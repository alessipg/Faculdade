package aula_2_6_2;

public class RelogioTeste {
	public static void main(String[] args) {
		Relogio relogio1 = new Relogio("Rolex",10,25);
		System.out.println("Marca: " + relogio1.marca);
		System.out.println("Hora: " + relogio1.hora);
		System.out.println("Minutos: " + relogio1.minutos);
		
		relogio1.setHora(75);
		relogio1.setMinutos(67);
		relogio1.setHora(0);
		relogio1.setMinutos(0);
		System.out.println(relogio1.getHora());
		System.out.println(relogio1.getMinutos());
		relogio1.setHora(24);
		relogio1.setMinutos(60);
		System.out.println(relogio1.getHora());
		System.out.println(relogio1.getMinutos());
		relogio1.setHora(6);
		relogio1.setMinutos(9);
		System.out.println(relogio1.getHora());
		System.out.println(relogio1.getMinutos());
		System.out.println(relogio1);
		
	}
}
