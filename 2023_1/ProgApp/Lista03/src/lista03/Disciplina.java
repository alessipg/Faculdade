package lista03;

public class Disciplina {
	private int codigo;
	private String nome;
	private String ementa;
	private int cargaHoraria;
	
	public Disciplina(int codigo, String nome, String ementa, int cargaHoraria) {
		this.codigo = codigo;
		this.nome = nome;
		this.ementa = ementa;
		this.cargaHoraria = cargaHoraria;
	}
	
	public void emitirDisciplina() {
		System.out.println("Código: "+this.codigo);
		System.out.println("Nome: "+this.nome);
		System.out.println("Ementa: "+this.ementa);
		System.out.println("Carga horária: "+this.cargaHoraria+" horas.");
		System.out.println("=============================");
	}
	
	
}
