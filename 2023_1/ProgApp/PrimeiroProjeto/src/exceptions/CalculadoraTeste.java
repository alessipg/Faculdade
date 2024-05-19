package exceptions;

public class CalculadoraTeste {

	public static void main(String[] args) throws NumeroNaoNaturalException {
		Calculadora c1 = new Calculadora();
		
		System.out.println(8-(-9));
		try {
			c1.dividir();	
		}catch (NumeroNaoNaturalException nnne) {
			System.out.println(nnne.getMessage());
		}
		
		
	}
}
