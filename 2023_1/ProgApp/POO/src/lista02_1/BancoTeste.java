package lista02_1;

public class BancoTeste {
	public static void main(String[] args) {
		Banco banco = new Banco("Teste","123");
		Cliente cliente1 = new Cliente("José","111");
		banco.criarConta(123,cliente1);
		banco.realizarDeposito(123, 500);
		banco.consultarSaldo(123);
		banco.realizarSaque(123, 700);
		banco.consultarSaldo(123);
		banco.realizarSaque(123, 300);
		banco.consultarSaldo(123);
	}
}
