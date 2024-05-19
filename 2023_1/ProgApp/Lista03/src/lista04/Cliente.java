package lista04;

public class Cliente {
	protected String nome;
	protected String dataNascimento;
	protected String fone;
	protected Endereco end;
	public Cliente(String nome, String dataNascimento, String fone, String logradouro,
			       int numero, String bairro, int cep, String cidade, String uF) {
		this.nome = nome;
		this.dataNascimento = dataNascimento;
		this.fone = fone;
		this.end = new Endereco(logradouro, numero, bairro, cep, cidade, uF);
	}
	
	
}
