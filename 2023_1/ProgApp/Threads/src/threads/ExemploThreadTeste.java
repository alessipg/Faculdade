package threads;

public class ExemploThreadTeste {
	public static void main(String[] args) throws InterruptedException {
		ExemploThread exThread1 = new ExemploThread("Thread 1", 400);
		Thread thread1 = new Thread(exThread1);
		ExemploThread exThread2 = new ExemploThread("Thread 2", 1000);
		Thread thread2 = new Thread(exThread2);
		exThread1.start();
		exThread2.start();	
		
		exThread1.join();
		exThread2.join();
		System.out.println("Todas as threads foram finalizadas");
	}
}
