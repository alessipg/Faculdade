package lista02;

public enum Tipo {
	ENTRADA("Entrada"),
	PRINCIPAL("Principal"),
	SOBREMESA("Sobremesa");
	private String tipo;

	private Tipo(String tipo) {
		this.tipo = tipo;
	}

	public String getTipo() {
		return tipo;
	}
	
	
}
