package lista02;

public class ImovelTeste {
	public static void main(String[] args) {
		ImovelNovo imovelnovo = new ImovelNovo();
		imovelnovo.imprimirDados();
		System.out.println("====================");
		ImovelVelho imovelvelho = new ImovelVelho();
		imovelvelho.imprimirDados();
	}
}
