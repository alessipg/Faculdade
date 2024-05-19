package aula_2_4;

public class Carro {
	String modelo;
	double velocidadeAtual = 0;
	boolean motor = false;

	public Carro(String modelo) {
		super();
		this.modelo = modelo;
	}
	
	public void ligar() {
		if(motor  == true)
			System.out.println("Carro já está ligado.");
		else {
			motor = true;
			System.out.println("Carro ligado.");
		}
	}
	public void desligar() {
		if(velocidadeAtual>0) {
			System.out.println("Carro não pode desligar em movimento.");
		}
		else if(motor  == false)
			System.out.println("Carro já está desligado.");
		else {
			motor = false;
			System.out.println("Carro desligado.");
		}
		
	}
	public void acelerar(double velocidade) {
		if(motor == false) {
			System.out.println("Ligue o motor primeiro");
			return;
		}
		velocidadeAtual += velocidade;
		System.out.println("Carro acelerou para "+velocidadeAtual+"km/h.");
	}
	public void frear(double velocidade) {
		velocidadeAtual -= velocidade;
		if(velocidadeAtual<0)
			velocidadeAtual = 0;
		System.out.println("Carro freou para "+velocidadeAtual+"km/h.");
	
	}

}
