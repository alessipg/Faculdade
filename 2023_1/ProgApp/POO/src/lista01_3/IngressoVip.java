package lista01_3;

public class IngressoVip extends Ingresso {

	private String local;

	public IngressoVip(double valor, double adicional, String tipo, String local) {
		super(valor+adicional, tipo);
		this.local = local;
		
	}
	
	
}
