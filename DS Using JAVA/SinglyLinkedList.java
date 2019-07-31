class  Node{
	public int data;
	public Node next;
	
	public Node(int data){
		this.data = data;
		next = null;
	}
} 

public class SinglyLinkedList extends Utility{
	private Node START, LAST;
	
	public SinglyLinkedList(){
		START = LAST = null;
	}
	
	// Insertion in list
	public void insertNode(){
		int data;
		Node curr = START, prev = null;
		println("Enter number to insert");
		data = input.nextInt();
		Node newNode = new Node(data);
		if(START == null){
			START = LAST = newNode;
			println("First node added in list");
		}else{
			while(curr != null && data > curr.data){
				prev = curr;
				curr = curr.next;
			}// inserting node at beginning
			if(prev == null){
				newNode.next = START;
				START = newNode;
				println(data+" inserted at beginning");
			}//inserting node at last
			else if(prev.next == null){
				prev.next = newNode;
				LAST = newNode;
				println(data+" inserted at last");
			}// inserting at their currect position
			else{
				prev.next = newNode;
				newNode.next = curr;
				println(data+" inserted between "+prev.data+" and "+curr.data);
			}
		}
	}
	
	public void deleteNode(){
		Node curr = START, prev = null;
		int data;
		println("Enter number to delete");
		data = input.nextInt();
		if(START == null){
			println("SORRY LIST IS EMPTY!");
		}else{
			while(curr != null && data != curr.data){
				prev = curr;
				curr = curr.next;
			}// deleting node from beginning
			if(prev == null){
				START = START.next;
				println(curr.data+" deleted from beginning");
				curr = null;
			}else if(curr == null){
				println("SORRY!!! "+data+" not in list");
			}
			// deleting node from last
			else if(curr.next == null){
				LAST = prev;
				LAST.next = null;
				println(curr.data+" deleted from last");
				curr = null;
			}// deleting from their currect position
			else{
				prev.next = curr.next;
				println(data+" deleted between "+prev.data+" and "+curr.next.data);
				curr = null;
			}
		}
	}
	
	// Traversing list
	public void printList(){
		Node curr = START;
		if(START == null){
			println("SORRY LIST IS EMPTY!");
		}else{
			while(curr != null){
				print(curr.data+"->");
				curr = curr.next;
			}
			println(null);
		}
	}
	
	public static void main(String args[]){
		SinglyLinkedList list = new SinglyLinkedList();	
		int choice;
		do{
			System.out.println("1. Add\n2. Remove\n3. Print\n0. Exit");
			choice = list.input.nextInt();
			switch(choice){
				case 1:
					list.insertNode();
					break;
				case 2:
					list.deleteNode();
					break;
				case 3:
					list.printList();
					break;
			}
		}while(choice != 0);
	}
}