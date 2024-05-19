package lista05;

public class Colaborador {
	protected String nome;
	protected String endereco;
	protected String dataInicio;
	public Colaborador(String nome, String endereco, String dataInicio) {
		this.nome = nome;
		this.endereco = endereco;
		this.dataInicio = dataInicio;
	}
	
	@Override
	public String toString() {
		return "Colaborador [nome=" + nome + ", endereco=" + endereco + ", dataInicio=" + dataInicio + "]";
	}
	
	
}
