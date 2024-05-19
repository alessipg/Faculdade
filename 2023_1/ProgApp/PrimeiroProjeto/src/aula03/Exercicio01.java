package aula03;

public class Exercicio01 {
	public static void main(String[] args) {
		String produto1, produto2;
		double precoProduto1, precoProduto2;
		produto1 = "Notebook";
		precoProduto1 = 3500.00;
		produto2 = "SSD";
		precoProduto2 = 250.00;
		
		System.out.println("Produtos:");
		System.out.printf("%s por apenas R$%.2f\n",produto1, precoProduto1);
		System.out.printf("%s por apenas R$%.2f",produto2, precoProduto2);
	}
}
