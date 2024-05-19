package lista02;

public class Imovel {	
	protected String end;
	protected float valor;
	public Imovel(float valor) {
		this.end = "Joaquim da Silva, 123, Centro, Ponta Grossa - PR, 84015-123";
		this.valor = valor+150000;
	}
	public void imprimirDados() {
		
		System.out.println("Endereço: " + end);
		System.out.println("Valor: R$" + valor);
		
	}
	
}
