package core;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.net.URL;

public class SignUpPage extends JFrame {
    private static final long serialVersionUID = 1L;
    private JTextField usernameField;
    private JPasswordField passwordField;
    private BackgroundPanel bgPanel;

    public SignUpPage() {
        setTitle("GameVerse - Signup");
        setExtendedState(JFrame.MAXIMIZED_BOTH);
        setUndecorated(true);
        setDefaultCloseOperation(EXIT_ON_CLOSE);

        // Load background image
        URL bgURL = getClass().getResource("/resources/background.jpg");
        if (bgURL == null) {
            JOptionPane.showMessageDialog(this, "Background image not found!", "Error", JOptionPane.ERROR_MESSAGE);
            System.exit(1);
        }
        bgPanel = new BackgroundPanel(bgURL);

        // Centered glass panel
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
        card.setPreferredSize(new Dimension(400, 400));
        card.setOpaque(false);
        card.setBorder(BorderFactory.createEmptyBorder(40, 40, 40, 40));
        card.setLayout(new GridBagLayout());

        GridBagConstraints gbc = new GridBagConstraints();
        gbc.insets = new Insets(15, 0, 10, 0);
        gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.gridx = 0;

        JLabel title = new JLabel("Create Your GameVerse Account", SwingConstants.CENTER);
        title.setFont(new Font("Segoe UI", Font.BOLD, 20));
        title.setForeground(Color.WHITE);
        gbc.gridy = 0;
        card.add(title, gbc);

        usernameField = createInputField("Username");
        gbc.gridy++;
        card.add(usernameField, gbc);

        passwordField = new JPasswordField();
        passwordField.setFont(new Font("Segoe UI", Font.PLAIN, 16));
        passwordField.setBorder(BorderFactory.createTitledBorder("Password"));
        gbc.gridy++;
        card.add(passwordField, gbc);

        JButton signup = createStyledButton("Signup");
        gbc.gridy++;
        card.add(signup, gbc);

        signup.addActionListener(this::signupAction);

        // Center the card in the background
        bgPanel.setLayout(new GridBagLayout());
        GridBagConstraints bgConstraints = new GridBagConstraints();
        bgConstraints.gridx = 0;
        bgConstraints.gridy = 0;
        bgConstraints.anchor = GridBagConstraints.CENTER;
        bgPanel.add(card, bgConstraints);

        setContentPane(bgPanel);
        setVisible(true);
    }

    private JTextField createInputField(String title) {
        JTextField field = new JTextField();
        field.setFont(new Font("Segoe UI", Font.PLAIN, 16));
        field.setBorder(BorderFactory.createTitledBorder(title));
        return field;
    }

    private JButton createStyledButton(String text) {
        JButton button = new JButton(text);
        button.setBackground(new Color(70, 130, 180));
        button.setForeground(Color.WHITE);
        button.setFocusPainted(false);
        button.setFont(new Font("Segoe UI", Font.BOLD, 14));
        button.setBorder(BorderFactory.createEmptyBorder(10, 20, 10, 20));
        return button;
    }

    private void signupAction(ActionEvent e) {
        String user = usernameField.getText();
        String pass = new String(passwordField.getPassword());
        if (user.isBlank() || pass.isBlank()) {
            JOptionPane.showMessageDialog(this, "Fields can't be empty!");
            return;
        }
        UserUtil.saveUser(user, pass);
        JOptionPane.showMessageDialog(this, "Signup Successful! Login now.");
        dispose();
        new GameLogin();
    }

    // Inner class for background image panel
    class BackgroundPanel extends JPanel {
        private static final long serialVersionUID = 1L;
        private Image backgroundImage;

        public BackgroundPanel(URL url) {
            this.backgroundImage = new ImageIcon(url).getImage();
        }

        @Override
        protected void paintComponent(Graphics g) {
            super.paintComponent(g);
            g.drawImage(backgroundImage, 0, 0, getWidth(), getHeight(), this); // Stretch to full screen
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(SignUpPage::new);
    }
}
