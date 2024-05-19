package lista03_4;

public class Filme {

	private String titulo;
	private int duracao;
	private float preco;
	private DadosLocacao dados;
	private float valorDev;
	
	public Filme(String titulo, int duracao, float preco) {
		this.titulo = titulo;
		this.duracao = duracao;
		this.preco = preco;
		this.dados = new DadosLocacao();
	}
	
	public void locarFilme(Cliente cliente, int dia) {
		if(this.dados.isDisponivel()) {
			dados.setCliente(cliente);
			dados.setDiaLocacao(dia);
			dados.setDiaPrevDevolucao(dia+3);
			dados.setValor(this.preco);
			dados.setDisponivel(false);
			System.out.println("Filme locado com sucesso.");
		}
		else {
			System.out.println("Não foi possível locar o filme");
		}
	}
	
	public void devolverFilme(int dia) {
		if(!dados.isDisponivel()) {
			dados.setDisponivel(true);
			valorDev = this.preco+((dia-dados.getDiaPrevDevolucao())*2);
			System.out.println("Filme devolvido, valor a pagar: R$"+valorDev);
		}
		else {
			System.out.println("Filme não está locado");
		}
		
	}
	
	
}
