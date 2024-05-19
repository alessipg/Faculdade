package aula04;

public class Bhaskara {
	public static void main(String[] args) {
		double a = 1;
		double b = 2;
		double c = -15;
		double delta = b*b-4*a*c;
		double result1 = (-b+Math.sqrt(delta))/2*a;
		double result2 = (-b-Math.sqrt(delta))/2*a;
		System.out.println("R = {"+result1+","+result2+"}");
	}
}
