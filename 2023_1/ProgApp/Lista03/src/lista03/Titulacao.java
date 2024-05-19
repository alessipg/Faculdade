package lista03;

public enum Titulacao {
	
	MESTRE("Mestre"),
	DOUTOR("Doutor");
	private String titulacao;

	public Titulacao (String titulacao) {
		this.titulacao = titulacao;
	}

	public String getTitulacao() {
		return titulacao;
	}
	
}
