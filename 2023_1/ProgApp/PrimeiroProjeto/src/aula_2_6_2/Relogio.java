package aula_2_6_2;

public class Relogio {
	final String marca;
	int hora;
	int minutos;
	public Relogio(String marca, int hora, int minutos) {
		super();
		this.marca = marca;
		this.hora = hora;
		this.minutos = minutos;
	}
	public String getMarca() {
		return marca;
	}
	public int getHora() {
		return hora;
	}
	public void setHora(int hora) {
		if(hora>=0 && hora < 24)
			this.hora = hora;
		else
			System.out.println("Hora inválida");
	}
	public int getMinutos() {
		return minutos;
	}
	public void setMinutos(int minutos) {
		if(minutos>=0 && minutos < 24)
			this.minutos = minutos;
		else
			System.out.println("Minutos inválidos");
	}
	@Override
	public String toString() {
		return "Relogio [marca=" + marca + ", hora=" + hora + ", minutos=" + minutos + "]";
	}
	
	
	
}
