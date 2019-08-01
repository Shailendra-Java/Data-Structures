import java.util.Scanner;

public class Utility{
	protected Scanner input = new Scanner(System.in);
	public void print(Object object){
		System.out.print(object);
	}
	
	public void println(Object object){
		System.out.println(object);
	}
	
	public void err(Object object){
		System.err.println(object);
	}
}
