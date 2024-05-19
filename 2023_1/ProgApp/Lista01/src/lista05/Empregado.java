package lista05;

public class Empregado extends Funcionario {
	private int carteiraTrabalho;
	
	public Empregado(String nome, String endereco, String dataInicio, String funcao, double salario, int carteiraTrabalho) {
		super(nome, endereco, dataInicio, funcao, salario);
		this.carteiraTrabalho = carteiraTrabalho;
	}

	@Override
	public String toString() {
		return super.toString() + "Empregado [carteiraTrabalho=" + carteiraTrabalho + "]";
	}
	

}
