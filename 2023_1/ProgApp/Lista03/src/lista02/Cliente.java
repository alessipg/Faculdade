package lista02;

public class Cliente {
	public String nome;
	public int cpf;
	public Conta conta;
	
	public Cliente(String nome, int cpf) {
		this.nome = nome;
		this.cpf = cpf;
		this.conta = new Conta();
	}
	
	
	public void solicitarPrato(int numero, String nome, Tipo tipo, String descricao, double preco) {
		conta.adicionarPrato(numero, nome, tipo, descricao, preco);
	}
	public void encerrarConta() {
		conta.fecharConta();
	}
	
}
