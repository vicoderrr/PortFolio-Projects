/**
 * ------------------------------------------------------------
 * Project     : GameVerse
 * Game Title  : Snake
 * Package     : games.snake
 * Class       : Snake.java
 *
 * Description : A classic arcade-style game where the player controls 
 *               a snake that moves around the screen to collect food. 
 *               Each time the snake eats food, it grows in size. 
 *               The goal is to survive as long as possible without 
 *               hitting the walls or colliding with itself.
 *
 *               Designed to enhance reaction time, coordination, and 
 *               strategic movement.
 *                              
 * Developed by: Rajan Kumar
 * Email       : 73521689rajan@gmail.com
 * College     : Graphic Era University (Deemed)
 * Date        : 05-12-2025
 * Version     : 1.0 
 * ------------------------------------------------------------
 */

package games.snake;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.Random;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.*;
import javafx.embed.swing.JFXPanel;
import javafx.scene.media.Media;
import javafx.scene.media.MediaPlayer;

public class Snake extends JFrame {
	private static final long serialVersionUID = 1L;

	private MediaPlayer mediaPlayer;
	private BackgroundPanel bgpanel;

	public Snake() {
		setTitle("Snake");
		setExtendedState(JFrame.MAXIMIZED_BOTH);
		setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		setResizable(false);
		pack();
		setVisible(true);
		setLocationRelativeTo(null);
		
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

		bgpanel = new BackgroundPanel("src/resources/background.jpg");
		bgpanel.setLayout(new BorderLayout());

		// Optional: Add header
		JPanel header = new JPanel();
		header.setOpaque(false); // So the background image is visible
		
		JLabel snakeLabel = new JLabel("Snake", SwingConstants.CENTER);
		Font f = new Font("Times New Roman", Font.BOLD, 60);
		snakeLabel.setFont(f);
		snakeLabel.setForeground(Color.WHITE);
		header.setLayout(new BorderLayout()); // Ensure layout supports centering
		header.add(snakeLabel, BorderLayout.CENTER);
		bgpanel.add(header, BorderLayout.NORTH);


		// Main game panel wrapped in a container for centering and border
		GamePanel gamePanel = new GamePanel();
		gamePanel.setOpaque(true); // Needs background color to see border

		JPanel gamePanelContainer = new JPanel(new GridBagLayout());
		gamePanelContainer.setOpaque(false); // Let background show through

		// Add border around the game panel
		gamePanel.setBorder(BorderFactory.createCompoundBorder(
			    BorderFactory.createLineBorder(Color.WHITE, 4, true), // true for rounded
			    BorderFactory.createEmptyBorder(10, 10, 10, 10)        // padding inside border
			));

		gamePanelContainer.add(gamePanel); // Center the game panel

		bgpanel.add(gamePanelContainer, BorderLayout.CENTER);


		// Optional: Add footer
		JPanel footer = new JPanel();
		footer.setOpaque(false);
		footer.add(new JLabel("© 2025 GameVerse"));
		bgpanel.add(footer, BorderLayout.SOUTH);

		// Set the composed panel as content
		setContentPane(bgpanel);


		playMusic("src/resources/background.mp3");
		setVisible(true);
	}

	private void playMusic(String filePath) {
		try {
			Media sound = new Media(new File(filePath).toURI().toString());
			mediaPlayer = new MediaPlayer(sound);
			mediaPlayer.setCycleCount(MediaPlayer.INDEFINITE);
			mediaPlayer.play();
		} catch (Exception e) {
			JOptionPane.showMessageDialog(this, "Error: Unable to play music.");
			e.printStackTrace();
		}
	}

	class BackgroundPanel extends JPanel {
		private static final long serialVersionUID = 1L;
		private Image backgroundImage;

		public BackgroundPanel(String imagePath) {
			this.backgroundImage = new ImageIcon(imagePath).getImage();
		}

		@Override
		protected void paintComponent(Graphics g) {
			super.paintComponent(g);
			g.drawImage(backgroundImage, 0, 0, getWidth(), getHeight(), this); // Stretch to fill
		}
	}

	public static void main(String[] args) {
		// Initialize JavaFX runtime
		new JFXPanel(); // Needed to initialize JavaFX environment
		SwingUtilities.invokeLater(Snake::new);
	}
}

class GamePanel extends JPanel implements ActionListener {

	private static final long serialVersionUID = 1L;
	static final int SCREEN_WIDTH = 600;
	static final int SCREEN_HEIGHT = 600;
	static final int UNIT_SIZE = 25;
	static final int GAME_UNITS = (SCREEN_WIDTH * SCREEN_HEIGHT) / (UNIT_SIZE * UNIT_SIZE);
	static final int DELAY = 75;

	final int[] x = new int[GAME_UNITS];
	final int[] y = new int[GAME_UNITS];
	int bodyParts = 6;
	int applesEaten;
	int appleX;
	int appleY;
	char direction = 'R';
	boolean running = false;
	Timer timer;
	Random random;

	GamePanel() {
		random = new Random();
		this.setPreferredSize(new Dimension(SCREEN_WIDTH, SCREEN_HEIGHT));
		this.setBackground(Color.black);
		this.setFocusable(true);
		this.addKeyListener(new MyKeyAdapter());
		startGame();
	}

	public void startGame() {
		newApple();
		running = true;
		timer = new Timer(DELAY, this);
		timer.start();
	}

	public void paintComponent(Graphics g) {
		super.paintComponent(g);
		draw(g);
	}

	public void draw(Graphics g) {
		if (running) {
			// draw grid (optional)
//			for (int i = 0; i < SCREEN_HEIGHT / UNIT_SIZE; i++) {
//				g.drawLine(i * UNIT_SIZE, 0, i * UNIT_SIZE, SCREEN_HEIGHT);
//				g.drawLine(0, i * UNIT_SIZE, SCREEN_WIDTH, i * UNIT_SIZE);
//			}

			// draw apple
			g.setColor(Color.red);
			g.fillOval(appleX, appleY, UNIT_SIZE, UNIT_SIZE);

			// draw snake
			for (int i = 0; i < bodyParts; i++) {
				if (i == 0) {
					g.setColor(Color.green);
				} else {
					g.setColor(new Color(45, 180, 0));
				}
				g.fillRect(x[i], y[i], UNIT_SIZE, UNIT_SIZE);
			}

			// score
			g.setColor(Color.red);
			g.setFont(new Font("Ink Free", Font.BOLD, 30));
			FontMetrics metrics = getFontMetrics(g.getFont());
			g.drawString("Score: " + applesEaten,
					(SCREEN_WIDTH - metrics.stringWidth("Score: " + applesEaten)) / 2,
					g.getFont().getSize());
		} else {
			gameOver(g);
		}
	}

	public void newApple() {
		appleX = random.nextInt(SCREEN_WIDTH / UNIT_SIZE) * UNIT_SIZE;
		appleY = random.nextInt(SCREEN_HEIGHT / UNIT_SIZE) * UNIT_SIZE;
	}

	public void move() {
		for (int i = bodyParts; i > 0; i--) {
			x[i] = x[i - 1];
			y[i] = y[i - 1];
		}

		switch (direction) {
			case 'U' -> y[0] -= UNIT_SIZE;
			case 'D' -> y[0] += UNIT_SIZE;
			case 'L' -> x[0] -= UNIT_SIZE;
			case 'R' -> x[0] += UNIT_SIZE;
		}
	}

	public void checkApple() {
		if (x[0] == appleX && y[0] == appleY) {
			bodyParts++;
			applesEaten++;
			newApple();
		}
	}

	public void checkCollisions() {
		// head vs body
		for (int i = bodyParts; i > 0; i--) {
			if (x[0] == x[i] && y[0] == y[i]) {
				running = false;
				break;
			}
		}

		// head touches wall
		if (x[0] < 0 || x[0] >= SCREEN_WIDTH ||
				y[0] < 0 || y[0] >= SCREEN_HEIGHT) {
			running = false;
		}

		if (!running) {
			timer.stop();
		}
	}

	public void gameOver(Graphics g) {
		// score
		g.setColor(Color.red);
		g.setFont(new Font("Ink Free", Font.BOLD, 30));
		FontMetrics metrics1 = getFontMetrics(g.getFont());
		g.drawString("Score: " + applesEaten,
				(SCREEN_WIDTH - metrics1.stringWidth("Score: " + applesEaten)) / 2,
				g.getFont().getSize());

		// game over text
		g.setColor(Color.red);
		g.setFont(new Font("Ink Free", Font.BOLD, 75));
		FontMetrics metrics2 = getFontMetrics(g.getFont());
		g.drawString("Game Over",
				(SCREEN_WIDTH - metrics2.stringWidth("Game Over")) / 2,
				SCREEN_HEIGHT / 2);
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		if (running) {
			move();
			checkApple();
			checkCollisions();
		}
		repaint();
	}

	public class MyKeyAdapter extends KeyAdapter {
		@Override
		public void keyPressed(KeyEvent e) {
			switch (e.getKeyCode()) {
				case KeyEvent.VK_LEFT -> {
					if (direction != 'R')
						direction = 'L';
				}
				case KeyEvent.VK_RIGHT -> {
					if (direction != 'L')
						direction = 'R';
				}
				case KeyEvent.VK_UP -> {
					if (direction != 'D')
						direction = 'U';
				}
				case KeyEvent.VK_DOWN -> {
					if (direction != 'U')
						direction = 'D';
				}
			}
		}
	}
}
