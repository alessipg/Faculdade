package polimorfismo;

public abstract class Mamifero {
	protected String nome;
	protected String raca;

	public Mamifero(String nome, String raca) {

		this.nome = nome;
		this.raca = raca;
	}
	
	public abstract void emitirSom();
	
	public void test() {
		System.out.println("test");
	}
	
}
