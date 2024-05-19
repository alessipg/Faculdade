package lista04;

public class Filme {
	
	private String titulo;
	private int duracao;
	private double preco;
	private int diaLocacao;
	private int diaDevolucao;
	private int devolucaoPrevista;
	public double valorLocacao;
	private double valorTotal;
	private double valorMulta;
	private String cliente;
	private boolean disponivel;
	
	public Filme(String titulo, int duracao, double preco) {
		this.titulo = titulo;
		this.duracao = duracao;
		this.preco = preco;
		this.disponivel = true;
	}
	
	public void locarFilme(String nome, int diaLocacao) throws FilmeIndisponivelException{
		if(this.disponivel == false) {
			throw new FilmeIndisponivelException("Filme indisponível");
		}else {
			this.disponivel = false;
			this.diaLocacao = diaLocacao;
			this.devolucaoPrevista = (diaLocacao+3);
			this.cliente = nome;
			this.valorLocacao = this.getPreco();
			System.out.println("Locação efetuada.");
			System.out.println("============================");
		}
		
	}
	
	public void devolverFilme(String nome, int diaDevolucao) throws FilmeNaoLocadoException {
		if(this.disponivel == true) {
			throw new FilmeNaoLocadoException("Filme não foi locado");
		}else {
			this.disponivel = true;
			if(diaDevolucao < this.devolucaoPrevista){
				this.valorMulta = 0;
			}else
				this.valorMulta = ((diaDevolucao - this.devolucaoPrevista)*2);
			this.valorTotal = this.valorLocacao+this.valorMulta;
			
			System.out.println("Título: "+ this.titulo);
			System.out.println("Nome do cliente: "+ this.cliente);
			System.out.println("Dia locação: "+ this.diaLocacao);
			System.out.println("Dia previsto devolução: "+ this.devolucaoPrevista);
			System.out.println("Dia real devolução: "+ diaDevolucao);
			System.out.println("Valor filme: "+ this.preco);
			System.out.println("Valor multa: "+ this.valorMulta);
			System.out.println("Valor total: "+ this.valorTotal);
			
			this.diaLocacao = 0;
			this.devolucaoPrevista = 0;
			this.cliente = null;
			this.valorLocacao = 0;
			

			System.out.println("Devolução efetuada com sucesso");
			System.out.println("==============================");
		}
	}

	public String getTitulo() {
		return titulo;
	}
	
	public double getPreco() {
		return preco;
	}
	
	
	
	
}
