#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        int height;
        Node *left;
        Node *right;
};

class BalancedBinaryTree{
    public:
        Node *root, *current, *parent;

    BalancedBinaryTree(){
        root = current = parent = NULL;
    }

    Node* createNode(int num){
        Node *temp = new Node;
        temp->data = num;
        temp->height = 0;
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
                else{
                   cout<<"Duplicate element on same parent"<<endl;
                    break;
                }
            }
            if(ptr->data < parent->data){
                parent->left = ptr;
                cout<<ptr->data<<" inserted in left of "<<parent->data<<endl;

                if(height(parent->left) - height(parent->right) == 2){

                   if(ptr->data < parent->left->data)
                        parent = singleRightRotate(parent);

                   else
                        parent = doubleRightRotate(parent);
                }
            }
            else if(ptr->data > parent->data){
                parent->right = ptr;
                cout<<ptr->data<<" inserted in right of "<<parent->data<<endl;

                if(height(parent->left) - height(parent->right) == 2){

                   if(ptr->data > parent->left->data)
                        parent = singleLeftRotate(parent);

                   else
                        parent = doubleLeftRotate(parent);
                }
            }
            parent->height = max(height(parent->left), height(parent->right))+1;
        }
    }

    void deleteLeaf(Node* &current, Node* &parent, int num){

        	if(num < parent->data)
				parent->left = NULL;
			else if(num > parent->data)
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
            while(inorder_succ->left != NULL){
                parent = inorder_succ;
                inorder_succ = inorder_succ->left;
            }
            current->data = inorder_succ->data;
            if(inorder_succ->left == NULL && inorder_succ->right == NULL){

                deleteLeaf(inorder_succ,parent,num);
            }

            else if(inorder_succ->left != NULL && inorder_succ->right == NULL){

                deleteHavingLeft(inorder_succ,parent,num);
            }
            else if(inorder_succ->left == NULL && inorder_succ->right != NULL){

                deleteHavingRight(inorder_succ,parent,num);
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
        	root = NULL;
        	delete(current);
        	cout<<num<<" deleted from tree"<<endl;
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

    //-----------------------------Balancing-------------------------

    int height(Node* t){
        return (t == NULL ? -1 : t->height);
    }

     int getBalance(Node* t){
        if(t == NULL)
            return 0;
        else
            return height(t->left) - height(t->right);
    }

    Node* singleRightRotate(Node* &t){
        Node* u = t->left;
        t->left = u->right;
        u->right = t;
        t->height = max(height(t->left), height(t->right))+1;
        u->height = max(height(u->left), t->height)+1;
        return u;
    }

    Node* singleLeftRotate(Node* &t){
        Node* u = t->right;
        t->right = u->left;
        u->left = t;
        t->height = max(height(t->left), height(t->right))+1;
        u->height = max(height(t->right), t->height)+1 ;
        return u;
    }

    Node* doubleLeftRotate(Node* &t){
        t->right = singleRightRotate(t->right);
        return singleLeftRotate(t);
    }

    Node* doubleRightRotate(Node* &t){
        t->left = singleLeftRotate(t->left);
        return singleRightRotate(t);
    }

    //---------------------------------------------------------------

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
    BalancedBinaryTree bt;
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
            case 3:
                bt.display();
                break;
        }
        cout<<"Do you want to continue(y/n)"<<endl;
        cin>>choice;
    }while(choice == 'y' || choice == 'Y');
}
