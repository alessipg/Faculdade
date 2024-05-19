package lista02;

public class Prato {
	
	private int numero;
	private String nome;
	private Tipo tipo;
	private String descricaoIngredientes;
	private double preco;
	
	public Prato(int numero, String nome, Tipo tipo, String descricaoIngredientes, double preco) {
		this.numero = numero;
		this.nome = nome;
		this.tipo = tipo;
		this.descricaoIngredientes = descricaoIngredientes;
		this.preco = preco;
	}
	
	public void emitirPrato() {
		System.out.println("Número: " + this.numero);
		System.out.println("Nome: " + this.nome);
		System.out.println("Tipo: " + this.tipo);
		System.out.println("Descrição: "+ this.descricaoIngredientes);
		System.out.println("Valor: R$"+String.format("%.2f", this.preco));
		System.out.println("===================");
	}
	public double getPreco() {
		return preco;
	}
	
	
}
