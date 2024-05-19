package aula08;

import java.util.Scanner;

public class Ternario {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		System.out.println("Insira um inteiro: ");
		int x = in.nextInt();
		//variável x = (expressão) ? valor se verdadeiro : valor se falso;
		                                  //true    false
		String resultado = (x % 2 == 0) ? "Par" : "Ímpar" ;
		
		System.out.println(resultado);
		in.close();
	}
}
