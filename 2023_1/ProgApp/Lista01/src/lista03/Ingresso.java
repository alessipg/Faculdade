package lista03;

public class Ingresso {
	protected float valor;
	protected String tipo;
	
	
	public Ingresso(float valor, String tipo) {
		this.valor = valor;
		this.tipo = tipo;
	}

	public void imprimirDadosIngresso() {
		System.out.println("Tipo: " + tipo);
	}
}
