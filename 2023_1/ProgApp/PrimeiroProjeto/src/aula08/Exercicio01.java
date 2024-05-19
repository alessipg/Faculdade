package aula08;

import java.util.Scanner;
public class Exercicio01 {
	public static void main(String[] args) {
		
		Scanner in = new Scanner(System.in);
		
		System.out.println("Insira o primeiro número: ");
		int n1 = in.nextInt();
		System.out.println("Insira o segundo número: ");
		int n2 = in.nextInt();
		System.out.println("Insira o segundo número: ");
		int n3 = in.nextInt();
		int aux;
		if(n1>n2)
			aux = n1;
		else
			aux = n2;
		if(aux<n3)
			aux=n3;
		System.out.println(aux);
		in.close();
	}
}
