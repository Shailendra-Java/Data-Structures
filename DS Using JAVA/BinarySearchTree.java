class Node{
	public int data;
	public Node lChild;
	public Node rChild;
	
	public Node(int data){
		this.data = data;
		lChild = rChild = null;
	}
}

public class BinarySearchTree extends Utility{
	public Node ROOT;
	
	public BinarySearchTree(){
		ROOT = null;
	}
	
	public void addNode(){
		int data;
		Node newNode, curr = ROOT, parent = null;
		println("Enter number to add ");
		data = input.nextInt();
		newNode = new Node(data);
		
		if(ROOT == null){
			ROOT = newNode;
			println("Root added in tree");
		}else{
			while(curr != null){
				parent = curr;
				if(data < curr.data)
					curr = curr.lChild;
				else if(data > curr.data)
					curr = curr.rChild;
				else
					break;
			}
			if(data < parent.data){
				parent.lChild = newNode;
				println(data+" added as left child of "+parent.data);
			}
			else if(data > parent.data){
				parent.rChild = newNode;
				println(data+" added as right child of "+parent.data);
			}
			else
				err("Duplicates Not allowed");
		}
	}
	public void deleteNode(){
		Node curr = ROOT, parent = null;
		println("Enter node to delete");
		int data = input.nextInt();
		
		if(ROOT == null)
			err("SORRY!! no node in tree");
		else{
			while(curr != null && data != curr.data){
				parent = curr;
				if(data < curr.data)
					curr = curr.lChild;
				else if(data > curr.data)
					curr = curr.rChild;
				else
					break;
			}
			if(parent == null){
				if(curr.lChild == null && curr.rChild == null){
					ROOT = curr = null;
					println(data+" deleted from tree");
				}
				else if((curr.lChild == null && curr.rChild != null)
					|| (curr.lChild != null && curr.rChild == null)){
						deleteHavingOne(curr, parent, data);
					}
				else
					deleteHavingBoth(curr, parent, data);
			}else{
				if(curr.lChild == null && curr.rChild == null)					
					deleteLeafNode(curr, parent, data);
				else if((curr.lChild == null && curr.rChild != null)
					|| (curr.lChild != null && curr.rChild == null))
						deleteHavingOne(curr, parent, data);
				else
					deleteHavingBoth(curr, parent, data);
			}
		}
	}
	
	void deleteLeafNode(Node curr, Node parent, int data){
		if(parent.lChild != null && parent.lChild.data == data)
			parent.lChild = null;
		else if(parent.rChild != null && parent.rChild.data == data)
			parent.rChild = null;
		else{
			err(data+" is not there in tree");
			return;
		}
		curr = null;
		println(data+" deleted from tree");
	}
	
	void deleteHavingOne(Node curr, Node parent, int data){
		Node child;
		if(curr.lChild != null)
			child = curr.lChild;
		else
			child = curr.rChild;
		
		if(parent.rChild != null && parent.rChild.data == data)
			parent.rChild = child;
		else if(parent.lChild != null && parent.lChild.data == data)
			parent.lChild = child;
		else{
			err(data+" is not there in tree");
			return;
		}
		curr = null;
		println(data+" deleted from tree");
	}
	
	void deleteHavingBoth(Node curr, Node parent, int data){
		Node inorder_succ = curr.rChild;
		parent = curr;
		while(inorder_succ.lChild != null){
			parent = inorder_succ;
			inorder_succ = inorder_succ.lChild;
		}
		curr.data = inorder_succ.data;
		if(inorder_succ.lChild == null && inorder_succ.rChild == null)
			deleteLeafNode(inorder_succ, parent, inorder_succ.data);
		else
			deleteHavingOne(inorder_succ, parent, inorder_succ.data);
	}
	
	void inOrder(Node root){
		if(root == null)
			return;
		inOrder(root.lChild);
		print(root.data+", ");
		inOrder(root.rChild);
	}
	
	void preOrder(Node root){
		if(root == null)
			return;
		print(root.data+", ");
		preOrder(root.lChild);
		preOrder(root.rChild);
	}
	
	void postOrder(Node root){
		if(root == null)
			return;
		postOrder(root.lChild);
		postOrder(root.rChild);
		print(root.data+", ");
	}
	
	public void traverse(){
		Node curr = ROOT;
		if(ROOT == null)
			err("There is no node in tree");
		else{
			println("IN-Order Traversal");
			inOrder(curr);
			println("\nPRE-Order Traversal");
			preOrder(curr);
			println("\nPOST-Order Traversal");
			postOrder(curr);
			print("\n");
		}
	}
	
	public static void main(String args[]){
		int choice;
		BinarySearchTree bst = new BinarySearchTree();
		do{
			bst.println("1. Add Node\n2. Delete Node");
			bst.println("3. Traverse Tree\n0. Exit");
			choice = bst.input.nextInt();
			switch(choice){
				case 0:
					System.exit(0);
				case 1:
					bst.addNode();
					break;
				case 2:
					bst.deleteNode();
					break;
				case 3:
					bst.traverse();
					break;
				default:
					bst.err("Sorry try again!");
			}
		}while(true);
	}
}
