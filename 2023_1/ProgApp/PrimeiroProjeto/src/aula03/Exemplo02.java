package aula03;

public class Exemplo02 {
	public static void main(String[] args) {
		System.out.print("Olá Mundo!");//print n quebra linha
		System.out.println("Saída de Dados em Java");
		
		String nome = "João da Silva";
		int idade = 30;
		double peso = 75.762;
		
		System.out.println(nome + " possui " + idade + " anos e " + peso + " Kg.");
		System.out.printf("%s possui %d anos e %.2f Kg.", nome, idade, peso);
	}

}
