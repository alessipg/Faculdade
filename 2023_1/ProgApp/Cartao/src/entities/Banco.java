package entities;

public class Banco {
	public static void main(String[] args) {
		Cartao c1 = new Cartao(123, new Cliente("José",123));
		c1.realizarCompra(123, "Café", 15.49);
		c1.realizarCompra(123, "Pão", 4.99);
		c1.emitirExtrato();
	}
}
