package aula_2_3_1;

public class Carro {
	String modelo;
	String marca;
	int ano;
	String placa;
	String cor;
	boolean ligado = false;
	int velocidade = 0;
	
	public Carro(String modelo, String marca, int ano, String placa, String cor) {
		
		this.modelo = modelo;
		this.marca = marca;
		this.ano = ano;
		this.placa = placa;
		this.cor = cor;
	}
	
	public void ligar() {
	ligado = true;
	System.out.println(modelo + " está ligado");
	}
	public void desligar() {
	ligado = false;
	System.out.println(modelo + " está desligado");
	}
	public void acelerar() {
	velocidade += 20;
	System.out.println(modelo + " está a " + velocidade + "km/h");
	}
	public void frear() {
	velocidade -=20;
	System.out.println(modelo + " está a " + velocidade + "km/h");
	}
	public String toString() {
		return "Carro [modelo=" + modelo + ", marca=" + marca + ", ano=" + ano + ", placa=" + placa + ", cor=" + cor
				+ "]";
	}
	

}
