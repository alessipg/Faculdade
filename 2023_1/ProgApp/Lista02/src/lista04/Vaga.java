package lista04;

public class Vaga {
	private int vaga;
	private String placa;
	private int entrada;
	private int saida;
	
	public Vaga(int vaga, String placa, int entrada) {
		this.vaga = vaga;
		this.placa = placa;
		this.entrada = entrada;
	}

	public int getEntrada() {
		return entrada;
	}

	public int getSaida() {
		return saida;
	}

	public int getVaga() {
		return vaga;
	}

	public String getPlaca() {
		return placa;
	}

	public void setVaga(int vaga) {
		this.vaga = vaga;
	}

	public void setPlaca(String placa) {
		this.placa = placa;
	}

	public void setEntrada(int entrada) {
		this.entrada = entrada;
	}

	public void setSaida(int saida) {
		this.saida = saida;
	}



	
}
