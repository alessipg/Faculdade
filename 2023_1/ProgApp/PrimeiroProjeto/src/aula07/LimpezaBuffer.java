package aula07;

import java.util.Scanner;

public class LimpezaBuffer{
	
	public static void main(String[] args) {
		
		Scanner entradaTeclado = new Scanner(System.in);
		
		System.out.println("Informe o Logradouro: ");
		String logradouro = entradaTeclado.nextLine();
		System.out.println("Informe o número da residência:");
		int numero = entradaTeclado.nextInt();
		System.out.println("Informe o Bairro: ");
		//Limpeza do buffer
		entradaTeclado.nextLine();
		String bairro = entradaTeclado.nextLine();
		System.out.println("Informe Telefone: ");
		int telefone = entradaTeclado.nextInt();
		System.out.println("---------------------");
		
		System.out.println("Logradouro: "+ logradouro);
		System.out.println("Número: "+ numero);
		System.out.println("Bairro: "+ bairro);
		System.out.println("Telefone: "+ telefone);
		entradaTeclado.close();
		
	}
}