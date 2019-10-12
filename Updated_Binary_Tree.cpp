#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *left;
        Node *right;
};

class BinarySearchTree
{
    Node *ROOT;
    public:
        BinarySearchTree()
        {
            ROOT = NULL;
        }
        Node* createNode(int n){
            Node *tmp = new Node;
            tmp->data = n;
            tmp->left = tmp->right = NULL;
            return tmp;
        }

        void insertNode(){
            int x;
            Node *newNode, *curr = ROOT, *parent = NULL;
            cout<<"Enter number to insert"<<endl;
            cin>>x;
            newNode = createNode(x);

            if(ROOT == NULL){
                ROOT = newNode;
                cout<<"Root added in tree"<<endl;
            }
            else{
                while(curr != NULL){
                    parent = curr;
                    if(x > curr->data)
                        curr = curr->right;
                    else if(x < curr->data)
                        curr = curr->left;
                    else
                        break;
                }
                if(x < parent->data){
                    parent->left = newNode;
                    cout<<x<<" added in left of "<<parent->data<<endl;
                }
                else if(x > parent->data){
                    parent->right = newNode;
                    cout<<x<<" added in right of "<<parent->data<<endl;
                }
                else
                    cout<<"Duplicates not allowed"<<endl;
            }
        }
        void inOrder(Node* &curr){
            if(curr == NULL)
                return;
            inOrder(curr->left);
            cout<<curr->data<<" ";
            inOrder(curr->right);
        }
        void preOrder(Node* &curr){
            if(curr == NULL)
                return;
            cout<<curr->data<<" ";
            preOrder(curr->left);
            preOrder(curr->right);
        }
        void postOrder(Node* &curr){
            if(curr == NULL)
                return;
            postOrder(curr->left);
            postOrder(curr->right);
            cout<<curr->data<<" ";
        }
        void printTree(){
            if(ROOT == NULL){
                cout<<"Tree is empty"<<endl;
                return;
            }
            cout<<"In-order - Traversal"<<endl;
            inOrder(ROOT);
            cout<<"\n\nPre-order - Traversal"<<endl;
            preOrder(ROOT);
            cout<<"\n\nPost-order - Traversal"<<endl;
            postOrder(ROOT);
        }
        void deleteNode(){
            int num;
            Node *curr = ROOT, *parent = NULL;
            cout<<"Enter number to delete"<<endl;
            cin>>num;
            if(ROOT == NULL){
                cout<<"Tree is empty"<<endl;
                return;
            }
            while(curr != NULL && num != curr->data){
                parent = curr;
                if(num > curr->data)
                    curr = curr->right;
                else
                    curr = curr->left;
            }
            if(curr->left == NULL && curr->right == NULL){
                if(num == parent->left->data)
                    parent->left = NULL;
                else
                    parent->right = NULL;
                delete curr;
                cout<<num<<" deleted from tree"<<endl;
            }
            else if((curr->left != NULL && curr->right == NULL)
                    ||(curr->left == NULL && curr->right != NULL)){
                        Node *child = NULL;
                        if(curr->left != NULL)
                            child = curr->left;
                        else
                            child = curr->right;
                        if(parent->left = curr)
                            parent->left = child;
                        else
                            parent->right = child;
                        delete curr;
                        cout<<num<<" deleted from tree"<<endl;
                    }
            else{
                Node *ins = curr->right, *p = NULL;
                while(ins->left != NULL){
                    p = ins;
                    ins = ins->left;
                }
                curr->data = ins->data;

                if(ins->left == NULL && ins->right == NULL){
                    if(num == p->left->data)
                        p->left = NULL;
                    else
                        p->right = NULL;
                    delete curr;
                    cout<<num<<" deleted from tree"<<endl;
                }
                else if((ins->left != NULL && ins->right == NULL)
                    ||(ins->left == NULL && ins->right != NULL)){
                        Node *child = NULL;
                        if(ins->left != NULL)
                            child = ins->left;
                        else
                            child = ins->right;
                        if(p->left = curr)
                            p->left = child;
                        else
                            p->right = child;
                        delete curr;
                        cout<<num<<" deleted from tree"<<endl;
                    }
            }
        }
};
main(){
    BinarySearchTree bs;
    int opns;
    do{
        cout<<"1. Add Node\n2. Print Tree\n3. Delete\n0. Exit"<<endl;
        cin>>opns;
        switch(opns){
            case 1:
                bs.insertNode();
                break;
            case 2:
                bs.printTree();
                break;
            case 3:
                bs.deleteNode();
                break;
        }
    }while(opns != 0);
}
