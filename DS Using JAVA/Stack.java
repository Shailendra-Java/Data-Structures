import java.util.Scanner;

class  Node{
	public int data;
	public Node next;
}
public class Stack{
	private Node TOP;
	public Stack(){
		TOP = null;
	}
	
	public Node createNode(int num){
		Node temp = new Node();
		temp.data = num;
		temp.next = null;
		return temp;
	}
	
	public void push(){
		int num = 0;
		Scanner input = new Scanner(System.in);
		Node newNode = null;
		System.out.println("Enter number to push into stack");
		num = input.nextInt();
		
		newNode = createNode(num);
		if(TOP == null){
			TOP = newNode;
			System.out.println("First number pushed in stack");
		}else{
			newNode.next = TOP;
			TOP = newNode;
			System.out.println("Number pushed in stack");
		}
	}
	
	public void pop(){
		Node temp = TOP;
		if(TOP == null){
			System.out.println("STACK UNDERFLOW!");
		}else{
			System.out.println(TOP.data+" poped from stack");
			TOP = TOP.next;
			temp = null;
		}
	}
	
	public void printStack(){
		Node temp = TOP;
		if(TOP == null){
			System.out.println("STACK UNDERFLOW!");
		}else{
			for(Node node = TOP; node != null; node = node.next){
				System.out.println("| "+node.data+" |");
			}
			System.out.println("------");
		}
	}
	
	public static void main(String args[]){
		Stack stack = new Stack();
		Scanner input = new Scanner(System.in);		
		int choice;
		do{
			System.out.println("1. Push\n2. Pop\n3. Print\n0. Exit");
			choice = input.nextInt();
			switch(choice){
				case 1:
					stack.push();
					break;
				case 2:
					stack.pop();
					break;
				case 3:
					stack.printStack();
					break;
			}
		}while(choice != 0);
	}
}