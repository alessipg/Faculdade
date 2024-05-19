package lista01;

import java.util.ArrayList;
import java.util.List;

public class Banco {
	private int cnpj;
	private String nomeBanco;
	private List<Conta> contasBancarias;

	public Banco(int cnpj, String nomeBanco) {
		this.cnpj = cnpj;
		this.nomeBanco = nomeBanco;
		this.contasBancarias = new ArrayList<Conta>();
	}

	public void criarNovaConta(int numeroConta, int cpfTitular, String nomeTitular) {
		Conta c1 = new Conta(numeroConta, new Cliente(cpfTitular, nomeTitular));
		this.contasBancarias.add(c1);
		System.out.println("Conta criada com sucesso.");
		System.out.println("===============================");
	}

	public void removerConta(int numeroConta) {
		for (Conta conta : contasBancarias) {
			if (conta.getNumeroConta() == numeroConta) {
				this.contasBancarias.remove(conta);
				System.out.println("Conta " + conta.getNumeroConta() + " removida.");
				System.out.println("===========================");
				break;
			}
		}

	}

	public void verificarSaldoConta(int numeroConta) {
		for (Conta conta : contasBancarias) {
			if (conta.getNumeroConta() == numeroConta) {
				conta.emitirSaldo();
				break;
			}
		}
	}

	public void realizarSaqueConta(int numeroConta, double valorSaque) {
		for (Conta conta : contasBancarias) {
			if (conta.getNumeroConta() == numeroConta) {
				conta.realizarSaque(valorSaque);
			}
		}
	}

	public void realizarDepositoConta(int numeroConta, double valorDeposito) {
		for (Conta conta : contasBancarias) {
			if (conta.getNumeroConta() == numeroConta) {
				conta.realizarDeposito(valorDeposito);
			}
		}
	}

	public void listarContas() {
		for (Conta conta : contasBancarias) {
			conta.emitirSaldo();
		}
	}

}
