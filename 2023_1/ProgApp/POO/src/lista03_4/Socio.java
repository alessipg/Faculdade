package lista03_4;

public class Socio extends Cliente{
	
	private int cpf;
	private Dependente dependente;
	
	public Socio(String nome, String dataNasc,int cpf, String telefone, Endereco endereco) {
		super(nome, dataNasc, telefone, endereco);
		this.cpf = cpf;
	}
	
	
}
