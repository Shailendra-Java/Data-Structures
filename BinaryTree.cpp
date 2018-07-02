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
            if(ptr->data > parent->data){
                parent->right = ptr;
                cout<<ptr->data<<" inserted in right of "<<parent->data<<endl;
            }
        }
    }

    void deleteNode(){
        Node *current, *parent, *child;
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
        	root = NULL;
        	delete(current);
        	cout<<num<<" deleted from tree"<<endl;
		}
		if(current->left == NULL && current->right == NULL){
			
			if(num < parent->data)
				parent->left = NULL;
			else if(num > parent->data)
				parent->right = NULL;
			
			delete(current);
			cout<<num<<" deleted from tree"<<endl;
		}
		else if(current->left != NULL && current->right == NULL){
			
			child = current->left;
			if(current == parent->left)
				parent->left = child;
			if(current == parent->right)
				parent->right = child;
				
			delete(current);
			cout<<num<<" deleted from tree"<<endl;
		}
		else if(current->left == NULL && current->right != NULL){
			
			child = current->right;
			if(current == parent->left)
				parent->left = child;
			if(current == parent->right)
				parent->right = child;
				
			delete(current);
			cout<<num<<" deleted from tree"<<endl;
		}
    }
};

int main(){
    BinaryTree bt;
    int opn;
    char choice;
    do{
        cout<<"1. Insert\n2. Delete\n3. Display"<<endl;
        cin>>opn;
        switch(opn){
            case 1:
                bt.insertNode();
                break;
            case 2:
            	bt.deleteNode();
            	break;
        }
        cout<<"Do you want to continue(y/n)"<<endl;
        cin>>choice;
    }while(choice == 'y' || choice == 'Y');
}