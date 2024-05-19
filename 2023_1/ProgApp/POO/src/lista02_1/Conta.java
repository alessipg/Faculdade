package lista02_1;

public class Conta {
	private int numero;
	private float saldo;
	private Cliente titular;
	
	
	
	public Conta(int numero, Cliente titular) {
		this.numero = numero;
		this.saldo = 0;
		this.titular = titular;
	}
	public int getNumero() {
		return numero;
	}
	public void setNumero(int numero) {
		this.numero = numero;
	}
	public float getSaldo() {
		return saldo;
	}
	public void setSaldo(float saldo) {
		this.saldo = saldo;
	}
	
	
}
