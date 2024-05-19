package aula07;

import java.util.Scanner;
public class ExercicioEntrada {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.println("Informe nome:");
		String nome = in.nextLine();
		System.out.println("Informe sexo:");
		String sexo = in.nextLine();
		System.out.println("Estado civil:");
		String civil = in.nextLine();
		System.out.println("Quantidade de filhos:");
		int filhos = in.nextInt();
		System.out.println("Escolaridade:");
		in.nextLine();
		String esc = in.nextLine();
		System.out.println("Renda Mensal:");
		double renda = in.nextDouble();
		System.out.println("----------------");
		
		System.out.println("Nome: "+ nome);
		System.out.println("Sexo: "+ sexo);
		System.out.println("Estado Civil: "+ civil);
		System.out.println("Quantidade de filhos: "+ filhos);
		System.out.println("Escolaridade: "+ esc);
		System.out.printf("Renda: R$%.2f",renda);
		in.close();
		
	}
}
