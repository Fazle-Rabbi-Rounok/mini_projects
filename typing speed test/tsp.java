import javax.swing.*;
import javax.swing.text.*;
import javax.swing.event.*;
import java.awt.*;
import java.io.*;
import java.util.*;
import java.util.List;

class ImagePanel extends JPanel {
    private Image image;

    public ImagePanel(String imagePath) {
        try {
            image = new ImageIcon(imagePath).getImage();
        } catch (Exception e) {
            e.printStackTrace();
        }
        setOpaque(false);
        setLayout(new BorderLayout());
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        if (image != null) {
            g.drawImage(image, 0, 0, getWidth(), getHeight(), this);
        }
    }
}

public class tsp extends JFrame {
    private static final String[] EASY_TEXTS = {
            "The quick brown fox jumps over the lazy dog.",
            "Java is fun. Learn typing fast.",
            "Practice makes perfect. Stay consistent.",
            "She always brings her lunch to school",
            "I enjoy reading books on quiet evenings",
            "The little boy kicked the red football",
            "They went shopping at the local market",
            "My sister loves playing the piano daily",
            "We should finish homework before watching TV",
            "He drinks coffee every morning before work",
            "The teacher explained the lesson very clearly",
            "Birds were flying high above the trees"
    };

    private static final String[] MEDIUM_TEXTS = {
            "Software development involves planning and testing.",
            "Focus on accuracy before aiming for speed.",
            "Applications rely on efficient algorithms."
    };

    private static final String[] HARD_TEXTS = {
            "Cybersecurity protects sensitive data from attacks.",
            "Distributed systems handle latency and failures.",
            "Machine learning models need regular tuning."
    };

    private JTextPane typingPane;
    private JTextArea displayArea;
    private JComboBox<String> levelCombo, timeCombo;
    private JLabel timerLabel, wpmLabel, accuracyLabel;
    private JButton startButton, historyButton;

    private final StyleContext styleContext = new StyleContext();
    private final Style styleIncorrect = styleContext.addStyle("incorrect", null);
    private final Style styleDefault = styleContext.getStyle(StyleContext.DEFAULT_STYLE);

    private javax.swing.Timer swingTimer;
    private java.util.Timer timer;

    private int timeLeft;
    private long startTime;

    private String currentText = "";
    private int totalTyped = 0, totalCorrect = 0;
    private List<String> sentencePool = new ArrayList<>();
    private final Random rand = new Random();

    private boolean sentenceComplete = false;
    private final List<TypingHistoryEntry> historyList = new ArrayList<>();
    private String currentDifficulty = "";

    private Image backgroundImage;

    public tsp() {
        setTitle("Typing Speed Test");
        setSize(1000, 700);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        backgroundImage = new ImageIcon("background.jpg").getImage();

        JPanel backgroundPanel = new JPanel() {
            @Override
            protected void paintComponent(Graphics g) {
                super.paintComponent(g);
                g.drawImage(backgroundImage, 0, 0, getWidth(), getHeight(), this);
            }
        };
        backgroundPanel.setLayout(new BorderLayout(10, 10));
        setContentPane(backgroundPanel);

        StyleConstants.setForeground(styleIncorrect, Color.RED);

        Font headerFont = new Font("Segoe UI", Font.BOLD, 28);
        Font contentFont = new Font("Consolas", Font.PLAIN, 18);

        JLabel headerLabel = new JLabel("⌨️ Typing Speed Test", JLabel.CENTER);
        headerLabel.setFont(headerFont);
        headerLabel.setForeground(Color.WHITE);
        headerLabel.setOpaque(false);
        backgroundPanel.add(headerLabel, BorderLayout.NORTH);

        displayArea = new JTextArea();
        displayArea.setFont(contentFont);
        displayArea.setWrapStyleWord(true);
        displayArea.setLineWrap(true);
        displayArea.setEditable(false);
        displayArea.setOpaque(false);
        displayArea.setForeground(Color.WHITE);
        JScrollPane displayScroll = new JScrollPane(displayArea);
        displayScroll.setOpaque(false);
        displayScroll.getViewport().setOpaque(false);

        typingPane = new JTextPane();
        typingPane.setFont(contentFont);
        typingPane.setEditable(false);
        typingPane.setOpaque(false);
        typingPane.setForeground(Color.WHITE);
        typingPane.getDocument().addDocumentListener(new DocumentListener() {
            public void insertUpdate(DocumentEvent e) {
                handleTyping();
            }

            public void removeUpdate(DocumentEvent e) {
                handleTyping();
            }

            public void changedUpdate(DocumentEvent e) {
            }
        });
        JScrollPane typingScroll = new JScrollPane(typingPane);
        typingScroll.setOpaque(false);
        typingScroll.getViewport().setOpaque(false);

        JPanel controlPanel = new JPanel(new GridLayout(2, 3, 10, 10));
        controlPanel.setOpaque(false);

        levelCombo = new JComboBox<>(new String[] { "Easy", "Medium", "Hard" });
        timeCombo = new JComboBox<>(new String[] { "30", "60", "90" });

        styleComboBox(levelCombo);
        styleComboBox(timeCombo);

        timerLabel = createStatLabel("Time: --");
        wpmLabel = createStatLabel("WPM: --");
        accuracyLabel = createStatLabel("Accuracy: --");

        controlPanel.add(new JLabel("Level:", JLabel.RIGHT)).setForeground(Color.WHITE);
        controlPanel.add(levelCombo);
        controlPanel.add(timerLabel);
        controlPanel.add(new JLabel("Time (s):", JLabel.RIGHT)).setForeground(Color.WHITE);
        controlPanel.add(timeCombo);
        controlPanel.add(wpmLabel);

        JPanel centerPanel = new JPanel(new GridLayout(2, 1, 10, 10));
        centerPanel.setOpaque(false);
        centerPanel.add(displayScroll);
        centerPanel.add(typingScroll);

        startButton = createButton("Start Test");
        historyButton = createButton("History");

        JPanel buttonPanel = new JPanel();
        buttonPanel.setOpaque(false);
        buttonPanel.add(startButton);
        buttonPanel.add(historyButton);

        backgroundPanel.add(controlPanel, BorderLayout.NORTH);
        backgroundPanel.add(centerPanel, BorderLayout.CENTER);
        backgroundPanel.add(buttonPanel, BorderLayout.SOUTH);

        startButton.addActionListener(e -> startTest());
        historyButton.addActionListener(e -> showHistoryDialog());

        loadHistoryFromFile();
    }

    private void styleComboBox(JComboBox<?> combo) {
        combo.setFont(new Font("Segoe UI", Font.PLAIN, 14));
        combo.setBackground(new Color(60, 60, 60));
        combo.setForeground(Color.WHITE);
    }

    private JButton createButton(String text) {
        JButton btn = new JButton(text) {
            @Override
            protected void paintComponent(Graphics g) {
                if (getModel().isRollover()) {
                    g.setColor(new Color(90, 150, 210));
                } else {
                    g.setColor(new Color(70, 130, 180));
                }
                g.fillRoundRect(0, 0, getWidth(), getHeight(), 12, 12);
                super.paintComponent(g);
            }

            @Override
            protected void paintBorder(Graphics g) {
                // Do nothing: removes default border
            }
        };
        btn.setContentAreaFilled(false);
        btn.setFocusPainted(false);
        btn.setBorderPainted(false);
        btn.setForeground(Color.WHITE);
        btn.setFont(new Font("Segoe UI", Font.BOLD, 16));
        btn.setCursor(new Cursor(Cursor.HAND_CURSOR));
        btn.setOpaque(false);
        btn.setMargin(new Insets(10, 20, 10, 20));
        return btn;
    }

    private JLabel createStatLabel(String text) {
        JLabel lbl = new JLabel(text, JLabel.CENTER);
        lbl.setFont(new Font("Segoe UI", Font.PLAIN, 16));
        lbl.setForeground(Color.WHITE);
        return lbl;
    }

    private void startTest() {
        if (swingTimer != null && swingTimer.isRunning()) {
            swingTimer.stop();
        }

        typingPane.setEditable(false);
        displayArea.setText("Starting in 3...");
        typingPane.setText("");

        timer = new java.util.Timer();
        timer.schedule(new TimerTask() {
            int countdown = 3;

            @Override
            public void run() {
                if (countdown > 1) {
                    countdown--;
                    SwingUtilities.invokeLater(() -> displayArea.setText("Starting in " + countdown + "..."));
                } else {
                    timer.cancel();
                    SwingUtilities.invokeLater(() -> beginTypingTest());
                }
            }
        }, 0, 1000);
    }

    private void beginTypingTest() {
        timeLeft = Integer.parseInt((String) timeCombo.getSelectedItem());
        timerLabel.setText("Time: " + timeLeft + "s");
        wpmLabel.setText("WPM: --");
        accuracyLabel.setText("Accuracy: --");

        totalTyped = 0;
        totalCorrect = 0;
        sentencePool.clear();

        currentDifficulty = (String) levelCombo.getSelectedItem();
        switch (currentDifficulty) {
            case "Medium" -> sentencePool.addAll(Arrays.asList(MEDIUM_TEXTS));
            case "Hard" -> sentencePool.addAll(Arrays.asList(HARD_TEXTS));
            default -> sentencePool.addAll(Arrays.asList(EASY_TEXTS));
        }

        nextSentence();
        startTime = System.currentTimeMillis();

        typingPane.setText("");
        typingPane.setEditable(true);
        typingPane.requestFocusInWindow();

        swingTimer = new javax.swing.Timer(1000, e -> {
            timeLeft--;
            timerLabel.setText("Time: " + timeLeft + "s");
            if (timeLeft <= 0) {
                swingTimer.stop();
                typingPane.setEditable(false);
                updateLiveStats(true);
                saveSessionToHistory();
                showResultPopup();
            } else {
                updateLiveStats(false);
            }
        });
        swingTimer.start();
    }

    private void nextSentence() {
        currentText = sentencePool.get(rand.nextInt(sentencePool.size()));
        displayArea.setText(currentText);
        typingPane.setText("");
        sentenceComplete = false;
    }

    private void handleTyping() {
        SwingUtilities.invokeLater(() -> {
            String typed = typingPane.getText();
            StyledDocument doc = typingPane.getStyledDocument();

            int len = Math.min(typed.length(), currentText.length());
            doc.setCharacterAttributes(0, doc.getLength(), styleDefault, true);

            for (int i = 0; i < len; i++) {
                if (typed.charAt(i) != currentText.charAt(i)) {
                    doc.setCharacterAttributes(i, 1, styleIncorrect, true);
                }
            }

            if (typed.length() >= currentText.length() && !sentenceComplete) {
                sentenceComplete = true;
                totalTyped += currentText.length();
                totalCorrect += countCorrectChars(currentText, typed);
                nextSentence();
            }
        });
    }

    private int countCorrectChars(String expected, String typed) {
        int correct = 0;
        for (int i = 0; i < Math.min(expected.length(), typed.length()); i++) {
            if (expected.charAt(i) == typed.charAt(i))
                correct++;
        }
        return correct;
    }

    private void updateLiveStats(boolean forceUpdate) {
        long elapsed = System.currentTimeMillis() - startTime;
        if (elapsed < 1000)
            return;

        double minutes = elapsed / 60000.0;
        double wpm = (totalCorrect / 5.0) / minutes;
        double accuracy = totalTyped > 0 ? (totalCorrect * 100.0 / totalTyped) : 100.0;

        if (forceUpdate || elapsed % 1000 == 0) {
            wpmLabel.setText(String.format("WPM: %.1f", wpm));
            accuracyLabel.setText(String.format("Accuracy: %.1f%%", accuracy));
        }
    }

    private void saveSessionToHistory() {
        String typed = typingPane.getText();
        int correctNow = countCorrectChars(currentText, typed);

        int finalTotalTyped = totalTyped + typed.length();
        int finalTotalCorrect = totalCorrect + correctNow;

        long elapsed = System.currentTimeMillis() - startTime;
        double minutes = elapsed / 60000.0;
        double wpm = (finalTotalCorrect / 5.0) / minutes;
        double accuracy = finalTotalTyped > 0 ? (finalTotalCorrect * 100.0 / finalTotalTyped) : 100.0;

        TypingHistoryEntry entry = new TypingHistoryEntry(wpm, accuracy, (int) (elapsed / 1000), currentDifficulty);
        historyList.add(entry);
        saveEntryToFile(entry);
    }

    private void saveEntryToFile(TypingHistoryEntry entry) {
        File file = new File("typing_history.csv");
        boolean fileExists = file.exists();

        try (FileWriter writer = new FileWriter(file, true)) {
            if (!fileExists) {
                writer.write("WPM,Accuracy,TimeInSeconds,Difficulty\n");
            }
            writer.write(String.format("%.1f,%.1f,%d,%s\n", entry.wpm, entry.accuracy, entry.timeInSeconds,
                    entry.difficulty));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void loadHistoryFromFile() {
        File file = new File("typing_history.csv");
        if (!file.exists())
            return;

        try (BufferedReader reader = new BufferedReader(new FileReader(file))) {
            reader.readLine(); // skip header
            String line;
            while ((line = reader.readLine()) != null) {
                TypingHistoryEntry entry = TypingHistoryEntry.fromCSV(line);
                historyList.add(entry);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void showResultPopup() {
        String typed = typingPane.getText();
        int correctNow = countCorrectChars(currentText, typed);

        int finalTotalTyped = totalTyped + typed.length();
        int finalTotalCorrect = totalCorrect + correctNow;

        long elapsed = System.currentTimeMillis() - startTime;
        double minutes = elapsed / 60000.0;
        double wpm = (finalTotalCorrect / 5.0) / minutes;
        double accuracy = finalTotalTyped > 0 ? (finalTotalCorrect * 100.0 / finalTotalTyped) : 100.0;

        JLabel resultLabel = new JLabel(
                String.format(
                        "<html><div style='text-align:center;'>Time's Up!<br><br><b>WPM:</b> %.1f<br><b>Accuracy:</b> %.1f%%</div></html>",
                        wpm, accuracy),
                SwingConstants.CENTER);
        resultLabel.setFont(new Font("Segoe UI", Font.BOLD, 20));
        resultLabel.setForeground(Color.WHITE);
        resultLabel.setOpaque(true);
        resultLabel.setBackground(new Color(45, 45, 45));

        JOptionPane.showMessageDialog(this, resultLabel, "Test Result", JOptionPane.INFORMATION_MESSAGE);
    }

    private void showHistoryDialog() {
        JTextArea historyArea = new JTextArea();
        historyArea.setFont(new Font("Consolas", Font.PLAIN, 16));
        historyArea.setEditable(false);
        historyArea.setOpaque(false);
        historyArea.setForeground(new Color(220, 220, 220));
        historyArea.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));

        StringBuilder sb = new StringBuilder();
        sb.append("WPM\tAccuracy\tTime(s)\tDifficulty\n");
        sb.append("-------------------------------------------------\n");

        for (TypingHistoryEntry entry : historyList) {
            sb.append(String.format("%.1f\t%.1f%%\t\t%d\t%s\n",
                    entry.wpm, entry.accuracy, entry.timeInSeconds, entry.difficulty));
        }
        historyArea.setText(sb.toString());

        JScrollPane scrollPane = new JScrollPane(historyArea);
        scrollPane.setPreferredSize(new Dimension(550, 350));
        scrollPane.setOpaque(false);
        scrollPane.getViewport().setOpaque(false);
        scrollPane.setBorder(BorderFactory.createLineBorder(new Color(70, 130, 180), 2, true));

        ImagePanel panel = new ImagePanel("background2.jpg");
        panel.setBackground(new Color(34, 34, 34, 180)); 
        panel.setLayout(new BorderLayout(10, 10));

        JLabel titleLabel = new JLabel("Typing History", JLabel.CENTER);
        titleLabel.setForeground(new Color(90, 150, 210));
        titleLabel.setFont(new Font("Segoe UI", Font.BOLD, 22));
        titleLabel.setBorder(BorderFactory.createEmptyBorder(10, 0, 10, 0));
        titleLabel.setOpaque(false);

        panel.add(titleLabel, BorderLayout.NORTH);
        panel.add(scrollPane, BorderLayout.CENTER);

        JOptionPane.showMessageDialog(this, panel, "Typing History", JOptionPane.PLAIN_MESSAGE);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            tsp app = new tsp();
            app.setVisible(true);
        });
    }
}

class TypingHistoryEntry {
    double wpm;
    double accuracy;
    int timeInSeconds;
    String difficulty;

    TypingHistoryEntry(double wpm, double accuracy, int timeInSeconds, String difficulty) {
        this.wpm = wpm;
        this.accuracy = accuracy;
        this.timeInSeconds = timeInSeconds;
        this.difficulty = difficulty;
    }

    public static TypingHistoryEntry fromCSV(String line) {
        String[] parts = line.split(",");
        return new TypingHistoryEntry(
                Double.parseDouble(parts[0]),
                Double.parseDouble(parts[1]),
                Integer.parseInt(parts[2]),
                parts[3]);
    }
}
