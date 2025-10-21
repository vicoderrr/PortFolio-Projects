package games.snapMatch;

import javax.swing.*;
import javafx.embed.swing.JFXPanel;
import javafx.scene.media.Media;
import javafx.scene.media.MediaPlayer;

import java.awt.*;
import java.awt.event.*;
import java.awt.image.BufferedImage;
import java.io.File;
import java.util.Random;
import java.util.concurrent.*;
import javax.imageio.ImageIO;

public class SnapMatch {
    private JFrame frame;
    private JLabel userImageLabel, computerImageLabel, statusLabel, scoreLabel;
    private JButton flipButton;

    private ImageIcon[] cardImages;
    private ImageIcon backImage;
    private BufferedImage backgroundImage;

    private int userScore = 0, computerScore = 0, roundCount = 0;
    private int currentUserImageIndex = -1, currentComputerImageIndex = -1;
    private boolean matchFound = false;

    private ScheduledExecutorService scheduler;
    private Random random = new Random();
    private Timer flipTimer;
    private int flipAngle = 0;
    private boolean flippingUserCard = false, flippingComputerCard = false;

    private BackgroundPanel mainPanel;
    private MediaPlayer mediaPlayer;

    public SnapMatch() {
        new JFXPanel(); // Initializes JavaFX runtime
        loadImages();
        createGUI();
        scheduler = Executors.newScheduledThreadPool(1);
        startNewRound();
    }

    private void loadImages() {
        try {
            BufferedImage originalBg = ImageIO.read(getClass().getResourceAsStream("/games/snapMatch/resources/background.jpg"));
            backgroundImage = new BufferedImage(600, 500, BufferedImage.TYPE_INT_RGB);
            Graphics2D g2d = backgroundImage.createGraphics();
            g2d.setRenderingHint(RenderingHints.KEY_INTERPOLATION, RenderingHints.VALUE_INTERPOLATION_BILINEAR);
            g2d.drawImage(originalBg, 0, 0, 600, 500, null);
            g2d.dispose();

            for (int y = 0; y < backgroundImage.getHeight(); y++) {
                for (int x = 0; x < backgroundImage.getWidth(); x++) {
                    Color c = new Color(backgroundImage.getRGB(x, y));
                    backgroundImage.setRGB(x, y, c.darker().darker().getRGB());
                }
            }
        } catch (Exception e) {
            backgroundImage = new BufferedImage(600, 500, BufferedImage.TYPE_INT_RGB);
            Graphics2D g2d = backgroundImage.createGraphics();
            GradientPaint gradient = new GradientPaint(0, 0, new Color(30, 60, 90), 600, 500, new Color(10, 20, 40));
            g2d.setPaint(gradient);
            g2d.fillRect(0, 0, 600, 500);
            g2d.dispose();
        }

        String[] imagePaths = {
            "image1.jpg", "image2.jpg", "image3.jpg", "image4.jpg", "image5.jpg",
            "image6.jpg", "image7.jpg", "image8.jpg", "image9.jpg", "image10.jpg",
            "image11.jpg", "image12.jpg", "image13.jpg", "image14.jpg"
        };

        cardImages = new ImageIcon[imagePaths.length];
        for (int i = 0; i < imagePaths.length; i++) {
            try {
                BufferedImage cardImg = ImageIO.read(getClass().getResourceAsStream("/games/snapMatch/resources/" + imagePaths[i]));
                BufferedImage resized = new BufferedImage(200, 200, BufferedImage.TYPE_INT_ARGB);
                Graphics2D g2d = resized.createGraphics();
                g2d.setRenderingHint(RenderingHints.KEY_INTERPOLATION, RenderingHints.VALUE_INTERPOLATION_BILINEAR);
                g2d.drawImage(cardImg, 0, 0, 200, 200, null);
                g2d.dispose();
                cardImages[i] = new ImageIcon(resized);
            } catch (Exception e) {
                cardImages[i] = createPlaceholderImage(200, 200, "Card " + (i + 1));
            }
        }

        backImage = createBackImage(200, 200);
    }

    private ImageIcon createBackImage(int width, int height) {
        BufferedImage image = new BufferedImage(width, height, BufferedImage.TYPE_INT_ARGB);
        Graphics2D g2 = image.createGraphics();
        g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);

        GradientPaint gradient = new GradientPaint(0, 0, new Color(20, 50, 100), width, height, new Color(10, 30, 70));
        g2.setPaint(gradient);
        g2.fillRoundRect(0, 0, width, height, 20, 20);

        g2.setColor(new Color(255, 255, 255, 150));
        g2.setStroke(new BasicStroke(4));
        g2.drawRoundRect(5, 5, width - 10, height - 10, 15, 15);

        g2.setFont(new Font("Arial", Font.BOLD, 28));
        g2.setColor(Color.WHITE);
        FontMetrics fm = g2.getFontMetrics();
        int x = (width - fm.stringWidth("SNAP")) / 2;
        int y = (height - fm.getHeight()) / 2 + fm.getAscent();
        g2.drawString("SNAP", x, y);
        g2.dispose();

        return new ImageIcon(image);
    }

    private ImageIcon createPlaceholderImage(int width, int height, String text) {
        BufferedImage image = new BufferedImage(width, height, BufferedImage.TYPE_INT_ARGB);
        Graphics2D g2 = image.createGraphics();
        g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);

        g2.setColor(new Color(240, 240, 240));
        g2.fillRoundRect(0, 0, width, height, 20, 20);

        g2.setColor(Color.GRAY);
        g2.setStroke(new BasicStroke(3));
        g2.drawRoundRect(2, 2, width - 4, height - 4, 18, 18);

        g2.setFont(new Font("Arial", Font.BOLD, 18));
        g2.setColor(Color.BLACK);
        FontMetrics fm = g2.getFontMetrics();
        int x = (width - fm.stringWidth(text)) / 2;
        int y = (height - fm.getHeight()) / 2 + fm.getAscent();
        g2.drawString(text, x, y);

        g2.dispose();
        return new ImageIcon(image);
    }

    private void createGUI() {
        frame = new JFrame("Snap Match Game");
        frame.setExtendedState(JFrame.MAXIMIZED_BOTH);
        frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        frame.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                if (mediaPlayer != null) mediaPlayer.stop();
                frame.dispose();
                SwingUtilities.invokeLater(() -> {
                    try {
                        Class.forName("core.GameDashboard");
                        new core.GameDashboard(""); // Ensure this class exists
                    } catch (ClassNotFoundException ex) {
                        System.out.println("core.GameDashboard not found.");
                    }
                });
            }
        });

        mainPanel = new BackgroundPanel("/games/snapMatch/resources/background.jpg");
        mainPanel.setLayout(new BorderLayout());
        frame.setContentPane(mainPanel);
        playMusic("src/resources/background.mp3");

        JPanel contentPanel = new JPanel(new BorderLayout()) {
            /**
			 * 
			 */
			private static final long serialVersionUID = 1L;

			@Override
            protected void paintComponent(Graphics g) {
                Graphics2D g2d = (Graphics2D) g;
                g2d.setColor(new Color(255, 255, 255, 0));
                g2d.fillRect(0, 0, getWidth(), getHeight());
                super.paintComponent(g);
            }
        };
        contentPanel.setOpaque(false);

        JPanel gamePanel = new JPanel(new GridLayout(1, 2, 30, 30));
        gamePanel.setOpaque(false);
        gamePanel.setBorder(BorderFactory.createEmptyBorder(30, 30, 30, 30));

        userImageLabel = new JLabel(backImage, SwingConstants.CENTER);
        computerImageLabel = new JLabel(backImage, SwingConstants.CENTER);
        gamePanel.add(userImageLabel);
        gamePanel.add(computerImageLabel);

        flipButton = new JButton("Flip Your Card");
        flipButton.setFont(new Font("Arial", Font.BOLD, 18));
        flipButton.setBackground(new Color(80, 140, 200));
        flipButton.setForeground(Color.WHITE);
        flipButton.setFocusPainted(false);
        flipButton.setBorder(BorderFactory.createEmptyBorder(10, 20, 10, 20));
        flipButton.addActionListener(_ -> startUserFlip());

        JPanel buttonPanel = new JPanel();
        buttonPanel.setOpaque(false);
        buttonPanel.add(flipButton);

        statusLabel = new JLabel("Click 'Flip Your Card' to start!", SwingConstants.CENTER);
        statusLabel.setFont(new Font("Arial", Font.BOLD, 18));

        scoreLabel = new JLabel("You: 0  |  Computer: 0  |  Rounds: 0", SwingConstants.CENTER);
        scoreLabel.setFont(new Font("Arial", Font.BOLD, 16));

        JPanel statusPanel = new JPanel(new GridLayout(2, 1));
        statusPanel.setOpaque(false);
        statusPanel.setBorder(BorderFactory.createEmptyBorder(10, 0, 20, 0));
        statusPanel.add(statusLabel);
        statusPanel.add(scoreLabel);

        contentPanel.add(gamePanel, BorderLayout.CENTER);
        contentPanel.add(buttonPanel, BorderLayout.NORTH);
        contentPanel.add(statusPanel, BorderLayout.SOUTH);
        mainPanel.add(contentPanel, BorderLayout.CENTER);

        flipTimer = new Timer(15, _ -> {
            flipAngle += 8;
            if (flipAngle >= 180) {
                flipAngle = 0;
                flipTimer.stop();
                if (flippingUserCard) {
                    userImageLabel.setIcon(cardImages[currentUserImageIndex]);
                    flippingUserCard = false;
                    checkMatchAfterUserFlip();
                } else if (flippingComputerCard) {
                    computerImageLabel.setIcon(cardImages[currentComputerImageIndex]);
                    flippingComputerCard = false;
                    checkMatchAfterComputerFlip();
                }
            } else {
                ImageIcon flipIcon = createFlippingImage(flipAngle, flippingUserCard);
                if (flippingUserCard) userImageLabel.setIcon(flipIcon);
                else computerImageLabel.setIcon(flipIcon);
            }
        });

        frame.setVisible(true);
    }

    private ImageIcon createFlippingImage(int angle, boolean isUserCard) {
        int width = 200, height = 200;
        BufferedImage image = new BufferedImage(width, height, BufferedImage.TYPE_INT_ARGB);
        Graphics2D g2 = image.createGraphics();
        g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
        g2.setRenderingHint(RenderingHints.KEY_INTERPOLATION, RenderingHints.VALUE_INTERPOLATION_BILINEAR);

        double scale = Math.abs(Math.cos(Math.toRadians(angle)));
        scale = Math.max(scale, 0.1);
        double perspective = Math.sin(Math.toRadians(angle)) * 0.3;

        int x = width / 2, y = height / 2;
        int w = (int)(width * scale);
        int h = (int)(height * (1 - perspective));

        if (angle < 90) g2.drawImage(backImage.getImage(), x - w / 2, y - h / 2, w, h, null);
        else {
            ImageIcon icon = isUserCard ? cardImages[currentUserImageIndex] : cardImages[currentComputerImageIndex];
            g2.drawImage(icon.getImage(), x - w / 2, y - h / 2, w, h, null);
        }
        g2.dispose();
        return new ImageIcon(image);
    }

    private void startNewRound() {
        roundCount++;
        setMatchFound(false);
        currentUserImageIndex = currentComputerImageIndex = -1;
        userImageLabel.setIcon(backImage);
        computerImageLabel.setIcon(backImage);
        flipButton.setEnabled(true);
        statusLabel.setText("Round " + roundCount + ": Your turn - Click 'Flip Your Card'!");
        updateScore();
    }

    private void startUserFlip() {
        flipButton.setEnabled(false);
        currentUserImageIndex = random.nextInt(cardImages.length);
        flippingUserCard = true;
        flipAngle = 0;
        flipTimer.start();
        statusLabel.setText("Round " + roundCount + ": Your card is flipping...");
    }

    private void startComputerFlip() {
        currentComputerImageIndex = random.nextInt(cardImages.length);
        flippingComputerCard = true;
        flipAngle = 0;
        flipTimer.start();
        statusLabel.setText("Round " + roundCount + ": Computer's card is flipping...");
    }

    private void checkMatchAfterUserFlip() {
        if (currentComputerImageIndex != -1 && currentUserImageIndex == currentComputerImageIndex) {
            userScore++;
            setMatchFound(true);
            statusLabel.setText("Round " + roundCount + ": You matched! You win!");
            updateScore();
            scheduler.schedule(this::startNewRound, 2, TimeUnit.SECONDS);
        } else {
            startComputerFlip();
        }
    }

    private void checkMatchAfterComputerFlip() {
        if (currentUserImageIndex != -1 && currentComputerImageIndex == currentUserImageIndex) {
            computerScore++;
            setMatchFound(true);
            statusLabel.setText("Round " + roundCount + ": Computer matched! Computer wins!");
            updateScore();
            scheduler.schedule(this::startNewRound, 2, TimeUnit.SECONDS);
        } else {
            flipButton.setEnabled(true);
            statusLabel.setText("Round " + roundCount + ": No match. Your turn!");
        }
    }

    private void updateScore() {
        scoreLabel.setText(String.format("You: %d  |  Computer: %d  |  Rounds: %d", userScore, computerScore, roundCount));
    }

    private void playMusic(String filePath) {
        try {
            Media sound = new Media(new File(filePath).toURI().toString());
            mediaPlayer = new MediaPlayer(sound);
            mediaPlayer.setCycleCount(MediaPlayer.INDEFINITE);
            mediaPlayer.play();
        } catch (Exception e) {
            JOptionPane.showMessageDialog(null, "Error: Unable to play music.");
            e.printStackTrace();
        }
    }

    class BackgroundPanel extends JPanel {
        /**
		 * 
		 */
		private static final long serialVersionUID = 1L;
		private Image bgImage;

        public BackgroundPanel(String path) {
            try {
                bgImage = new ImageIcon(getClass().getResource(path)).getImage();
            } catch (Exception e) {
                bgImage = null;
            }
        }

        @Override
        protected void paintComponent(Graphics g) {
            super.paintComponent(g);
            if (bgImage != null) g.drawImage(bgImage, 0, 0, getWidth(), getHeight(), this);
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(SnapMatch::new);
    }

	public boolean isMatchFound() {
		return matchFound;
	}

	public void setMatchFound(boolean matchFound) {
		this.matchFound = matchFound;
	}
}
