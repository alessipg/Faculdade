package exceptions;

public class Calculadora {
	
	public void dividir() throws NumeroNaoNaturalException {
		int i = -1;
		
		if(i<0) {
			throw new NumeroNaoNaturalException("Número não natural");
		}
	}
}
