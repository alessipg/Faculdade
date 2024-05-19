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

public class SobreWindow extends JFrame {

	private JPanel contentPane;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					SobreWindow frame = new SobreWindow();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the frame.
	 */
	public SobreWindow() {
		setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		setBounds(100, 100, 450, 450);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));

		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLabel lblExemploGui = new JLabel("Exemplo GUI");
		lblExemploGui.setFont(new Font("Dialog", Font.BOLD, 50));
		lblExemploGui.setBounds(38, 12, 357, 140);
		contentPane.add(lblExemploGui);
		
		JLabel lblGabrielAlessiPosonski = new JLabel("Gabriel Alessi Posonski");
		lblGabrielAlessiPosonski.setBounds(134, 164, 204, 15);
		contentPane.add(lblGabrielAlessiPosonski);
		
		JLabel lblUniversidadeTecnolgicaFederal = new JLabel("Universidade Tecnológica Federal do Paraná");
		lblUniversidadeTecnolgicaFederal.setBounds(66, 191, 316, 15);
		contentPane.add(lblUniversidadeTecnolgicaFederal);
		
		JLabel lblCmpusPontaGrossa = new JLabel("Câmpus Ponta Grossa");
		lblCmpusPontaGrossa.setBounds(134, 218, 178, 15);
		contentPane.add(lblCmpusPontaGrossa);
		
		JButton btnOk = new JButton("OK");
		btnOk.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				btnOkActionPerformed();
			}
		});
		btnOk.setBounds(161, 285, 117, 25);
		contentPane.add(btnOk);
	}

	private void btnOkActionPerformed() {
		this.dispose();
		
	}
}
