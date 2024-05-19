package lista02_1;

import java.util.ArrayList;
import java.util.List;

public class Banco {

	private String nome;
	private String cnpj;
	private List<Conta> contas;
	public Banco(String nome, String cnpj) { 
		this.nome = nome;
		this.cnpj = cnpj;
	}
	
	public void criarConta(int numero, Cliente titular) {
		contas = new ArrayList<>();
		Conta conta = new Conta(numero, titular);
		contas.add(conta);
		System.out.println("Conta criada com sucesso.");
	}
	
	public void realizarDeposito(int numero,float valor) {
		for(Conta conta : contas) {
			if(conta.getNumero() == numero) {
				conta.setSaldo(conta.getSaldo()+valor);
				System.out.println("Depósito realizado com sucesso.");
			}
			else
				System.out.println("Conta não localizada.");
		}
	}
	
	public void consultarSaldo(int numero) {
		for(Conta conta : contas) {
			if(conta.getNumero() == numero) {
				System.out.println("Saldo disponível: R$ "+conta.getSaldo());
			}
		}
	}
	
	public void realizarSaque(int numero,float valor) {
		for(Conta conta : contas) {
			if(conta.getNumero() == numero) {
				if(conta.getSaldo()-valor<0)
					System.out.println("Saldo insuficiente");
				else {
					conta.setSaldo(conta.getSaldo()-valor);
					System.out.println("Saque realizado com sucesso.");
				}
			}
			else
				System.out.println("Conta não localizada.");
		}
	}
	
	
	
	
}
