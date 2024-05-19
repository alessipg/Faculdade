package aula_2_4;

public class Conta {
	final int numeroConta;
	int agencia;
	String nomeTitular;
	double saldo;
	static int qtdeContas = 0;
	public Conta(int numeroConta, int agencia, String nomeTitular, double saldo) {
		if(numeroConta >999999) {
			System.out.println("Número da conta excede o limite permitido");
		}
		this.numeroConta = numeroConta;
		this.agencia = agencia;
		this.nomeTitular = nomeTitular;
		this.saldo = saldo;
		qtdeContas += 1;
	}
	
	
	
}
