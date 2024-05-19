package lista03;

public class IngressoTeste {
	public static void main(String[] args) {
		IngressoNormal ingressoN = new IngressoNormal(50, "Normal");
		ingressoN.imprimirDadosIngresso();
		
		CamaroteInferior camaroteI = new CamaroteInferior(80, "Vip inferior", 30);
		camaroteI.imprimirDadosIngresso();
		
		CamaroteSuperior camaroteS = new CamaroteSuperior(100, "Vip superior", 50);
		camaroteS.imprimirDadosIngresso();
	}
}
