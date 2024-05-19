package entities;

import java.util.ArrayList;
import java.util.List;

public class Cartao{
	private int numero;
	private double valorGasto;
	private Cliente cliente;
	private List<Compra> compras;
	private boolean bloqueado;
	
	public Cartao(int numero, Cliente cliente) {
		this.numero = numero;
		this.valorGasto = 0.0;
		this.cliente = cliente;
		this.bloqueado = false;
		this.compras = new ArrayList<>();
	}
	public double getValorGasto() {
		return valorGasto;
	}
	public void setValorGasto(float valorGasto) {
		this.valorGasto = valorGasto;
	}
	public Cliente getCliente() {
		return cliente;
	}
	public void setCliente(Cliente cliente) {
		this.cliente = cliente;
	}
	
	public void realizarCompra(int numero, String nome, double valor) {
		Compra compra = new Compra(nome, valor);
		compras.add(compra);
		valorGasto+= valor;
		
	}
	public void emitirExtrato(){
		for(Compra compra: compras) {
			System.out.println("Nome: "+compra.getNome());
			System.out.println("Valor: R$"+compra.getValor());
			System.out.println("---------------------------");
		}
		System.out.println("Valor da fatura: R$"+this.getValorGasto());
	}
	
}
