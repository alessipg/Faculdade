package lista01;

public class AlunoTeste {
	public static void main(String[] args) {
		Pessoa pessoa1 = new Pessoa("Gabriel Antonio", "31/12/2001", 123, 321);
		pessoa1.imprimirDados();
		System.out.println("============");
		Aluno aluno1 = new Aluno("Antonio Gabriel","01/01/2001", 321, 123, 666);
		aluno1.imprimirDados();
		System.out.println("============");
		Aluno aluno2 = new Aluno("Antonio Ga","01/011", 1, 13, 66);
		aluno2.imprimirDados();
		System.out.println("============");
		aluno1.imprimirDados();
		
		
	}

}
