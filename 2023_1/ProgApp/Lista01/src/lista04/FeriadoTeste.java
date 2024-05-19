package lista04;

public class FeriadoTeste {
	public static void main(String[] args) {
		Feriado feriado = new Feriado();
		System.out.println(feriado.toString());
				
		Feriado feriado1 = new Feriado("Recesso");
		System.out.println(feriado1.toString());
		
		Feriado feriado2 = new Feriado(10,8,2023,"Hoje");
		System.out.println(feriado2.toString());
	}
}
