package lista03;

public class TurmaTeste {
	public static void main(String[] args) {
		Turma turma = new Turma("Vinicius", "POO");
		
		double[] notas1 = {6.0, 6.0, 5.9, 6.0};
		turma.adicionarAluno("Fulano", 111, notas1);
		
		double[] notas2 = {5.0, 7.5, 6.0, 6.5};
		turma.adicionarAluno("Ciclano", 222, notas2);
		
		double[] notas3 = {8.0, 7.0, 9.0, 6.5};
		turma.adicionarAluno("Beltrano", 333, notas3);
		
		double[] notas4 = {4.0, 5.5, 3.0, 6.0};
		turma.adicionarAluno("João", 444, notas4);
		
		double[] notas5 = {6.5, 7.0, 8.5, 7.0};
		turma.adicionarAluno("Maria", 555, notas5);
		
		turma.mediaAluno(111);
		turma.mediaAluno(222);
		turma.mediaAluno(333);
		turma.mediaAluno(444);
		turma.mediaAluno(555);
		
		turma.mediaTurma();
		
	}
	
	
}
