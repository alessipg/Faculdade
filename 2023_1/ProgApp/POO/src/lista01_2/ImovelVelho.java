package lista01_2;

public class ImovelVelho extends Imovel {

	public ImovelVelho(String endereco, double valor) {
		super(endereco, valor-20000);
	}
	
	void imprimeImovelVelho() {
		System.out.println("Endereco: " + this.getEndereco());
		System.out.println("Valor: " + this.getValor());
	}

}
