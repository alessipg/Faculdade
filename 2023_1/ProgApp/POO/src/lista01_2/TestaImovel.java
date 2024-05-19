package lista01_2;

public class TestaImovel {
	public static void main(String[] args) {
		ImovelNovo imovelNovo = new ImovelNovo("Rua A", 300000);
		imovelNovo.imprimeImovelNovo();
		System.out.println("======================");
		ImovelVelho imovelVelho = new ImovelVelho("Rua B", 300000);
		imovelVelho.imprimeImovelVelho();
	}
}
