package banco;

public class ContaTeste {
	public static void main(String[] args) {
		
		Banco banco1 = new Banco(1678, "NewBank");
		
		banco1.criarNovaConta(111, 123456, "João da silva");
		banco1.criarNovaConta(222, 21321, "Maria de oliveira");
		banco1.criarNovaConta(333, 213214, "Ricardo carvalho");
		
		ContaBancaria contaBancaria1 = new ContaBancaria(111, new Cliente(123456, "João da Silva"));
		
		banco1.realizarDeposito(111, 120);
		banco1.listarContas();
	
	}
}
