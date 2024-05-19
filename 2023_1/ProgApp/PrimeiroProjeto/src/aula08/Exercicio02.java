package aula08;

import java.util.Scanner;
public class Exercicio02 {
	public static void main(String[] args) {
		
		Scanner in = new Scanner(System.in);
		
		System.out.println("Valor da compra: ");
		double compra = in.nextDouble();
		double resultado = (compra >= 50) ? compra-compra*0.1 : compra-compra*0.05 ;
		System.out.printf("Valor com desconto: R$%.2f",resultado);
		in.close();
	}
}