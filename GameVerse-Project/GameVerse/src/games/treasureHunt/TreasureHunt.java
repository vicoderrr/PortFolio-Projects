package games.treasureHunt;

import javax.swing.*;
import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.image.BufferedImage;
import javax.imageio.ImageIO;

import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.util.Random;
import javafx.embed.swing.JFXPanel;
import javafx.scene.media.Media;
import javafx.scene.media.MediaPlayer;

public class TreasureHunt extends JFrame {
    /**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private static final int HOUSE_COUNT = 5;
    private static final int ROOMS_PER_HOUSE = 10;
    private static final int MAX_ATTEMPTS = 3;

    private JPanel mainPanel;
    private JPanel housesPanel;
    private JPanel roomsPanel;
    private CardLayout cardLayout;
    private ImageIcon[] houseIcons;
    private String[] houseNames = {
            "Emerald Mansion", "Sapphire Villa", "Ruby Palace",
            "Golden Manor", "Diamond Keep"
    };

    private int treasureHouseIndex;
    private int treasureRoomIndex;
    private String currentClue;
    private JLabel clueLabel;
    private int attemptsLeft;
    private JLabel attemptsLabel;

    private Image backgroundImage;
    private MediaPlayer mediaPlayer;


    public TreasureHunt() {
    	new JFXPanel();
        setTitle("Fantasy Treasure Hunt");
        setSize(1000, 800);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setExtendedState(JFrame.MAXIMIZED_BOTH);
        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                if (mediaPlayer != null) {
                    mediaPlayer.stop();
                }
                dispose();
                SwingUtilities.invokeLater(() -> new core.GameDashboard(""));
            }
        });

        loadBackgroundImage();
        initializeGame();
        loadHouseImages();

        BackgroundPanel bgPanel = new BackgroundPanel();
        bgPanel.setLayout(new BorderLayout());
        setContentPane(bgPanel);

        playMusic("src/resources/background.mp3"); 
        
        cardLayout = new CardLayout();
        mainPanel = new JPanel(cardLayout);
        mainPanel.setOpaque(false);

        JPanel centerPanel = new JPanel(new GridBagLayout());
        centerPanel.setOpaque(false);
        centerPanel.add(mainPanel);
        bgPanel.add(centerPanel, BorderLayout.CENTER);

        createHousesPanel();

        roomsPanel = new JPanel(new BorderLayout());
        roomsPanel.setOpaque(false);

        attemptsLabel = new JLabel("Attempts left: " + attemptsLeft, SwingConstants.CENTER);
        attemptsLabel.setFont(new Font("Serif", Font.BOLD, 16));
        attemptsLabel.setForeground(Color.WHITE);

        clueLabel = new JLabel(currentClue, SwingConstants.CENTER);
        clueLabel.setFont(new Font("Serif", Font.BOLD, 18));
        clueLabel.setBorder(BorderFactory.createEmptyBorder(10, 10, 20, 10));
        clueLabel.setForeground(Color.WHITE);

        JPanel statusPanel = new JPanel(new GridLayout(2, 1));
        statusPanel.setOpaque(false);
        statusPanel.add(attemptsLabel);
        statusPanel.add(clueLabel);

        mainPanel.add(housesPanel, "HOUSES");
        mainPanel.add(roomsPanel, "ROOMS");

        add(statusPanel, BorderLayout.SOUTH);

        cardLayout.show(mainPanel, "HOUSES");

    }

    private void loadBackgroundImage() {
        try (InputStream is = getClass().getResourceAsStream("/resources/background.jpg")) {
            backgroundImage = ImageIO.read(is);
        } catch (IOException e) {
            System.err.println("Could not load background image: " + e.getMessage());
        }
    }


    private void initializeGame() {
        Random random = new Random();
        treasureHouseIndex = random.nextInt(HOUSE_COUNT);
        treasureRoomIndex = random.nextInt(ROOMS_PER_HOUSE);
        attemptsLeft = MAX_ATTEMPTS;
        currentClue = "The treasure is hidden in one of these magnificent houses!";
    }

    private void loadHouseImages() {
        houseIcons = new ImageIcon[HOUSE_COUNT];
        for (int i = 0; i < HOUSE_COUNT; i++) {
            try (InputStream is = getClass().getResourceAsStream("/games/treasureHunt/resources/image" + (i + 1) + ".jpg")) {
                Image image = ImageIO.read(is);
                Image scaled = image.getScaledInstance(300, 200, Image.SCALE_SMOOTH);
                houseIcons[i] = new ImageIcon(scaled);
            } catch (IOException e) {
                houseIcons[i] = createColorIcon(new Color(100 + i * 30, 150 + i * 20, 200 - i * 20), houseNames[i]);
                System.err.println("Couldn't load image for " + houseNames[i] + ": " + e.getMessage());
            }
        }
    }

    private ImageIcon createColorIcon(Color color, String text) {
        BufferedImage img = new BufferedImage(300, 200, BufferedImage.TYPE_INT_RGB);
        Graphics2D g = img.createGraphics();
        g.setColor(color);
        g.fillRect(0, 0, 300, 200);
        g.setColor(Color.BLACK);
        g.drawRect(0, 0, 299, 199);
        g.setColor(Color.WHITE);
        g.setFont(new Font("Arial", Font.BOLD, 16));
        FontMetrics fm = g.getFontMetrics();
        int x = (300 - fm.stringWidth(text)) / 2;
        g.drawString(text, x, 100);
        g.dispose();
        return new ImageIcon(img);
    }

    private void createHousesPanel() {
        housesPanel = new JPanel(new GridBagLayout());
        housesPanel.setOpaque(false);

        GridBagConstraints gbc = new GridBagConstraints();
        gbc.insets = new Insets(20, 20, 20, 20);
        gbc.fill = GridBagConstraints.HORIZONTAL;

        for (int i = 0; i < HOUSE_COUNT; i++) {
            gbc.gridx = i % 3;
            gbc.gridy = i / 3;

            JButton btn = new JButton(houseNames[i], houseIcons[i]);
            btn.setVerticalTextPosition(SwingConstants.BOTTOM);
            btn.setHorizontalTextPosition(SwingConstants.CENTER);
            btn.setFont(new Font("Arial", Font.BOLD, 16));
            btn.setOpaque(false);
            btn.setContentAreaFilled(false);
            btn.setBorder(BorderFactory.createRaisedBevelBorder());

            final int index = i;
            btn.addActionListener(_ -> showRoomsForHouse(index));

            housesPanel.add(btn, gbc);
        }
    }

    private void showRoomsForHouse(int houseIndex) {
        roomsPanel.removeAll();
        roomsPanel.setOpaque(false);

        JPanel header = new JPanel();
        header.setOpaque(false);
        JLabel label = new JLabel(houseNames[houseIndex], SwingConstants.CENTER);
        label.setFont(new Font("Serif", Font.BOLD, 24));
        label.setForeground(Color.WHITE);
        header.add(label);

        JButton back = new JButton("Back to Houses");
        back.addActionListener(_ -> {
            cardLayout.show(mainPanel, "HOUSES");
            clueLabel.setText("The treasure is hidden in one of these magnificent houses!");
        });

        JPanel grid = new JPanel(new GridLayout(2, 5, 20, 20));
        grid.setOpaque(false);
        grid.setBorder(BorderFactory.createEmptyBorder(20, 20, 20, 20));

        for (int i = 0; i < ROOMS_PER_HOUSE; i++) {
            JButton roomBtn = new JButton("Room " + (i + 1));
            roomBtn.setFont(new Font("Arial", Font.BOLD, 14));
            roomBtn.setOpaque(false);
            roomBtn.setContentAreaFilled(false);
            roomBtn.setBorder(BorderFactory.createRaisedBevelBorder());

            final int roomIndex = i;
            roomBtn.addActionListener(_ -> checkRoomForTreasure(houseIndex, roomIndex));

            grid.add(roomBtn);
        }

        if (houseIndex == treasureHouseIndex) {
            currentClue = "You're in the right house! The treasure is behind one of these doors!";
        } else {
            currentClue = "The treasure isn't in this house. Try another!";
        }

        clueLabel.setText(currentClue);
        attemptsLabel.setText("Attempts left: " + attemptsLeft);

        roomsPanel.add(header, BorderLayout.NORTH);
        roomsPanel.add(grid, BorderLayout.CENTER);
        roomsPanel.add(back, BorderLayout.SOUTH);

        cardLayout.show(mainPanel, "ROOMS");
        roomsPanel.revalidate();
        roomsPanel.repaint();
    }

    private void checkRoomForTreasure(int houseIndex, int roomIndex) {
        if (houseIndex == treasureHouseIndex) {
            if (roomIndex == treasureRoomIndex) {
                JOptionPane.showMessageDialog(this,
                        "CONGRATULATIONS! You found the treasure in " +
                                houseNames[houseIndex] + ", Room " + (roomIndex + 1),
                        "Treasure Found!",
                        JOptionPane.INFORMATION_MESSAGE);
                showTreasure();
            } else {
                attemptsLeft--;
                attemptsLabel.setText("Attempts left: " + attemptsLeft);
                if (attemptsLeft > 0) {
                    JOptionPane.showMessageDialog(this,
                            "No treasure here! Attempts left: " + attemptsLeft,
                            "Keep Searching", JOptionPane.WARNING_MESSAGE);
                } else {
                    JOptionPane.showMessageDialog(this,
                            "No more attempts left! The treasure was in Room " + (treasureRoomIndex + 1),
                            "Game Over", JOptionPane.ERROR_MESSAGE);
                    showTreasure();
                }
            }
        } else {
            JOptionPane.showMessageDialog(this,
                    "This house doesn't contain the treasure!",
                    "Wrong House", JOptionPane.WARNING_MESSAGE);
        }
    }

    private void showTreasure() {
        roomsPanel.removeAll();
        roomsPanel.setOpaque(false);

        JPanel panel = new JPanel(new BorderLayout());
        panel.setOpaque(false);

        ImageIcon icon = createDiamondIcon();
        JLabel label = new JLabel(icon, SwingConstants.CENTER);
        label.setBorder(BorderFactory.createEmptyBorder(20, 20, 20, 20));

        String message = (attemptsLeft > 0) ?
                "YOU FOUND THE LEGENDARY DIAMOND!" :
                "GAME OVER! The treasure was here all along!";
        JLabel msgLabel = new JLabel(message, SwingConstants.CENTER);
        msgLabel.setFont(new Font("Serif", Font.BOLD, 28));
        msgLabel.setForeground(Color.YELLOW);

        JButton restart = new JButton("Play Again");
        restart.addActionListener(_ -> {
            initializeGame();
            cardLayout.show(mainPanel, "HOUSES");
            clueLabel.setText("The treasure is hidden in one of these magnificent houses!");
            attemptsLabel.setText("Attempts left: " + attemptsLeft);
        });

        panel.add(msgLabel, BorderLayout.NORTH);
        panel.add(label, BorderLayout.CENTER);
        panel.add(restart, BorderLayout.SOUTH);

        roomsPanel.add(panel);
        roomsPanel.revalidate();
        roomsPanel.repaint();
    }

    private ImageIcon createDiamondIcon() {
        BufferedImage image = new BufferedImage(300, 300, BufferedImage.TYPE_INT_ARGB);
        Graphics2D g2d = image.createGraphics();
        g2d.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);

        int[] xPoints = {150, 250, 150, 50};
        int[] yPoints = {50, 150, 250, 150};

        GradientPaint gradient = new GradientPaint(150, 50, new Color(100, 200, 255),
                150, 250, new Color(0, 100, 200));
        g2d.setPaint(gradient);
        g2d.fillPolygon(xPoints, yPoints, 4);

        g2d.setColor(new Color(255, 255, 255, 150));
        g2d.fillOval(100, 75, 60, 30);

        g2d.dispose();
        return new ImageIcon(image);
    }

    private class BackgroundPanel extends JPanel {
        /**
		 * 
		 */
		private static final long serialVersionUID = 1L;

		@Override
        protected void paintComponent(Graphics g) {
            super.paintComponent(g);
            if (backgroundImage != null) {
                g.drawImage(backgroundImage, 0, 0, getWidth(), getHeight(), this);
            } else {
                g.setColor(new Color(30, 30, 60));
                g.fillRect(0, 0, getWidth(), getHeight());
            }
        }
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

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            TreasureHunt game = new TreasureHunt();
            game.setVisible(true);
        });
    }
}
