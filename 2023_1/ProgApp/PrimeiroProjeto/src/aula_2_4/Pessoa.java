package aula_2_4;

public class Pessoa {
	String nome;
	final int cpf;
	String dataNascimento;
	int telefone;
	String email;
	String status;
	public Pessoa(String nome,int cpf,String dataNascimento, int telefone, String email, String status) {
		this.nome = nome;
		this.cpf = cpf;
		this.dataNascimento = dataNascimento;
		this.telefone = telefone;
		this.email = email;
		this.status = status;
	}
	@Override
	public String toString() {
		return "Pessoa [nome=" + nome + ", cpf=" + cpf + ", dataNascimento=" + dataNascimento + ", telefone=" + telefone
				+ ", email=" + email + ", status=" + status + "]";
	}
	
	
}
