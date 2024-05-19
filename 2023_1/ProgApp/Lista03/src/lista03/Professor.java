package lista03;

import java.util.ArrayList;
import java.util.List;

public class Professor extends Funcionario {

	private Titulacao titulacao;
	private double salario;
	private List<Disciplina> disc;

	public Professor(int registro, String nome, String dataAdmissao, double salarioBase, Titulacao titulacao) {
		super(registro, nome, dataAdmissao, salarioBase);
		this.titulacao = titulacao;
		this.disc = new ArrayList<Disciplina>();
		this.salario = this.calcularSalario();
	}
	
	public void adicionarDisciplina(int codigo, String nome, String ementa, int cargaHoraria) {
		Disciplina d1 = new Disciplina(codigo, nome, ementa, cargaHoraria);
		this.disc.add(d1);
		System.out.println("Disciplina adicionada com sucesso.");
		System.out.println("==================================");
	}
	
	public void emitirDados() {
		super.emitirDados();
		System.out.println("Salário: "+this.salario);
		System.out.println("============================");
		for(Disciplina disc : disc) {
			disc.emitirDisciplina();
		}
	}

	@Override
	public double calcularSalario() {
		double gratificacao;
		if(this.titulacao == Titulacao.MESTRE)
			gratificacao = 1000;
		else
			gratificacao = 2000;
			
		this.salario = super.getSalarioBase()+gratificacao;
		
		return this.salario;	
	}
	

	

	
}
