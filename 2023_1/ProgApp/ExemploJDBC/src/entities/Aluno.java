package entities;

public class Aluno {

	private int registroAcademico;
	private String nome;
	private Curso curso;
	private int periodo;
	private double coeficiente;
	private String sexo;
	private String dataIngresso;
	
	public Aluno() {
		this.curso = new Curso();
	}
	
	/*
	 * public Aluno(int registroAcademico, String nome, String sexo, Curso curso,
	 * String dataIngresso, int periodo, double coeficiente) {
	 * this.registroAcademico = registroAcademico; this.nome = nome; this.sexo =
	 * sexo; this.curso = curso; this.dataIngresso = dataIngresso; this.periodo =
	 * periodo; this.coeficiente = coeficiente;
	 * 
	 * }
	 */
	public int getRegistroAcademico() {
		return registroAcademico;
	}

	public void setRegistroAcademico(int registroAcademico) {
		this.registroAcademico = registroAcademico;
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public Curso getCurso() {
		return curso;
	}

	public void setCurso(Curso curso) {
		this.curso = curso;
	}

	public int getPeriodo() {
		return periodo;
	}

	public void setPeriodo(int periodo) {
		this.periodo = periodo;
	}

	public double getCoeficiente() {
		return coeficiente;
	}

	public void setCoeficiente(double coeficiente) {
		this.coeficiente = coeficiente;
	}

	public String getSexo() {
		return sexo;
	}

	public void setSexo(String sexo) {
		this.sexo = sexo;
	}

	public String getDataIngresso() {
		return dataIngresso;
	}

	public void setDataIngresso(String dataIngresso) {
		this.dataIngresso = dataIngresso;
	}

	
	
	
	
	
}
