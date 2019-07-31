class  Node{
	public int data;
	public Node next;
	
	public Node(int data){
		this.data = data;
		next = null;
	}
} 

public class Queue extends Utility{
	private Node FRONT, REAR;	
	
	Queue(){
		FRONT = null;
		REAR = null;
	}
	
	public Node createNode(int num){
		return new Node(num);
	}
	
	public void add(){
		int num = 0;
		Node newNode = null;
		println("Enter number to push into stack");
		num = input.nextInt();
		
		newNode = createNode(num);
		if(FRONT == null){
			FRONT = REAR = newNode;
			println("First number added in queue");
		}else{
			REAR.next = newNode;
			REAR = newNode;
			println("Number added in queue");
		}
	}
	
	public void remove(){
		Node temp = FRONT;
		if(FRONT == null){
			println("QUEUE IS EMPTY!");
		}else{
			FRONT = FRONT.next;
			println(temp.data+" removed from queue");
			temp = null;
		}
	}
	
	public void printQueue(){
		Node temp = FRONT;
		if(FRONT == null){
			println("QUEUE IS EMPTY!");
		}else{
			while(temp != null){
				print(temp.data+" ");
				temp = temp.next;
			}
			println("");
		}
	}
	
	public static void main(String args[]){
		Queue queue = new Queue();	
		int choice;
		do{
			System.out.println("1. Add\n2. Remove\n3. Print\n0. Exit");
			choice = queue.input.nextInt();
			switch(choice){
				case 1:
					queue.add();
					break;
				case 2:
					queue.remove();
					break;
				case 3:
					queue.printQueue();
					break;
			}
		}while(choice != 0);
	}
}