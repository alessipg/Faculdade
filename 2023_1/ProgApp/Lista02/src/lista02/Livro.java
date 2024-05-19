package lista02;

public class Livro {
	
	public String titulo;
	public String autor;
	public int anoPublicacao;
	public String editora;
	public int numeroPaginas;
	public boolean disponibilidade;
	public int dataEmprestimo;
	public int dataDevolucao;
	public double multa;
	
	public Livro(String titulo, String autor, int anoPublicacao, String editora, int numeroPaginas) {
		this.titulo = titulo;
		this.autor = autor;
		this.anoPublicacao = anoPublicacao;
		this.editora = editora;
		this.numeroPaginas = numeroPaginas;
		this.disponibilidade = true;
	}

	public String getTitulo() {
		return titulo;
	}
	public void emitirDisponibilidade() {
		System.out.println("Titulo: "+ this.titulo);
		System.out.println("Ano publicado: "+ this.anoPublicacao);
		System.out.println("Editora: "+ this.editora);
		System.out.println("Nº de páginas: "+ this.numeroPaginas);
		System.out.println("Disponibilidade: " + ((this.disponibilidade == true) ? "Livre" :"Emprestado" ));
		System.out.println("=============================");
	}
	public void realizarEmprestimo(int dia) {		
		if(this.disponibilidade == true) {
		this.dataEmprestimo = dia;
			this.disponibilidade = false;
			System.out.println("Livro emprestado com sucesso.");
			System.out.println("=============================");
		}
		else {
			System.out.println("Livro está em uso por outra pessoa.");
			System.out.println("===================================");	
		}
	}

	public void realizarDevolucao(int dia) {
		if(this.disponibilidade == false) {
		this.dataDevolucao = dia;
			this.disponibilidade = false;
			System.out.println("Livro devolvido com sucesso.");
			if((this.dataDevolucao - this.dataEmprestimo) <= 7) {
				System.out.println("Sem débitos a pagar.");
			}else {
				multa = ((this.dataDevolucao - this.dataEmprestimo)-7)*1.5;
				System.out.println("Valor da multa a pagar: R$"+multa);
			}
			System.out.println("=============================");
		}
		else {
			System.out.println("Livro já foi devolvido.");
			System.out.println("=============================");	
		}
		
	}
	
	
	
	
}
