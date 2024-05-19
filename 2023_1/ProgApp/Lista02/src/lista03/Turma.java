package lista03;

import java.util.ArrayList;
import java.util.List;

public class Turma {
	private String professor;
	private String materia;
	private List<Aluno> listaAlunos;
	private double soma = 0;
	private double media;
	public Turma(String professor, String materia) {
		this.professor = professor;
		this.materia = materia;
		this.listaAlunos = new ArrayList<Aluno>();
	}
	
	public void adicionarAluno(String nome, int ra, double[] notas) {
		Aluno a1 = new Aluno(nome, ra, notas);
		this.listaAlunos.add(a1);
		System.out.println("Aluno cadastrado com sucesso.");
		System.out.println("=============================");
		
	}
	public void mediaAluno(int ra) {
		for(Aluno aluno : listaAlunos) {
			if(aluno.getRa() == ra) {
				aluno.calcularMedia();
			}
		}
	}
	public void mediaTurma() {
		for(Aluno aluno : listaAlunos) {
			soma += aluno.getMedia();
		}
			media = soma / listaAlunos.size();
			System.out.println("Média da turma: " + this.media);
	}
	
	
}
