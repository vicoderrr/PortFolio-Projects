package core;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.net.URL;

public class GameLogin extends JFrame {
    private static final long serialVersionUID = 1L;
	private JTextField usernameField;
    private JPasswordField passwordField;
    private BackgroundPanel bgPanel;
    private List<Particle> particles;

    public GameLogin() {
        setTitle("GameVerse - Premium Login");
        setUndecorated(true);
        setExtendedState(JFrame.MAXIMIZED_BOTH);
        setDefaultCloseOperation(EXIT_ON_CLOSE);

        // Initialize particles
        setParticles(new ArrayList<>());

 
        URL bgURL = getClass().getResource("/resources/background.jpg");
        if (bgURL == null) {
            JOptionPane.showMessageDialog(this, "Background image not found!", "Error", JOptionPane.ERROR_MESSAGE);
            System.exit(1);
        }
        bgPanel = new BackgroundPanel(bgURL);
        // Glass-like card panel
        JPanel card = new JPanel(new GridBagLayout()) {
			private static final long serialVersionUID = 1L;

			@Override
            protected void paintComponent(Graphics g) {
                super.paintComponent(g);
                Graphics2D g2 = (Graphics2D) g;
                g2.setColor(new Color(255, 255, 255, 30));
                g2.fillRoundRect(0, 0, getWidth(), getHeight(), 25, 25);
            }
        };
        card.setPreferredSize(new Dimension(420, 500));
        card.setOpaque(false);
        card.setBorder(BorderFactory.createEmptyBorder(40, 40, 40, 40));
        card.setLayout(new GridBagLayout());

        GridBagConstraints gbc = new GridBagConstraints();
        gbc.insets = new Insets(15, 0, 10, 0);
        gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.gridx = 0;

        JLabel logo = new JLabel("🎮", SwingConstants.CENTER);
        logo.setFont(new Font("Segoe UI Emoji", Font.PLAIN, 36));
        gbc.gridy = 0;
        card.add(logo, gbc);

        JLabel title = new JLabel("Welcome to GameVerse", SwingConstants.CENTER);
        title.setFont(new Font("Segoe UI", Font.BOLD, 24));
        title.setForeground(Color.WHITE);
        gbc.gridy++;
        card.add(title, gbc);

        usernameField = createInputField("Username");
        gbc.gridy++;
        card.add(usernameField, gbc);

        passwordField = new JPasswordField();
        passwordField.setFont(new Font("Segoe UI", Font.PLAIN, 16));
        passwordField.setBorder(BorderFactory.createTitledBorder("Password"));
        gbc.gridy++;
        card.add(passwordField, gbc);

        JButton login = createButton("Login");
        JButton signup = createButton("Signup");
        JButton forgot = createLinkButton("Forgot Password?");

        gbc.gridy++;
        card.add(login, gbc);
        gbc.gridy++;
        card.add(signup, gbc);
        gbc.gridy++;
        card.add(forgot, gbc);

        // Event Listeners
        login.addActionListener(_ -> loginAction());
        signup.addActionListener(_ -> {
            dispose();
            new SignUpPage();
        });
        
        bgPanel.setLayout(new GridBagLayout());
        GridBagConstraints gbcPanel = new GridBagConstraints();
        gbcPanel.gridx = 0;
        gbcPanel.gridy = 0;
        gbcPanel.anchor = GridBagConstraints.CENTER;
        bgPanel.add(card, gbcPanel);

        setContentPane(bgPanel);
        setVisible(true);
    }

    private JTextField createInputField(String title) {
        JTextField field = new JTextField();
        field.setFont(new Font("Segoe UI", Font.PLAIN, 16));
        field.setBorder(BorderFactory.createTitledBorder(title));
        return field;
    }

    private JButton createButton(String text) {
        JButton button = new JButton(text);
        button.setBackground(new Color(70, 130, 180));
        button.setForeground(Color.WHITE);
        button.setFont(new Font("Segoe UI", Font.BOLD, 16));
        button.setFocusPainted(false);
        button.setCursor(Cursor.getPredefinedCursor(Cursor.HAND_CURSOR));
        button.setBorder(BorderFactory.createEmptyBorder(10, 25, 10, 25));
        button.addMouseListener(new MouseAdapter() {
            public void mouseEntered(MouseEvent e) {
                button.setBackground(new Color(90, 150, 200));
            }

            public void mouseExited(MouseEvent e) {
                button.setBackground(new Color(70, 130, 180));
            }
        });
        return button;
    }

    private JButton createLinkButton(String text) {
        JButton link = new JButton(text);
        link.setContentAreaFilled(false);
        link.setBorderPainted(false);
        link.setFocusPainted(false);
        link.setForeground(Color.LIGHT_GRAY);
        link.setFont(new Font("Segoe UI", Font.PLAIN, 12));
        link.setCursor(Cursor.getPredefinedCursor(Cursor.HAND_CURSOR));
        return link;
    }

    private void loginAction() {
        String user = usernameField.getText().trim();
        String pass = new String(passwordField.getPassword()).trim();
        if (UserUtil.validateUser(user, pass)) {
            dispose();
            new GameDashboard(user);
        } else {
            JOptionPane.showMessageDialog(this, "Invalid credentials!", "Login Failed", JOptionPane.ERROR_MESSAGE);
        }
    }

    // Particle class to represent individual particles
    class Particle {
        private int x, y;
        private int size = 10;
        private Color color;
        private float alpha = 1.0f;
        private float speedX, speedY;
        private Random random;

        public Particle(int startX, int startY) {
            this.random = new Random();
            this.x = startX;
            this.y = startY;
            this.speedX = (random.nextFloat() - 0.5f) * 2;
            this.speedY = (random.nextFloat() - 0.5f) * 2;
            this.color = new Color(255, 255, 255, (int) (alpha * 255));
        }

        public void update() {
            x += speedX;
            y += speedY;
            alpha -= 0.01f; // Fade out the particle over time
            color = new Color(255, 255, 255, (int) (alpha * 255));
        }

        public void draw(Graphics g) {
            g.setColor(color);
            g.fillOval(x, y, size, size);
        }
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
            g.drawImage(backgroundImage, 0, 0, getWidth(), getHeight(), this); // Stretch to fill
        }
    }
    
    // Main method to run the application
    public static void main(String[] args) {
        SwingUtilities.invokeLater(GameLogin::new);
    }

	public List<Particle> getParticles() {
		return particles;
	}

	public void setParticles(List<Particle> particles) {
		this.particles = particles;
	}
}

