package lista05;

public class Prestador extends Colaborador{
	protected double valorHora;
	protected String tipoServico;
	public Prestador(String nome, String endereco, String dataInicio) {
		super(nome, endereco, dataInicio);
		this.valorHora = valorHora;
		this.tipoServico = tipoServico;
	}
	@Override
	public String toString() {
		return "Prestador [valorHora=" + valorHora + ", tipoServico=" + tipoServico + "]";
	}
	
	
}
