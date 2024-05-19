package lista01_3;

public class Ingresso {
	private double valor;
	private String tipo;

	public Ingresso(double valor, String tipo) {

		this.valor = valor;
		this.tipo = tipo;
	}
	
	void imprime() {
		System.out.println("Tipo: " + this.tipo);
		System.out.println("Valor: " + this.valor);
	}
	
}
