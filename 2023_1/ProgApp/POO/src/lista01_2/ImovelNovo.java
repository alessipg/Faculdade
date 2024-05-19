package lista01_2;

public class ImovelNovo extends Imovel {

	public ImovelNovo(String endereco, double valor) {
		super(endereco, valor+20000);
	}
	
	void imprimeImovelNovo() {
		System.out.println("Endereco: " + this.getEndereco());
		System.out.println("Valor: " + this.getValor());
	}

}
