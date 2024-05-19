package lista03;

public class IngressoVip extends Ingresso {
	private float valorAdicional;
	private String localizacao;
	public IngressoVip(float valor, String tipo, float valorAdicional, String localizacao) {
		super(valor, tipo);
		this.valorAdicional = valorAdicional;
		this.localizacao = localizacao;
	}
	private float calcularValorIngressoVip() {
		return (valor + valorAdicional);
	}
	public void imprimirDadosIngresso() {
		super.imprimirDadosIngresso();
		System.out.println("Valor do Vip: " + calcularValorIngressoVip());
	}

}
