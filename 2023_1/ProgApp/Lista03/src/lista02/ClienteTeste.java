package lista02;

public class ClienteTeste {
	public static void main(String[] args) {
		Cliente c1 = new Cliente("Gabriel", 123);
		
		c1.solicitarPrato(1, "PF", Tipo.PRINCIPAL, "Arroz, Feijão, Bife acebolado", 15);
		c1.solicitarPrato(2, "Torradas", Tipo.ENTRADA, "Pão torrado com manteiga", 9);
		c1.solicitarPrato(3, "Sagu", Tipo.SOBREMESA, "Sagu de vinho com leite", 6);
		
		c1.encerrarConta();
	}
}
