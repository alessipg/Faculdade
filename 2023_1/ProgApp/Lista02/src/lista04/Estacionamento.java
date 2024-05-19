package lista04;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class Estacionamento {
	private static List<Vaga> vagas;
	
	public static void estacionar(String placa, int entrada) {
		Random gen = new Random();
		vagas = new ArrayList<Vaga>();
		Vaga vaga = new Vaga(gen.nextInt(51),placa, entrada);
		vagas.add(vaga);
		System.out.println("Veiculo estacionado na vaga " + vaga.getVaga());
	}
	
	public static void liberar(String placa, int saida) {
		for(Vaga vaga : vagas) {
			if(vaga.getPlaca() == placa) {
				vaga.setSaida(saida);
				System.out.println(vaga.getSaida() +" - " + vaga.getEntrada());
				double valor = 0.5*(vaga.getSaida()-vaga.getEntrada());
				vaga.setPlaca(null);
				System.out.println("Vaga "+ vaga.getVaga() +" livre, foi pago "+valor);
			}
		}
	}
}
