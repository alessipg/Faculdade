package lista03_4;

public class DadosLocacao {
	private boolean disponivel;
	private int diaLocacao;
	private int diaPrevDevolucao;
	private int diaDev;
	private float valor;
	
	public DadosLocacao() {
		this.disponivel = true;
	}
	public float getValor() {
		return valor;
	}

	public void setValor(float valor) {
		this.valor = valor;
	}

	private Cliente cliente;
	

	public boolean isDisponivel() {
		return disponivel;
	}

	public void setDisponivel(boolean disponivel) {
		this.disponivel = disponivel;
	}

	public int getDiaLocacao() {
		return diaLocacao;
	}

	public void setDiaLocacao(int diaLocacao) {
		this.diaLocacao = diaLocacao;
	}

	public int getDiaPrevDevolucao() {
		return diaPrevDevolucao;
	}

	public void setDiaPrevDevolucao(int diaPrevDevolucao) {
		this.diaPrevDevolucao = diaPrevDevolucao;
	}

	public int getDiaDev() {
		return diaDev;
	}

	public void setDiaDev(int diaDev) {
		this.diaDev = diaDev;
	}

	public Cliente getCliente() {
		return cliente;
	}

	public void setCliente(Cliente cliente) {
		this.cliente = cliente;
	}
	
	
	
	
	
}
