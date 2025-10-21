package games.brainTreasure;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.File;
import java.net.URL;
import java.util.Stack;
import java.util.Random;
import java.util.ArrayList;
import java.util.Collections;
import javafx.embed.swing.JFXPanel;
import javafx.scene.media.Media;
import javafx.scene.media.MediaPlayer;

public class BrainTreasure extends JFrame {
    private static final long serialVersionUID = 1L;
    private JPanel mainPanel; // CardLayout container
    private CardLayout cardLayout;

    private Stack<Integer> numberStack;
    private Random random = new Random();
    private int score = 0;
    private int questionsAsked = 0;
    private final int TOTAL_QUESTIONS = 5;

    private JLabel scoreLabel;
    private JLabel questionLabel;
    private JTextField answerField;
    private ArrayList<Question> questionPool;
    private MediaPlayer mediaPlayer;

    public static void main(String[] args) {
        new JFXPanel(); // initialize JavaFX toolkit for MediaPlayer
        SwingUtilities.invokeLater(() -> {
            try {
                UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
            } catch (Exception e) {
                e.printStackTrace();
            }
            new BrainTreasure();
        });
    }

    private class Question {
        String text;
        int correctAnswer;

        Question(String text, int correctAnswer) {
            this.text = text;
            this.correctAnswer = correctAnswer;
        }
    }

    public BrainTreasure() {
        setTitle("Brain Treasure - Stack Memory Game");
        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        setSize(600, 480); // fixed size window
        setLocationRelativeTo(null); // center window on screen
        setLayout(new BorderLayout());
        setResizable(false);

        // Handle window closing to stop music and open dashboard
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

        // Setup card layout panel to hold screens
        cardLayout = new CardLayout();
        mainPanel = new JPanel(cardLayout);
        mainPanel.setOpaque(false); // transparent to show background

        // Create each screen panel
        JPanel stackScreen = createStackScreen();
        JPanel questionScreen = createQuestionScreen();
        JPanel resultScreen = createResultScreen();

        // Wrap screens inside a fixed size container panel centered
        JPanel fixedPanel = new JPanel(new GridBagLayout()); // centers content
        fixedPanel.setOpaque(false); // transparent
        Dimension fixedSize = new Dimension(500, 400);
        setExtendedState(JFrame.MAXIMIZED_BOTH);
        stackScreen.setPreferredSize(fixedSize);
        questionScreen.setPreferredSize(fixedSize);
        resultScreen.setPreferredSize(fixedSize);

        // Add screens to mainPanel
        mainPanel.add(stackScreen, "STACK");
        mainPanel.add(questionScreen, "QUESTION");
        mainPanel.add(resultScreen, "RESULT");

        // Add mainPanel to fixedPanel to center
        fixedPanel.add(mainPanel);

        // Create background panel with image, set layout
        BackgroundPanel bgPanel = new BackgroundPanel("/resources/background.jpg");
        bgPanel.setLayout(new BorderLayout());
        bgPanel.add(fixedPanel, BorderLayout.CENTER);

        setContentPane(bgPanel);

        // Start music
        playMusic("src/resources/background.mp3");

        setVisible(true);

        startNewGame();
    }

    private void startNewGame() {
        score = 0;
        questionsAsked = 0;
        generateNewStack();
        prepareQuestionPool();
        showStackScreen();
    }

    private void generateNewStack() {
        numberStack = new Stack<>();
        int size = 3 + random.nextInt(4); // 5-8 elements
        for (int i = 0; i < size; i++) {
            numberStack.push(10 + random.nextInt(90));
        }
    }

    private void prepareQuestionPool() {
        questionPool = new ArrayList<>();

        for (int i = 0; i < numberStack.size(); i++) {
            int value = numberStack.get(i);
            if (i > 0) {
                questionPool.add(new Question("What value was below " + value + "?", numberStack.get(i - 1)));
            }
            if (i < numberStack.size() - 1) {
                questionPool.add(new Question("What value was above " + value + "?", numberStack.get(i + 1)));
            }
            if (i > 0) {
                questionPool.add(new Question("What is the parent of " + value + "?", numberStack.get(i - 1)));
            }
            if (i < numberStack.size() - 1) {
                questionPool.add(new Question("What is the child of " + value + "?", numberStack.get(i + 1)));
            }
        }

        questionPool.add(new Question("How many elements were in the stack?", numberStack.size()));
        questionPool.add(new Question("What was the top value of the stack?", numberStack.peek()));
        questionPool.add(new Question("What was the bottom value of the stack?", numberStack.get(0)));

        for (int i = 0; i < 3; i++) {
            boolean present = random.nextBoolean();
            int questionValue;
            if (present) {
                questionValue = numberStack.get(random.nextInt(numberStack.size()));
            } else {
                do {
                    questionValue = 10 + random.nextInt(90);
                } while (numberStack.contains(questionValue));
            }
            questionPool.add(new Question("Was " + questionValue + " in the stack? (1=Yes, 0=No)", present ? 1 : 0));
        }

        Collections.shuffle(questionPool);
    }

    private JPanel createStackScreen() {
        JPanel panel = new JPanel(new BorderLayout());
        panel.setOpaque(false);

        JLabel title = new JLabel("MEMORIZE THIS STACK (5 seconds)", SwingConstants.CENTER);
        title.setFont(new Font("Arial", Font.BOLD, 20));
        title.setBorder(BorderFactory.createEmptyBorder(20, 0, 20, 0));
        title.setForeground(Color.WHITE); // better contrast on background

        JPanel stackPanel = new JPanel() {
            /**
			 * 
			 */
			private static final long serialVersionUID = 1L;

			@Override
            protected void paintComponent(Graphics g) {
                super.paintComponent(g);
                drawStack(g);
            }
        };
        stackPanel.setOpaque(false);
        stackPanel.setPreferredSize(new Dimension(300, 300));

        panel.add(title, BorderLayout.NORTH);
        panel.add(stackPanel, BorderLayout.CENTER);

        return panel;
    }

    private void drawStack(Graphics g) {
        Graphics2D g2d = (Graphics2D) g;
        g2d.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);

        int boxWidth = 120;
        int boxHeight = 30;
        int startX = 90;
        int startY = 20;

        for (int i = numberStack.size() - 1; i >= 0; i--) {
            int value = numberStack.get(i);
            float hue = 0.6f - (i * 0.6f / numberStack.size());
            Color boxColor = Color.getHSBColor(hue, 0.8f, 0.9f);

            g2d.setColor(boxColor);
            g2d.fillRect(startX, startY, boxWidth, boxHeight);
            g2d.setColor(Color.BLACK);
            g2d.drawRect(startX, startY, boxWidth, boxHeight);

            g2d.setColor(Color.BLACK);
            g2d.setFont(new Font("Arial", Font.BOLD, 14));
            String text = String.valueOf(value);
            int textWidth = g2d.getFontMetrics().stringWidth(text);
            g2d.drawString(text, startX + (boxWidth - textWidth) / 2, startY + 20);

            startY += boxHeight + 5;
        }
    }

    private void showStackScreen() {
        cardLayout.show(mainPanel, "STACK");
        Timer timer = new Timer(5000, _ -> showQuestionScreen());
        timer.setRepeats(false);
        timer.start();
    }

    private JPanel createQuestionScreen() {
        JPanel panel = new JPanel(new BorderLayout(10, 10));
        panel.setBorder(BorderFactory.createEmptyBorder(20, 20, 20, 20));
        panel.setOpaque(false);

        scoreLabel = new JLabel("Score: 0", SwingConstants.RIGHT);
        scoreLabel.setFont(new Font("Arial", Font.BOLD, 16));
        scoreLabel.setForeground(new Color(0, 200, 0)); // brighter green for visibility

        questionLabel = new JLabel("", SwingConstants.CENTER);
        questionLabel.setFont(new Font("Arial", Font.BOLD, 18));
        questionLabel.setForeground(Color.WHITE);

        answerField = new JTextField();
        answerField.setFont(new Font("Arial", Font.PLAIN, 16));
        answerField.addActionListener(_ -> checkAnswer());

        JButton submitButton = new JButton("Submit");
        submitButton.setFont(new Font("Arial", Font.BOLD, 14));
        submitButton.addActionListener(_ -> checkAnswer());

        JPanel centerPanel = new JPanel();
        centerPanel.setLayout(new BoxLayout(centerPanel, BoxLayout.Y_AXIS));
        centerPanel.setOpaque(false);
        centerPanel.add(questionLabel);
        centerPanel.add(Box.createRigidArea(new Dimension(0, 20)));
        centerPanel.add(answerField);
        centerPanel.add(Box.createRigidArea(new Dimension(0, 20)));
        centerPanel.add(submitButton);
        centerPanel.setAlignmentX(Component.CENTER_ALIGNMENT);

        panel.add(scoreLabel, BorderLayout.NORTH);
        panel.add(centerPanel, BorderLayout.CENTER);

        return panel;
    }

    private void showQuestionScreen() {
        cardLayout.show(mainPanel, "QUESTION");
        scoreLabel.setText("Score: " + score);
        askNextQuestion();
        answerField.requestFocusInWindow();
    }

    private void askNextQuestion() {
        if (questionsAsked < TOTAL_QUESTIONS && !questionPool.isEmpty()) {
            Question nextQuestion = questionPool.remove(0);
            questionLabel.setText(nextQuestion.text);
            questionLabel.putClientProperty("correctAnswer", nextQuestion.correctAnswer);
            answerField.setText("");
            questionsAsked++;
        } else {
            showResultScreen();
        }
    }

    private void checkAnswer() {
        try {
            String answerText = answerField.getText().trim();
            if (answerText.isEmpty()) return;

            int userAnswer = Integer.parseInt(answerText);
            int correctAnswer = (int) questionLabel.getClientProperty("correctAnswer");

            if (userAnswer == correctAnswer) {
                score += 10;
                JOptionPane.showMessageDialog(this, "Correct! +10 points", "Result", JOptionPane.INFORMATION_MESSAGE);
            } else {
                score = Math.max(0, score - 5);
                JOptionPane.showMessageDialog(this,
                        "Incorrect! The answer was " + correctAnswer + ". -5 points",
                        "Result", JOptionPane.WARNING_MESSAGE);
            }

            askNextQuestion();
            scoreLabel.setText("Score: " + score);
        } catch (NumberFormatException ex) {
            JOptionPane.showMessageDialog(this, "Please enter a valid number", "Error", JOptionPane.ERROR_MESSAGE);
        }
    }

    private JPanel createResultScreen() {
        JPanel panel = new JPanel(new BorderLayout());
        panel.setOpaque(false);

        JLabel resultLabel = new JLabel("", SwingConstants.CENTER);
        resultLabel.setFont(new Font("Arial", Font.BOLD, 22));
        resultLabel.setForeground(Color.YELLOW);

        JButton retryButton = new JButton("Play Again");
        retryButton.setFont(new Font("Arial", Font.BOLD, 16));
        retryButton.addActionListener(_ -> {
            startNewGame();
        });


        JPanel buttonPanel = new JPanel();
        buttonPanel.setOpaque(false);
        buttonPanel.add(retryButton);

        panel.add(resultLabel, BorderLayout.CENTER);
        panel.add(buttonPanel, BorderLayout.SOUTH);

        // Store reference for updating
        panel.putClientProperty("resultLabel", resultLabel);

        return panel;
    }

    private void showResultScreen() {
        JPanel resultPanel = (JPanel) mainPanel.getComponent(2); // RESULT panel
        JLabel resultLabel = (JLabel) resultPanel.getClientProperty("resultLabel");
        resultLabel.setText("Your final score: " + score);
        cardLayout.show(mainPanel, "RESULT");
    }

    private void playMusic(String musicFilePath) {
        try {
            File file = new File(musicFilePath);
            if (!file.exists()) {
                System.err.println("Music file not found: " + musicFilePath);
                return;
            }
            Media media = new Media(file.toURI().toString());
            mediaPlayer = new MediaPlayer(media);
            mediaPlayer.setCycleCount(MediaPlayer.INDEFINITE);
            mediaPlayer.play();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    // Custom JPanel that draws background image scaled
    private static class BackgroundPanel extends JPanel {
        /**
		 * 
		 */
		private static final long serialVersionUID = 1L;
		private Image backgroundImage;

        public BackgroundPanel(String imagePath) {
            try {
                URL imgUrl = BrainTreasure.class.getResource(imagePath);
                if (imgUrl == null) {
                    System.err.println("Background image not found at " + imagePath);
                } else {
                    backgroundImage = new ImageIcon(imgUrl).getImage();
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
            setOpaque(true);
        }

        @Override
        protected void paintComponent(Graphics g) {
            super.paintComponent(g);
            if (backgroundImage != null) {
                Dimension size = getSize();
                g.drawImage(backgroundImage, 0, 0, size.width, size.height, this);
            }
        }
    }
}
