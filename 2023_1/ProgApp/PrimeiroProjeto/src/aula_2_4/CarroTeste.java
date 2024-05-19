package aula_2_4;

public class CarroTeste {

	public static void main(String[] args) {
		Carro carro1 = new Carro("Palio");
		carro1.acelerar(10);
		carro1.ligar();
		carro1.ligar();
		carro1.acelerar(10);
		carro1.acelerar(40);
		carro1.desligar();
		carro1.frear(30);
		carro1.frear(15);
		carro1.frear(20);
		carro1.frear(5);
		carro1.desligar();
		carro1.desligar();
		
	}
}
