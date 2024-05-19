package lista02;

import java.util.ArrayList;
import java.util.List;

public class Biblioteca {
	private String campus;
	private List<Livro> livrosAcervo;
	public Biblioteca(String campus) {
		this.campus = campus;
		this.livrosAcervo = new ArrayList<Livro>();
	}
	public void cadastrarLivro(String titulo, String autor, int anoPublicacao, String editora, int numeroPaginas) {
		Livro livro1 = new Livro(titulo, autor, anoPublicacao, editora, numeroPaginas);
		this.livrosAcervo.add(livro1);
		System.out.println("Livro cadastrado com sucesso.");
		System.out.println("=============================");
	}
	public void checarDisponibilidade(String titulo) {
		for(Livro livro : livrosAcervo) {
			if(livro.getTitulo() == titulo) {
				livro.emitirDisponibilidade();
			}
		}
	}
	public void emprestarLivro(String titulo, int dia) {
		for(Livro livro : livrosAcervo) {
			if(livro.getTitulo() == titulo) {
				livro.realizarEmprestimo(dia);
			}
		}
	}
	public void devolverLivro(String titulo, int dia) {
		for(Livro livro : livrosAcervo) {
			if (livro.getTitulo() == titulo) {
				livro.realizarDevolucao(dia);
			}
		}
	}
	
	
}
