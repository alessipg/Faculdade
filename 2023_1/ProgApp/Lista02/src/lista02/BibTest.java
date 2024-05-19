package lista02;

public class BibTest {
	public static void main(String[] args) {
		Biblioteca b1 = new Biblioteca("Ponta Grossa");	
		b1.cadastrarLivro("Senhor dos aneis 1", "Tolkien", 1984, "Panini", 600);
		b1.cadastrarLivro("Senhor dos aneis 2", "Tolkien", 1987, "Panini", 620);
		b1.cadastrarLivro("Senhor dos aneis 3", "Tolkien", 1990, "Panini", 640);
		
		b1.checarDisponibilidade("Senhor dos aneis 1");
		b1.checarDisponibilidade("Senhor dos aneis 2");
		b1.checarDisponibilidade("Senhor dos aneis 3");
		
		b1.emprestarLivro("Senhor dos aneis 2", 2);
		b1.emprestarLivro("Senhor dos aneis 2", 3);
		b1.emprestarLivro("Senhor dos aneis 3", 6);
		
		b1.devolverLivro("Senhor dos aneis 2", 11);
		b1.devolverLivro("Senhor dos aneis 3", 9);
	}

	
	
}
