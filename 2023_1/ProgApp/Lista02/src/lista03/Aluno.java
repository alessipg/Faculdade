package lista03;

public class Aluno {
	private String nome;
	private int ra;
	private double[] notas = new double[4];
	private double soma = 0;
	private double media = 0;
	public Aluno(String nome, int ra, double[] notas) {
		this.nome = nome;
		this.ra = ra;
		this.notas = notas;
	}
	public void calcularMedia() {
		for(double nota : notas) {
			soma += nota;
		}
		media = soma / notas.length;
		System.out.println("Media: " + this.media + ((this.media>=6)?". Aprovado.":". Reprovado."));
		
	}
	public int getRa() {
		return ra;
	}
	public double getMedia() {
		return media;
	}
	
	
	
}
