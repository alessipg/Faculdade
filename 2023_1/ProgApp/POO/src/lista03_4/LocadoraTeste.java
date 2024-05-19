package lista03_4;

public class LocadoraTeste {
	public static void main(String[] args) {
		Socio socio = new Socio("João", "01/01/2000", 123, "99999-9999", new Endereco("Rua 1", 2, "Bairro", "84400-000", "Ponta Grossa", "PR"));
		Filme filme = new Filme("O Senhor dos Aneis",180,10);
		filme.locarFilme(socio, 3);
		filme.devolverFilme(9);
		
	}
}
