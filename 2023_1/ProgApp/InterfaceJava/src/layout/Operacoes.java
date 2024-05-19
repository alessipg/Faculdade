package layout;

public class Operacoes {
	float aux;
	static float[] memoria = new float[1];
	static float[] funcaoMemoria = new float[1];
	public Operacoes() {
		
	}
	
	public static float somar(float valor) {
		memoria[0] += valor;
		return memoria[0];
	}
	
	public static float igual(int sinal, float visor) {
		System.out.println("igual");
		switch(sinal) {
		case 0:
			return 0;
		case 1:
			return memoria[0]+visor;
		case 2:
			return memoria[0]-visor;
		case 3:
			System.out.println(memoria[0]*visor);
			return memoria[0]*visor;
		case 4:
			return memoria[0]/visor;
		
			
		}
		return memoria[0];
	}

	public static void limpar() {
		// TODO Auto-generated method stub
		System.out.println(memoria[0]);
		memoria[0]=0;
	}

	public static float subtrair(float valor) {
		// TODO Auto-generated method stub
		if(memoria[0]==0)
		memoria[0] = valor;
		else
		memoria[0] -= valor;
		return memoria[0];
	}

	public static float multiplicar(float valor) {
		// TODO Auto-generated method stub
		if(memoria[0]==0)
		memoria[0] = valor;
		else
		memoria[0] *= valor;
		System.out.println(memoria[0]);
		return memoria[0];
	}

	public static float dividir(float valor) {
		// TODO Auto-generated method stub
		if(memoria[0]==0)
		memoria[0] = valor;
		else
		memoria[0] /= valor;
		return memoria[0];
	}

	public static void armazenar(float valor) {
		funcaoMemoria[0] = valor;
		System.out.println(funcaoMemoria[0]);
	}

	public static String recuperar() {
		// TODO Auto-generated method stub
		return  ""+funcaoMemoria[0];
	}

	public static void limparMem() {
		// TODO Auto-generated method stub
		funcaoMemoria[0]=0;
	}
	
	
	
	
}
