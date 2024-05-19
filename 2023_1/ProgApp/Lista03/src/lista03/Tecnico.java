package lista03;

import java.util.ArrayList;
import java.util.List;

public class Tecnico extends Funcionario {
	private boolean noturno;
	private double salario;
	private List<Processos> processo;
	
	public Tecnico(int registro, String nome, String dataAdmissao, double salarioBase, boolean noturno) {
		super(registro, nome, dataAdmissao, salarioBase);
		this.noturno = noturno;
		this.salario = this.calcularSalario();
		this.processo = new ArrayList<Processos>();
	}
	public void adicionarProcesso(int numero, String dataCriacao, String descricao) {
		Processos p1 = new Processos(numero, dataCriacao, descricao);
		this.processo.add(p1);
		System.out.println("Processo adicionado com sucesso.");
		System.out.println("================================");
	}
	public void emitirDados() {
		super.emitirDados();
		System.out.println("Salário: "+this.salario);
		System.out.println("===========================");
		for(Processos processo : processo) {
			processo.emitirProcessos();
		}
		
	}
	
	@Override
	public double calcularSalario() {
		double adicional=0;
		if(this.noturno == true)
			adicional = 1000;	
		this.salario = super.getSalarioBase()+adicional;
		
		return this.salario;	
	}
}
