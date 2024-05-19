package lista01_1;

public class Aluno extends Pessoa {

	private int matricula;
	
	public Aluno(String nome, String nascimento, long rg, long cpf, int matricula) {
		super(nome, nascimento, rg, cpf);
		this.matricula = matricula;
	}
	
	void imprimeAluno() {
		System.out.println("Nome:" + this.getNome());
		System.out.println("Nascimento: " + this.getNascimento());
		System.out.println("RG: " + this.getRg());
		System.out.println("CPF: " + this.getCpf());
		System.out.println("Matrícula: " + this.matricula);
	}

}
