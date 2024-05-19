package layout;

import java.awt.FlowLayout;

import javax.swing.JButton;
import javax.swing.JFrame;

public class FlowLayoutFrame extends JFrame {
	
	private JButton btnBotao1;
	private JButton btnBotao2;
	private JButton btnBotao3;
	private FlowLayout layout;
	
	public FlowLayoutFrame() {
		
		this.layout = new FlowLayout(FlowLayout.CENTER, 20, 20);//cria um flowlayout
		this.setLayout(layout);//configura o layout do frame
		
		//criação dos componentes
		this.btnBotao1 = new JButton("Botão 1");
		this.btnBotao2 = new JButton("Botão 2");
		this.btnBotao3 = new JButton("Botão 3");
		
		//adiciona os componentes ao frame
		this.add(btnBotao1);
		this.add(btnBotao2);
		this.add(btnBotao3);
		
		this.setTitle("Exemplo de FlowLayout");//define o titulo do frame
		this.setSize(600,400);//define o tamanho do frame
		this.setLocationRelativeTo(null);//define o local que será apresentado
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);//define o que ocorrerá com a aplicacao
	}
	public static void main(String[] args) {
		new FlowLayoutFrame().setVisible(true);	
	}
}
