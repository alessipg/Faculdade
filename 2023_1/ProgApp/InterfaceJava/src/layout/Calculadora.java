package layout;

import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.border.EmptyBorder;

public class Calculadora extends JFrame {

	private JTextField txtVisor;
	private JButton btnZero;
	private JButton btnUm;
	private JButton btnDois;
	private JButton btnTres;
	private JButton btnQuatro;
	private JButton btnCinco;
	private JButton btnSeis;
	private JButton btnSete;
	private JButton btnOito;
	private JButton btnNove;
	private JButton btnSoma;
	private JButton btnSubtracao;
	private JButton btnMultiplicacao;
	private JButton btnDivisao;
	private JButton btnIgual;
	private JButton btnLimpar;
	private JButton btnMS;
	private JButton btnMR;
	private JButton btnMC;
	private JButton btnVirgula;
	private JPanel painelCentral;
	private float valor;
	private int sinal;

	public Calculadora() {
		this.initComponents();
	}

	private void initComponents() {
		this.txtVisor = new JTextField();
		this.txtVisor.setText("0.0");
		this.txtVisor.setFont(new java.awt.Font("Tahoma", 1, 24));
		this.txtVisor.setHorizontalAlignment(javax.swing.JTextField.RIGHT);
		this.txtVisor.setEnabled(false);

		this.add(txtVisor, BorderLayout.NORTH);

		this.btnZero = new JButton("0");
		this.btnZero.setFont(new java.awt.Font("Tahoma", 0, 24));

		this.btnUm = new JButton("1");
		this.btnUm.setFont(new java.awt.Font("Tahoma", 0, 24));

		this.btnDois = new JButton("2");
		this.btnDois.setFont(new java.awt.Font("Tahoma", 0, 24));

		this.btnTres = new JButton("3");
		this.btnTres.setFont(new java.awt.Font("Tahoma", 0, 24));

		this.btnQuatro = new JButton("4");
		this.btnQuatro.setFont(new java.awt.Font("Tahoma", 0, 24));

		this.btnCinco = new JButton("5");
		this.btnCinco.setFont(new java.awt.Font("Tahoma", 0, 24));

		this.btnSeis = new JButton("6");
		this.btnSeis.setFont(new java.awt.Font("Tahoma", 0, 24));

		this.btnSete = new JButton("7");
		this.btnSete.setFont(new java.awt.Font("Tahoma", 0, 24));

		this.btnOito = new JButton("8");
		this.btnOito.setFont(new java.awt.Font("Tahoma", 0, 24));

		this.btnNove = new JButton("9");
		this.btnNove.setFont(new java.awt.Font("Tahoma", 0, 24));

		this.btnSoma = new JButton("+");
		this.btnSoma.setFont(new java.awt.Font("Tahoma", 0, 24));

		this.btnSubtracao = new JButton("-");
		this.btnSubtracao.setFont(new java.awt.Font("Tahoma", 0, 24));

		this.btnMultiplicacao = new JButton("*");
		this.btnMultiplicacao.setFont(new java.awt.Font("Tahoma", 0, 24));

		this.btnDivisao = new JButton("/");
		this.btnDivisao.setFont(new java.awt.Font("Tahoma", 0, 24));

		this.btnIgual = new JButton("=");
		this.btnIgual.setFont(new java.awt.Font("Tahoma", 0, 24));

		this.btnLimpar = new JButton("C");
		this.btnLimpar.setFont(new java.awt.Font("Tahoma", 0, 24));

		this.btnMS = new JButton("MS");
		this.btnMS.setFont(new java.awt.Font("Tahoma", 0, 24));

		this.btnMR = new JButton("MR");
		this.btnMR.setFont(new java.awt.Font("Tahoma", 0, 24));

		this.btnMC = new JButton("MC");
		this.btnMC.setFont(new java.awt.Font("Tahoma", 0, 24));

		this.btnVirgula = new JButton(",");
		this.btnVirgula.setFont(new java.awt.Font("Tahoma", 0, 24));

		this.painelCentral = new JPanel(new GridLayout(5, 4, 5, 5));

		this.painelCentral.setBorder(new EmptyBorder(5, 5, 5, 5));
		this.painelCentral.add(btnMS);
		this.painelCentral.add(btnMR);
		this.painelCentral.add(btnMC);
		this.painelCentral.add(btnLimpar);

		this.painelCentral.add(btnSete);
		this.painelCentral.add(btnOito);
		this.painelCentral.add(btnNove);
		this.painelCentral.add(btnDivisao);

		this.painelCentral.add(btnQuatro);
		this.painelCentral.add(btnCinco);
		this.painelCentral.add(btnSeis);
		this.painelCentral.add(btnMultiplicacao);

		this.painelCentral.add(btnUm);
		this.painelCentral.add(btnDois);
		this.painelCentral.add(btnTres);
		this.painelCentral.add(btnSubtracao);

		this.painelCentral.add(btnZero);
		this.painelCentral.add(btnVirgula);
		this.painelCentral.add(btnIgual);
		this.painelCentral.add(btnSoma);

		this.add(painelCentral, BorderLayout.CENTER);

		this.setTitle("Calculadora");
		this.setSize(320, 400);
		this.setResizable(false);
		this.setLocationRelativeTo(null);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		this.btnLimpar.addActionListener(new java.awt.event.ActionListener() {

			@Override
			public void actionPerformed(ActionEvent evt) {
				btnLimparActionPerformed();
			}

		});
		this.btnUm.addActionListener(new java.awt.event.ActionListener() {

			@Override
			public void actionPerformed(ActionEvent evt) {
				btnUmActionPerformed();
			}

		});
		this.btnDois.addActionListener(new java.awt.event.ActionListener() {

			@Override
			public void actionPerformed(ActionEvent evt) {
				btnDoisActionPerformed();
			}

		});
		this.btnTres.addActionListener(new java.awt.event.ActionListener() {

			@Override
			public void actionPerformed(ActionEvent evt) {
				btnTresActionPerformed();
			}

		});
		this.btnQuatro.addActionListener(new java.awt.event.ActionListener() {

			@Override
			public void actionPerformed(ActionEvent evt) {
				btnQuatroActionPerformed();
			}

		});
		this.btnCinco.addActionListener(new java.awt.event.ActionListener() {

			@Override
			public void actionPerformed(ActionEvent evt) {
				btnCincoActionPerformed();
			}

		});
		this.btnSeis.addActionListener(new java.awt.event.ActionListener() {

			@Override
			public void actionPerformed(ActionEvent evt) {
				btnSeisActionPerformed();
			}

		});
		this.btnSete.addActionListener(new java.awt.event.ActionListener() {

			@Override
			public void actionPerformed(ActionEvent evt) {
				btnSeteActionPerformed();
			}

		});
		this.btnOito.addActionListener(new java.awt.event.ActionListener() {

			@Override
			public void actionPerformed(ActionEvent evt) {
				btnOitoActionPerformed();
			}

		});
		this.btnNove.addActionListener(new java.awt.event.ActionListener() {

			@Override
			public void actionPerformed(ActionEvent evt) {
				btnNoveActionPerformed();
			}

		});
		this.btnZero.addActionListener(new java.awt.event.ActionListener() {

			@Override
			public void actionPerformed(ActionEvent evt) {
				btnZeroActionPerformed();
			}

		});
		this.btnVirgula.addActionListener(new java.awt.event.ActionListener() {
			@Override
			public void actionPerformed(ActionEvent evt) {
				btnVirgulaActionPerformed();
			}
		});
		this.btnSoma.addActionListener(new java.awt.event.ActionListener() {
			@Override
			public void actionPerformed(ActionEvent evt) {
				btnSomaActionPerformed();
			}
		});
		this.btnSubtracao.addActionListener(new java.awt.event.ActionListener() {
			@Override
			public void actionPerformed(ActionEvent evt) {
				btnSubtracaoActionPerformed();
			}
		});
		this.btnMultiplicacao.addActionListener(new java.awt.event.ActionListener() {
			@Override
			public void actionPerformed(ActionEvent evt) {
				btnMultiplicacaoActionPerformed();
			}
		});
		this.btnDivisao.addActionListener(new java.awt.event.ActionListener() {
			@Override
			public void actionPerformed(ActionEvent evt) {
				btnDivisaoActionPerformed();
			}
		});
		this.btnMS.addActionListener(new java.awt.event.ActionListener() {
			@Override
			public void actionPerformed(ActionEvent evt) {
				btnMSActionPerformed();
			}
		});
		this.btnMR.addActionListener(new java.awt.event.ActionListener() {
			@Override
			public void actionPerformed(ActionEvent evt) {
				btnMRActionPerformed();
			}
		});
		this.btnMC.addActionListener(new java.awt.event.ActionListener() {
			@Override
			public void actionPerformed(ActionEvent evt) {
				btnMCActionPerformed();
			}
		});
		this.btnIgual.addActionListener(new java.awt.event.ActionListener() {
			@Override
			public void actionPerformed(ActionEvent evt) {
				btnIgualActionPerformed();
			}
		});

	}

	private void btnLimparActionPerformed() {
		Operacoes.limpar();
		txtVisor.setText("0.0");
		sinal = 0;
	}

	private void btnUmActionPerformed() {
		if (!txtVisor.getText().equals("0.0"))
			txtVisor.setText(txtVisor.getText() + "1");
		else {
			txtVisor.setText(null);
			txtVisor.setText("1");

		}

	}

	private void btnDoisActionPerformed() {
		if (!txtVisor.getText().equals("0.0")) {
			txtVisor.setText(txtVisor.getText() + "2");
		} else {
			txtVisor.setText(null);
			txtVisor.setText("2");
		}
	}

	private void btnTresActionPerformed() {
		if (!txtVisor.getText().equals("0.0")) {
			txtVisor.setText(txtVisor.getText() + "3");
		} else {
			txtVisor.setText(null);
			txtVisor.setText("3");
		}
	}

	private void btnQuatroActionPerformed() {
		if (!txtVisor.getText().equals("0.0")) {
			txtVisor.setText(txtVisor.getText() + "4");
		} else {
			txtVisor.setText(null);
			txtVisor.setText("4");
		}
	}

	private void btnCincoActionPerformed() {
		if (!txtVisor.getText().equals("0.0")) {
			txtVisor.setText(txtVisor.getText() + "5");
		} else {
			txtVisor.setText(null);
			txtVisor.setText("5");
		}
	}

	private void btnSeisActionPerformed() {
		if (!txtVisor.getText().equals("0.0")) {
			txtVisor.setText(txtVisor.getText() + "6");
		} else {
			txtVisor.setText(null);
			txtVisor.setText("6");
		}
	}

	private void btnSeteActionPerformed() {
		if (!txtVisor.getText().equals("0.0")) {
			txtVisor.setText(txtVisor.getText() + "7");
		} else {
			txtVisor.setText(null);
			txtVisor.setText("7");
		}
	}

	private void btnOitoActionPerformed() {
		if (!txtVisor.getText().equals("0.0")) {
			txtVisor.setText(txtVisor.getText() + "8");
		} else {
			txtVisor.setText(null);
			txtVisor.setText("8");
		}
	}

	private void btnNoveActionPerformed() {
		if (!txtVisor.getText().equals("0.0")) {
			txtVisor.setText(txtVisor.getText() + "9");
		} else {
			txtVisor.setText(null);
			txtVisor.setText("9");
		}
	}

	private void btnZeroActionPerformed() {
		if (!txtVisor.getText().equals("0.0"))
			txtVisor.setText(txtVisor.getText() + "0");
	}

	private void btnVirgulaActionPerformed() {
		int aux = txtVisor.getText().indexOf(",");
		if (aux != -1 && !txtVisor.getText().equals("0.0")) {
			System.out.println("Entrou primeiro");
			return;
		}
		if (!txtVisor.getText().equals("0.0")) {
			txtVisor.setText(txtVisor.getText() + ",");
		}
		if (txtVisor.getText().equals("0.0")) {
			System.out.println("entrou");
			txtVisor.setText("0,");

		}

	}

	private void btnSomaActionPerformed() {
		valor = Float.parseFloat(txtVisor.getText().replace(",", "."));
		Operacoes.somar(valor);
		txtVisor.setText("0.0");
		sinal = 1;
	}

	private void btnSubtracaoActionPerformed() {
		valor = Float.parseFloat(txtVisor.getText().replace(",", "."));
		Operacoes.subtrair(valor);
		txtVisor.setText("0.0");
		sinal = 2;
	}

	private void btnMultiplicacaoActionPerformed() {
		valor = Float.parseFloat(txtVisor.getText().replace(",", "."));
		Operacoes.multiplicar(valor);
		txtVisor.setText("0.0");
		sinal = 3;
	}

	private void btnDivisaoActionPerformed() {
		valor = Float.parseFloat(txtVisor.getText().replace(",", "."));
		Operacoes.dividir(valor);
		txtVisor.setText("0.0");
		sinal = 4;
	}

	public void btnMSActionPerformed() {
		valor = Float.parseFloat(txtVisor.getText().replace(",", "."));
		Operacoes.armazenar(valor);
		txtVisor.setText("0.0");
	}

	public void btnMRActionPerformed() {
		txtVisor.setText(Operacoes.recuperar());
	}

	public void btnMCActionPerformed() {
		Operacoes.limparMem();
		txtVisor.setText("0.0");
	}

	private void btnIgualActionPerformed() {
		txtVisor.setText("" + Operacoes.igual(sinal, Float.parseFloat(txtVisor.getText().replace(",", "."))));
	}

	public static void main(String[] args) {
		new Calculadora().setVisible(true);
	}

}
