package lista04;

public class Socio extends Cliente {
	
	private int cpf;
	private Dependente dependente;
	private boolean temDependente;
	
	public Socio(String nome, String dataNascimento, String fone, int cpf, String logradouro, int numero, String bairro, int cep,
			String cidade, String uF) {
		super(nome, dataNascimento, fone, logradouro, numero, bairro, cep, cidade, uF);
		this.cpf = cpf;
	}
	
	public void criarDependente(String nome, String dataNascimento, String fone, String logradouro, int numero, String bairro,
			int cep, String cidade, String uF) {
		this.dependente = new Dependente(nome, dataNascimento, fone, logradouro, numero, bairro, cep, cidade, uF);
		this.temDependente = true;
		System.out.println("Dependente criado e vinculado ao Sócio: "+this.nome);
		System.out.println("===============================================================");
	}
	
	public int getCpf() {
		return cpf;
	}
	
	

	
	
	
}
