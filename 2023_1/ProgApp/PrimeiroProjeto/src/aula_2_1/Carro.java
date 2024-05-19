package aula_2_1;

public class Carro {
	String modelo;
	String marca;
	int ano;
	String placa;
	String cor;
	
	public void ligar() {
		System.out.println(modelo + " está ligando.");
	}
	public void desligar() {
		System.out.println(modelo + " está desligando.");		
	}
	public void acelerar() {
		System.out.println(modelo + " está acelerando.");
	}
	public void frear() {
		System.out.println(modelo + " está freando.");
	}
	public String toString() {
		return "Modelo: " + modelo + "\n"
			+ "Marca: " + marca + "\n"
			+ "Ano: " + ano + "\n"
			+ "Placa: " + placa + "\n"
			+ "Cor: " + cor;
	}
}
