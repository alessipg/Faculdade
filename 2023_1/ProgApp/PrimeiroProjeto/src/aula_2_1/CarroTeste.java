package aula_2_1;

import java.util.Scanner;

public class CarroTeste {
	public static void main(String[] args) {
		
		Scanner in = new Scanner(System.in);
		
		Carro carro1 = new Carro();
		
		System.out.println("Informe o modelo do carro1: ");
		carro1.modelo = in.nextLine();
		
		System.out.println("Informe a marca do carro1: ");
		carro1.marca = in.nextLine();
		
		System.out.println("Informe o ano do carro1: ");
		carro1.ano = in.nextInt();
		
		System.out.println("Informe a placa do carro1: ");
		in.nextLine();
		carro1.placa = in.nextLine();
		
		System.out.println("Informe a cor do carro1: ");
		carro1.cor = in.nextLine();
		
		/*System.out.println("Relatório do carro1");
		System.out.println("Modelo: " + carro1.modelo);
		System.out.println("Marca: " + carro1.marca);
		System.out.println("Ano: " + carro1.ano);
		System.out.println("Placa: " + carro1.placa);
		System.out.println("Cor: " + carro1.cor);*/
		//substituindo por toString
		
		System.out.println(carro1);
		
	
		carro1.ligar();
		carro1.acelerar();
		carro1.frear();
		carro1.desligar();
		
		in.close();
	}
}
