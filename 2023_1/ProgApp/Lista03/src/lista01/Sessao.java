package lista01;

public class Sessao {
	
	private int data;
	private int hora;
	private int numeroIngressos;
	private Sala sala;
	private Filme filme;
	
	public Sessao(int data, int hora, Sala sala, Filme filme) {
		this.data = data;
		this.hora = hora;
		this.sala = sala;
		this.filme = filme;
		this.numeroIngressos = sala.getCapacidadePessoas();
	}
	
	public void venderIngresso() {
		
	}
	
	
	
	
	
}
