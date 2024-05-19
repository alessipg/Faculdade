package layout;

import java.awt.GridLayout;

import javax.swing.JButton;
import javax.swing.JFrame;

public class GridLayoutFrame extends JFrame{

	private JButton btnBotao1;
	private JButton btnBotao2;
	private JButton btnBotao3;
	private JButton btnBotao4;
	private JButton btnBotao5;
	private JButton btnBotao6;
	private GridLayout layout;
	
	public GridLayoutFrame() {
		
		this.layout = new GridLayout(3, 2, 5, 5);
		this.setLayout(layout);
		
		this.btnBotao1 = new JButton("Botão 1");
		this.btnBotao2 = new JButton("Botão 2");
		this.btnBotao3 = new JButton("Botão 3");
		this.btnBotao4 = new JButton("Botão 4");
		this.btnBotao5 = new JButton("Botão 5");
		this.btnBotao6 = new JButton("Botão 6");
	
		this.add(btnBotao1);
		this.add(btnBotao2);
		this.add(btnBotao3);
		this.add(btnBotao4);
		this.add(btnBotao5);
		this.add(btnBotao6);
		
		this.setTitle("Exemplo de GridLayout");
		this.setSize(600,400);
		this.setLocationRelativeTo(null);
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
	}

	public static void main(String[] args) {
		new GridLayoutFrame().setVisible(true);
	}
}
