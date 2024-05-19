package lista01;

public class Pessoa {
	
	protected String nome;
	protected String nascimento;
	protected long rg;
	protected long cpf;
	
	public Pessoa(String nome, String nascimento, long rg, long cpf) {
		this.nome = nome;
		this.nascimento = nascimento;
		this.rg = rg;
		this.cpf = cpf;
	}

	

	public void imprimirDados() {

		System.out.println("Nome: " + nome);
		System.out.println("Nascimento: " + nascimento);
		System.out.println("RG: " + rg);
		System.out.println("CPF: " + cpf);
	
	}
	
	
	
	
}
