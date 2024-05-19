package lista03;

public abstract class Funcionario {
	private int registro;
	private String nome;
	private String dataAdmissao;
	private double salarioBase;
	
	public Funcionario(int registro, String nome, String dataAdmissao, double salarioBase) {
		this.registro = registro;
		this.nome = nome;
		this.dataAdmissao = dataAdmissao;
		this.salarioBase = salarioBase;
	}
	
	public abstract double calcularSalario();

	public void emitirDados() {
		System.out.println("Registro: "+this.registro);
		System.out.println("Nome: "+this.nome);
		System.out.println("Data de admissão: "+this.dataAdmissao);
	}

	public double getSalarioBase() {
		return salarioBase;
	}

	
}
