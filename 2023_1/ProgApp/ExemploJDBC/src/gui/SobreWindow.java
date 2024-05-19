package gui;

import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JLabel;
import java.awt.Font;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.SwingConstants;

public class SobreWindow extends JFrame {

	private JPanel contentPane;

	/**
	 * Launch the application.
	 */
	/**
	 * Create the frame.
	 */
	public SobreWindow() {
		initComponents();
	}
	public void initComponents() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 300);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));

		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLabel lblExemploGui = new JLabel("Exemplo GUI");
		lblExemploGui.setHorizontalAlignment(SwingConstants.CENTER);
		lblExemploGui.setFont(new Font("Dialog", Font.BOLD, 51));
		lblExemploGui.setBounds(27, 12, 401, 80);
		contentPane.add(lblExemploGui);
		
		JLabel lblGabrielAlessiPosonski = new JLabel("Gabriel Alessi Posonski");
		lblGabrielAlessiPosonski.setHorizontalAlignment(SwingConstants.CENTER);
		lblGabrielAlessiPosonski.setBounds(121, 112, 225, 15);
		contentPane.add(lblGabrielAlessiPosonski);
		
		JButton btnOk = new JButton("OK");
		btnOk.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				btnOkActionPerformed();
			}
		});
		btnOk.setBounds(158, 199, 117, 25);
		contentPane.add(btnOk);
	}
	
	protected void btnOkActionPerformed() {
		
		this.dispose();
	}
}
