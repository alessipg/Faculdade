package messagedialog;

import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JButton;
import java.awt.GridLayout;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.JLabel;

public class DialogWindow extends JFrame {

	private JPanel contentPane;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					DialogWindow frame = new DialogWindow();
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
	public DialogWindow() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 510, 537);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(20, 20, 20, 20));

		setContentPane(contentPane);
		
		JButton btnInformacao = new JButton("Mensagem de Informação");
		btnInformacao.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				JOptionPane.showMessageDialog(null, "Mensagem de Informação", "Informação", JOptionPane.INFORMATION_MESSAGE);
			}
		});
		contentPane.setLayout(new GridLayout(0, 1, 0, 0));
		contentPane.add(btnInformacao);
		
		JButton btnAdvertencia = new JButton("Mensagem de Advertência");
		btnAdvertencia.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				JOptionPane.showMessageDialog(null, "Mensagem de Advertência", "Advertência", JOptionPane.WARNING_MESSAGE);
			}
		});
		contentPane.add(btnAdvertencia);
		
		JButton btnErro = new JButton("Mensagem de Erro");
		btnErro.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				JOptionPane.showMessageDialog(btnErro, "Mensagem de Erro", "Erro", JOptionPane.ERROR_MESSAGE);
				
			}
		});
		contentPane.add(btnErro);
		
		JButton btnQuestionamento = new JButton("Mensagem de Questionamento");
		btnQuestionamento.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				JOptionPane.showMessageDialog(null, "Mensagem de Questionamento", "Questionamento", JOptionPane.QUESTION_MESSAGE);
			}
		});
		contentPane.add(btnQuestionamento);
		
		JButton btnSemIcone = new JButton("Mensagem sem Ícone");
		btnSemIcone.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				JOptionPane.showMessageDialog(null, "Mensagem sem Ícone", "Genérico", JOptionPane.DEFAULT_OPTION);
			}
		});
		contentPane.add(btnSemIcone);
		
		JButton btnNewButton = new JButton("New button");
		btnNewButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String valor1 = JOptionPane.showInputDialog(null, "Insira valor 1:", "Entrada de Dados", JOptionPane.QUESTION_MESSAGE);
				String valor2 = JOptionPane.showInputDialog(null, "Insira valor 2:", "Entrada de Dados", JOptionPane.QUESTION_MESSAGE);
				int confirmacao = JOptionPane.showConfirmDialog(null, "Deseja confirmar?", "Confirmação", JOptionPane.YES_NO_CANCEL_OPTION);
				if(confirmacao == 0) System.out.println("Operação concluída com sucesso.");
				System.out.println(confirmacao);
				String result = print(Double.parseDouble(valor1), Double.parseDouble(valor2));
				JOptionPane.showMessageDialog(null, result, "Resultados", JOptionPane.DEFAULT_OPTION);
			}
		});
		contentPane.add(btnNewButton);
		
		
		JLabel label = new JLabel("");
		contentPane.add(label);
	}
	private String print(double valor1, double valor2) {
		String result = "soma = " + (valor1+valor2) + "\nSubtração= " + (valor1-valor2) + "\nMultiplicação = " + (valor1*valor2) + "\nDivisão = " + (valor1/valor2);
		return result;
	}
}
