package lista03;

public class IngressoNormal extends Ingresso{

	public IngressoNormal(float valor, String tipo) {
		super(valor, tipo);
	}
	public void imprimirDadosIngresso() {
		super.imprimirDadosIngresso();
		System.out.println("Valor do normal: " + valor);
	}
}
