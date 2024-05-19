package aula08;

public class Comparativos {
	public static void main(String[] args) {
		
		int x = 5;
		
		boolean cond1 = x > 5;
		boolean cond2 = x > 3;
		boolean cond3 = x < 5;
		boolean cond4 = x < 8;
		boolean cond5 = x >= 5;
		boolean cond6 = x <= 5;
		boolean cond7 = x != 5;
		boolean cond8 = x == 5;
		
		System.out.println("x > 5: " + cond1);	
		System.out.println("x > 3: " + cond2);
		System.out.println("x < 5: " + cond3);
		System.out.println("x < 8: " + cond4);
		System.out.println("x >= 5: " + cond5);
		System.out.println("x <= 5: " + cond6);
		System.out.println("x != 5: " + cond7);
		System.out.println("x == 5: " + cond8);
		
	}
}
