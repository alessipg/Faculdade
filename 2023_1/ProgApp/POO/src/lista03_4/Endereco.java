package lista03_4;

public class Endereco {
	private String logradouro;
	private int numero;
	private String bairro;
	private String cep;
	private String cidade;
	private String uf;
	
	
	public Endereco(String logradouro, int numero, String bairro, String cep, String cidade, String uf) {
		this.logradouro = logradouro;
		this.numero = numero;
		this.bairro = bairro;
		this.cep = cep;
		this.cidade = cidade;
		this.uf = uf;
	}
	
	public void imprimirEndereco() {
		System.out.println(this.logradouro + " - " + this.numero + " - " + this.bairro + " - " + this.cep + " - " + this.cidade + " - " + this.uf);
	}
	
	
}
