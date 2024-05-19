package lista01_1;

public class Pessoa {
	private String nome;
	private String nascimento;
	private long rg;
	private long cpf;
	
	public Pessoa(String nome, String nascimento, long rg, long cpf) {
		this.nome = nome;
		this.nascimento = nascimento;
		this.rg = rg;
		this.cpf = cpf;
	}

	void imprimePessoa() {
		System.out.println("Nome:" + this.nome);
		System.out.println("Nascimento: " + this.nascimento);
		System.out.println("RG: " + this.rg);
		System.out.println("CPF: " + this.cpf);
	}

	public String getNome() {
		return nome;
	}

	public String getNascimento() {
		return nascimento;
	}

	public long getRg() {
		return rg;
	}

	public long getCpf() {
		return cpf;
	}
	
	
	
	
}
