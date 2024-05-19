package lista03;

public class Processos {
	private int numero;
	private String dataCriacao;
	private String descricao;
	public Processos(int numero, String dataCriacao, String descricao) {
		this.numero = numero;
		this.dataCriacao = dataCriacao;
		this.descricao = descricao;
	}
	
	public void emitirProcessos() {
		System.out.println("Número: "+this.numero);
		System.out.println("Data de criação: "+this.dataCriacao);
		System.out.println("Descrição: "+this.descricao);
		System.out.println("======================================");
	}
	
	
}
