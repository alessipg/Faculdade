package aula_2_2;

import java.util.Scanner;
public class Metodo {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		PessoaTeste pessoa1 = new PessoaTeste();
		System.out.println("Insira nome: ");
		pessoa1.nome = in.nextLine();
		System.out.println("Insira dade: ");
		pessoa1.idade = in.nextInt();
		System.out.println("Insira peso: ");
		pessoa1.peso = in.nextDouble();
		System.out.println("Relatório: ");
		System.out.println("Nome: " + pessoa1.nome);
		System.out.println("Idade: " + pessoa1.idade);
		System.out.println("Peso: " + pessoa1.peso);
		
		
		in.close();
	}

}
