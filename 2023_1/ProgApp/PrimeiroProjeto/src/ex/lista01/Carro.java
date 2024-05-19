package ex.lista01;

public class Carro {
	String modelo;
	String marca;
	String cor;
	int ano;
	int renavam;
	String chassi;
	String placa;
	
	
	public Carro(String modelo, String marca, String cor, int ano, int renavam, String chassi, String placa) {
		super();
		this.modelo = modelo;
		this.marca = marca;
		this.cor = cor;
		this.ano = ano;
		this.renavam = renavam;
		this.chassi = chassi;
		this.placa = placa;
	}
	public void ligar() {
		
	}
	public void desligar() {
		
	}
	public void acelerar() {
		
	}
	public void frear() {
		
	}
	@Override
	public String toString() {
		return "Carro [modelo=" + modelo + ", marca=" + marca + ", cor=" + cor + ", ano=" + ano + ", renavam=" + renavam
				+ ", chassi=" + chassi + ", placa=" + placa + "]";
	}
	
	
}
