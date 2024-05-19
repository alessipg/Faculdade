package aula_2_3_1;

public class PessoaTeste {
	public static void main(String[] args) {
		
		Pessoa pessoa1 = new Pessoa("João da Silva",30);
		
		System.out.println("Nome: " + pessoa1.nome);
		System.out.println("Idade: " + pessoa1.idade);
		
		Pessoa pessoa2 = new Pessoa("Maria Oliveira",35);
		
		System.out.println("Nome: " + pessoa2.nome);
		System.out.println("Idade: " + pessoa2.idade);
	}
}
