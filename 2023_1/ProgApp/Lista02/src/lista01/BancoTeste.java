package lista01;

public class BancoTeste {
	public static void main(String[] args) {
		Banco b1 = new Banco(123, "Newbank");
		
		b1.criarNovaConta(111, 1234, "Gabriel Antonio");
		b1.criarNovaConta(222, 5678, "Theodoro Ubeda");
		b1.criarNovaConta(333, 21312, "Gabriel Gurjão");
		
		b1.realizarDepositoConta(222, 500);
		b1.listarContas();
		
		b1.realizarSaqueConta(222, 130.00);
		b1.listarContas();
		
		b1.removerConta(333);
		b1.listarContas();
	}
}
