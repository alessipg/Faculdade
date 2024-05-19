package polimorfismo;

public class MamiferoTest {
	public static void main(String[] args) {
		Mamifero mamifero = null;
		
		mamifero = new Gato("Alasca","Cinza");
		mamifero.emitirSom();
		mamifero.test();
	}
}
