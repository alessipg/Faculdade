package banco;

public class Cliente {

	private String nome;
	private int cpf;
	
	public Cliente(int cpf, String nome) {
		// TODO Auto-generated constructor stub
		this.cpf = cpf;
		this.nome = nome;
	}
	
	public String getNome() {
		return nome;
	}
	
	public int getCpf() {
		return cpf;
	}
	
}
