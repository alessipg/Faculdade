package layout;

import java.awt.BorderLayout;

import javax.swing.JButton;
import javax.swing.JFrame;

public class BorderLayoutFrame extends JFrame{
	
	private JButton btnNorte;
	private JButton btnSul;
	private JButton btnLeste;
	private JButton btnOeste;
	private JButton btnCentro;
	private BorderLayout layout;
	
	public BorderLayoutFrame () {
		
		this.layout = new BorderLayout(5, 5);
		this.setLayout(layout);
		
		
		this.btnNorte = new JButton("Norte");
		this.btnSul = new JButton("Sul");
		this.btnLeste = new JButton("Leste");
		this.btnOeste = new JButton("Oeste");
		this.btnCentro = new JButton("Centro");
		
		this.add(btnNorte, BorderLayout.NORTH);
		this.add(btnSul, BorderLayout.SOUTH);
		this.add(btnLeste, BorderLayout.EAST);
		this.add(btnOeste, BorderLayout.WEST);
		this.add(btnCentro, BorderLayout.CENTER);
		
		this.setTitle("Exemplo de BorderLayout");
		this.setSize(600, 400);
		this.setLocationRelativeTo(null);
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
	}
	public static void main(String[] args) {
		new BorderLayoutFrame().setVisible(true);
	}
}
