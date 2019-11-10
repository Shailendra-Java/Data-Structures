#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;
};

class BinaryTree{
    public:
        Node *root, *current, *parent;

    BinaryTree(){
        root = current = parent = NULL;
    }

    Node* createNode(int num){
        Node *temp = new Node;
        temp->data = num;
        temp->left = NULL;
        temp->right = NULL;

        return temp;
    }

    void insertNode(){
        Node *ptr;
        int num;
        cout<<"Enter number to insert"<<endl;
        cin>>num;

        current = root;
        ptr = createNode(num);
        if(root == NULL){
            root = ptr;
            cout<<"First element inserted"<<endl;
        }
        else{
            while(current != NULL){
                parent = current;
                if(ptr->data < current->data)
                    current = current->left;
                else if(ptr->data > current->data)
                    current = current->right;
            }
            if(ptr->data < parent->data){
                parent->left = ptr;
                cout<<ptr->data<<" inserted in left of "<<parent->data<<endl;
            }
            else if(ptr->data > parent->data){
                parent->right = ptr;
                cout<<ptr->data<<" inserted in right of "<<parent->data<<endl;
            }
            else
                cout<<"Duplicate element on same parent"<<endl;
        }
    }

    void deleteLeaf(Node* &current, Node* &parent, int num){

        	if(num < parent->data)
				parent->left = NULL;
			else if(num > parent->data)
				parent->right = NULL;
            else
                parent->right = NULL;

			delete(current);
			cout<<num<<" deleted from tree"<<endl;
    }

    void deleteHavingLeft(Node* &current, Node* &parent, int num){

            Node *child;
            child = current->left;
			if(current == parent->left)
				parent->left = child;
			if(current == parent->right)
				parent->right = child;

			delete(current);
			cout<<num<<" deleted from tree"<<endl;
    }

    void deleteHavingRight(Node* &current, Node* &parent, int num){

            Node *child;
            child = current->right;
			if(current == parent->left)
				parent->left = child;
			if(current == parent->right)
				parent->right = child;

			delete(current);
			cout<<num<<" deleted from tree"<<endl;
    }

    void deleteHavingBoth(Node* &current, Node* &parent, int num){

            Node *inorder_succ;
            inorder_succ = current->right;
            parent = current;
            while(inorder_succ->left != NULL){
                parent = inorder_succ;
                inorder_succ = inorder_succ->left;
            }

            current->data = inorder_succ->data;
            if(inorder_succ->left == NULL && inorder_succ->right == NULL){

                deleteLeaf(inorder_succ,parent,inorder_succ->data);
            }
            else if(inorder_succ->left == NULL && inorder_succ->right != NULL){

                deleteHavingRight(inorder_succ,parent,inorder_succ->data);
            }
    }

    void deleteNode(){
        Node *current, *parent;
        int num;
        cout<<"Enter number to delete from tree"<<endl;
        cin>>num;

        current = root;
        parent = NULL;

        while(current != NULL && num != current->data){
            parent = current;
            if(num < current->data)
                current = current->left;
            else if(num > current->data)
                current = current->right;
        }
        if(parent == NULL){
        	if(current->left == NULL && current->right == NULL){
			root = NULL;
        		delete(current);
        		cout<<num<<" deleted from tree"<<endl;
			return;
		}
	}
	if(current == NULL)
        {
            cout<<"Node is not there"<<endl;
            return;
        }

		if(current->left == NULL && current->right == NULL){

            deleteLeaf(current,parent,num);
		}

		else if(current->left != NULL && current->right == NULL){

			deleteHavingLeft(current,parent,num);
		}
		else if(current->left == NULL && current->right != NULL){

			deleteHavingRight(current,parent,num);
		}
		else{

            deleteHavingBoth(current,parent,num);
		}
    }

    void printInorder(Node* &node){

        if (node == NULL)
            return;

        printInorder(node->left);
        cout << node->data << " ";
        printInorder(node->right);
    }

    void printPreorder(Node* &node){

        if (node == NULL)
            return;

        cout << node->data << " ";
        printPreorder(node->left);
        printPreorder(node->right);
    }

    void printPostorder(Node* &node){

        if (node == NULL)
            return;

        printPostorder(node->left);
        printPostorder(node->right);
        cout << node->data << " ";
    }

    void display(){

        cout<<"Inorder Traversal"<<endl;
        cout<<"----------------------------------------------------"<<endl;
        printInorder(root);
        cout<<"\n----------------------------------------------------"<<endl;

        cout<<"Preorder Traversal"<<endl;
        cout<<"----------------------------------------------------"<<endl;
        printPreorder(root);
        cout<<"\n----------------------------------------------------"<<endl;

        cout<<"Postorder Traversal"<<endl;
        cout<<"----------------------------------------------------"<<endl;
        printPostorder(root);
        cout<<"\n----------------------------------------------------"<<endl;
    }
};

int main(){
    BinaryTree bt;
    int opn;
    do{
        cout<<"1. Insert\n2. Delete\n3. Display\n0. Exit"<<endl;
        cin>>opn;
        switch(opn){
            case 1:
                bt.insertNode();
                break;
            case 2:
            	bt.deleteNode();
            	break;
            case 3:
                bt.display();
                break;
        }

    }while(opn != 0);
}
