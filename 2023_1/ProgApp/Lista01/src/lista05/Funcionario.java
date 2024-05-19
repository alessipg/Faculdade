package lista05;

public class Funcionario extends Colaborador{

	protected String funcao;
	protected double salario;
	
	public Funcionario(String nome, String endereco, String dataInicio, String funcao, double salario) {
		super(nome, endereco, dataInicio);
		this.funcao = funcao;
		this.salario = salario;
	}
	@Override
	public String toString() {
		return super.toString() + ", Funcionario [funcao=" + funcao + ", salario=" + salario + "]";
	}
	
	
}
