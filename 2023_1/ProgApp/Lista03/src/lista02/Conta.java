package lista02;

import java.util.ArrayList;
import java.util.List;

public class Conta {
	private List<Prato> prato;
	private double totalConta;
	
	
	public Conta() {
		this.totalConta = 0;
		this.prato = new ArrayList<Prato>();
	}
	
	
	public void adicionarPrato(int numero, String nome, Tipo tipo, String descricao, double preco){
		Prato p1 = new Prato(numero, nome, tipo, descricao, preco);
		this.prato.add(p1);
		System.out.println("Prato adicionado.");
		System.out.println("=================");
	}
	public void fecharConta() {
		for(Prato prato : prato) {
			prato.emitirPrato();
			this.totalConta += prato.getPreco();
		}
		System.out.println("Total: R$" + String.format("%.2f", (this.totalConta+(this.totalConta*0.1))));
	}
}
