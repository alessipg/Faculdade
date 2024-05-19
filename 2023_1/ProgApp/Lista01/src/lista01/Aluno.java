package lista01;

public class Aluno extends Pessoa{
	private int matricula;
	public Aluno(String nome, String nascimento, long rg, long cpf, int matricula) {
		super(nome, nascimento, rg, cpf);
		this.matricula = matricula;
	}
	
	public void imprimirDados(){
		super.imprimirDados();
		System.out.println("Matrícula: "+ matricula);
	}
}
