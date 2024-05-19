package aula07;

import java.util.Scanner;

public class EntradaDados {
	
	public static void main(String[] args) {
		Scanner entradaTeclado = new Scanner(System.in);
		
		System.out.println("Informe seu nome:");
		String nome = entradaTeclado.nextLine();
		System.out.println("Informe sua idade:");
		int idade = entradaTeclado.nextInt();
		System.out.println("Informe sua altura:");
		double altura = entradaTeclado.nextDouble();
		System.out.println("--------------------");
		
		System.out.println("Nome: "+nome);
		System.out.println("Idade: "+idade+" anos.");
		System.out.println("Altura: "+ altura + "m.");
		entradaTeclado.close();
	}

}
