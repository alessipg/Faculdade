package lista01_1;

public class AlunoTeste {
	public static void main(String[] args) {
		Pessoa pessoa = new Pessoa("Gabriel","24/10/2001",123,321);
		pessoa.imprimePessoa();
		System.out.println("===============================");
		Aluno aluno = new Aluno("José","01/01/2001",111,222,4321);
		aluno.imprimeAluno();
	}
}
