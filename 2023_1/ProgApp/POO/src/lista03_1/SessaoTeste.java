package lista03_1;

public class SessaoTeste {
	public static void main(String[] args) {
		Sala sala = new Sala(1,60);
		Filme filme = new Filme("Besouro Azul",150);
		Sessao sessao = new Sessao("24/08/2023","22:00", sala,filme);
		
		System.out.println(sessao.getNumeroIngressos());
		sessao.venderIngressos(20);
		System.out.println(sessao.getNumeroIngressos());
		sessao.venderIngressos(80);
		sessao.venderIngressos(40);
		System.out.println(sessao.getNumeroIngressos());
		
	}
}
