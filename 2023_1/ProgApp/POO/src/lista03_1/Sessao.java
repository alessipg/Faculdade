package lista03_1;

public class Sessao {

	private String data;
	private String hora;
	private int numeroIngressos;
	private Sala sala;
	private Filme filme;
	
	
	public Sessao(String data, String hora, Sala sala, Filme filme) {
		this.data = data;
		this.hora = hora;
		this.numeroIngressos = sala.getCapacidadeMax();
		this.sala = sala;
		this.filme = filme;
	}
	
	public void venderIngressos(int qtd) {
		if(this.getNumeroIngressos()>=qtd) {
			this.setNumeroIngressos(this.getNumeroIngressos()-qtd);
			System.out.println("Venda realizada com sucesso.");
		} else
			System.out.println("Quantidade de ingressos insuficiente.");
	}

	public void setNumeroIngressos(int numeroIngressos) {
		this.numeroIngressos = numeroIngressos;
	}

	public String getData() {
		return data;
	}

	public String getHora() {
		return hora;
	}

	public int getNumeroIngressos() {
		return numeroIngressos;
	}

	public Sala getSala() {
		return sala;
	}

	public Filme getFilme() {
		return filme;
	}
	
	
	
	
}
