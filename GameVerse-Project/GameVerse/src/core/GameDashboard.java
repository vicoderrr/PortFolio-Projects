package core;

import java.awt.*;
import java.net.URL;
import javax.swing.*;

public class GameDashboard extends JFrame {

    private static final long serialVersionUID = 1L;
    JPanel displayPanel;
    private BackgroundPanel bgPanel;

    public GameDashboard(String username) {
        setTitle("Welcome " + username);
        setUndecorated(true);
        setExtendedState(JFrame.MAXIMIZED_BOTH);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(EXIT_ON_CLOSE);

        URL bgURL = getClass().getResource("/resources/background.jpg");
        if (bgURL == null) {
            JOptionPane.showMessageDialog(this, "Background image not found!", "Error", JOptionPane.ERROR_MESSAGE);
            System.exit(1);
        }
        bgPanel = new BackgroundPanel(bgURL);
        bgPanel.setLayout(new BorderLayout());

        // Display panel
        displayPanel = new JPanel();
        displayPanel.setOpaque(false);
        displayPanel.setLayout(new BorderLayout());
        displayPanel.setBackground(new Color(240, 240, 255));

        JLabel welcome = new JLabel("GameVerse", SwingConstants.CENTER);
        welcome.setFont(new Font("Segoe UI", Font.BOLD, 72));
        welcome.setForeground(Color.WHITE);
        welcome.setBorder(BorderFactory.createEmptyBorder(30, 0, 10, 0));

        displayPanel.add(welcome, BorderLayout.NORTH);
        bgPanel.add(displayPanel, BorderLayout.CENTER);
        setContentPane(bgPanel);

        // Show all games directly
        showAllGames();
        setVisible(true);
    }

    void showAllGames() {
        JPanel gameBoxPanel = new JPanel(new GridLayout(0, 3, 150, 100));
        gameBoxPanel.setOpaque(false);
        gameBoxPanel.setBackground(new Color(240, 240, 255));
        gameBoxPanel.setBorder(BorderFactory.createEmptyBorder(100, 150, 100, 150));

        String[] allGames = {
            "Business", "RockPaperScissors", "TicTacToe",
            "Snake", "WordJumble", "TreasureHunt",
            "SnapMatch", "ColorCoding", "NumberGuessing",
            "BrainTreasure"
        };

        for (String game : allGames) {
            URL imgURL = getClass().getResource("/resources/" + game + ".png");
            if (imgURL == null) {
                System.err.println("Missing image: /resources/" + game + ".png");
                continue;
            }

            ImageIcon rawIcon = new ImageIcon(imgURL);
            Image scaledImage = rawIcon.getImage().getScaledInstance(300, 400, Image.SCALE_SMOOTH);
            ImageIcon gameIcon = new ImageIcon(scaledImage);

            JButton gameButton = new JButton(gameIcon);
            gameButton.setPreferredSize(new Dimension(300, 400));
            gameButton.setBorderPainted(true);
            gameButton.setContentAreaFilled(false);
            gameButton.setFocusPainted(false);
            gameButton.setMargin(new Insets(0, 0, 0, 0));
            gameButton.setOpaque(false);

            gameButton.addActionListener(_ -> {
                dispose();
                switch (game) {
                    case "Business" -> new games.business.Business();
                    case "TicTacToe" -> new games.ticTacToe.TicTacToe();
                    case "Snake" -> new games.snake.Snake();
                    case "RockPaperScissors" -> new games.rockPaperScissors.RockPaperScissors();
                    case "TreasureHunt" -> {
//                        dispose();
                        games.treasureHunt.TreasureHunt.main(new String[]{});
                    }

//                    case "TreasureHunt" -> new games.treasureHunt.TreasureHunt();
                    case "SnapMatch" -> new games.snapMatch.SnapMatch();
                    case "BrainTreasure" -> new games.brainTreasure.BrainTreasure();
                    case "NumberGuessing" -> new games.numberGuessing.NumberGuessing();
                    case "ColorCoding" -> new games.colorCoding.ColorCoding();
                    case "WordJumble" -> new games.wordJumble.WordJumble();
                    default -> JOptionPane.showMessageDialog(null, "Game not available: " + game);
                }
            });

            JPanel card = new JPanel(new BorderLayout());
            card.setOpaque(false);
            card.add(gameButton, BorderLayout.CENTER);
            gameBoxPanel.add(card);
        }

        JScrollPane scrollPane = new JScrollPane(gameBoxPanel);
        scrollPane.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
        scrollPane.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_NEVER);
        scrollPane.getVerticalScrollBar().setUnitIncrement(20);
        scrollPane.setOpaque(false);
        scrollPane.getViewport().setOpaque(false);
        scrollPane.setBorder(null);

        displayPanel.add(scrollPane, BorderLayout.CENTER);
        displayPanel.revalidate();
        displayPanel.repaint();
    }

    class BackgroundPanel extends JPanel {
        private static final long serialVersionUID = 1L;
        private Image backgroundImage;

        public BackgroundPanel(URL url) {
            this.backgroundImage = new ImageIcon(url).getImage();
        }

        @Override
        protected void paintComponent(Graphics g) {
            super.paintComponent(g);
            g.drawImage(backgroundImage, 0, 0, getWidth(), getHeight(), this);
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new GameDashboard("vicoderrr"));
    }
}
