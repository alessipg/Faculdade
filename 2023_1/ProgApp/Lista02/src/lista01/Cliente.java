package lista01;

public class Cliente {
	
	private String nome;
	private int cpf;
	
	public Cliente(int cpf, String nome) {
		this.nome = nome;
		this.cpf = cpf;
	}
	
	public String getNome() {
		return nome;
	}
	
	public int getCpf() {
		return cpf;
	}
	
}
