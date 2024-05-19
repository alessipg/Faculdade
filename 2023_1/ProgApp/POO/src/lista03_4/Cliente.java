package lista03_4;

public class Cliente {
	
	private String nome;
	private String dataNasc;
	private String telefone;
	private Endereco endereco;
	
	
	public Cliente(String nome, String dataNasc, String telefone, Endereco endereco) {
		this.nome = nome;
		this.dataNasc = dataNasc;
		this.telefone = telefone;
		this.endereco = endereco;
	}


	public String getNome() {
		return nome;
	}


	public String getDataNasc() {
		return dataNasc;
	}


	public String getTelefone() {
		return telefone;
	}


	public Endereco getEndereco() {
		return endereco;
	}
	
	
	
	
}
