package lista03;

public class FuncionarioTeste {
	public static void main(String[] args) {
		Professor p1 = new Professor(111, "Vinicius Camargo", "01/02/2007", 5000, Titulacao.MESTRE);
		p1.adicionarDisciplina(123, "POO", "Fundamentos de Orientada a objeto", 60);
		
		Tecnico t1 = new Tecnico(222, "Jose dos Santos", "01/03/2020", 3000, false);
		t1.adicionarProcesso(321, "25/10/2021", "Gerar relatório de gastos");
		
		t1.emitirDados();
		System.out.println("=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-==-=-=-=");
		p1.emitirDados();
	
	
	}
}
