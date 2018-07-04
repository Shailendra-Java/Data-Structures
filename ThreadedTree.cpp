#include<iostream>
using namespace std;

class Node{
    public:
        int data, lth, rth;
        Node *left, *right;
};

class ThreadedTree{
    public:
        Node *head, *current, *parent;

    ThreadedTree(){

            head = new Node;
            head->left = head;
            head->right = head;
            head->lth = 0;
            head->rth = 1;
    }

    Node* createNode(int data){

        Node *temp = new Node;
        temp->data = data;
        temp->left = temp->right = NULL;
        temp->lth = temp->rth = 0;

        return temp;
    }

    void getPosition(Node* &current, Node* &parent, int data){

        current = head->left;
        while(current != NULL){
            parent = current;
            if((data < current->data) && (current->lth == 1)){
                current = current->left;
                continue;
            }
            else if((data < current->data) && (current->lth == 0)){
                current = NULL;
                continue;
            }
            else if((data > current->data) && (current->rth == 1)){
                current = current->right;
                continue;
            }
            else if((data > current->data) && (current->rth == 0)){
                current = NULL;
                continue;
            }
        }
    }

    void insertNode(){

        Node *temp, *parent, *current;
        int num;
        cout<<"Enter Number to insert"<<endl;
        cin>>num;
        temp = createNode(num);

        parent = current = head;
        if(head->left == head){

            head->lth = 1;
            head->left = temp;
            temp->left = temp->right = head;
            cout<<"First Node created"<<endl;
            return;
        }

        getPosition(current, parent, num);
        if(num < parent->data){
            temp->left = parent->left;
            temp->right = parent;
            parent->lth = 1;
            parent->left = temp;
            cout<<num<<" inserted in left of "<<parent->data<<endl;
            cout<<"Left thread is : "<<temp->left->data<<" Right thread is : "<<parent->data<<endl;
        }
        else if(num > parent->data){
            temp->left = parent;
            temp->right = parent->right;
            parent->rth = 1;
            parent->right = temp;
            cout<<num<<" inserted in right of "<<parent->data<<endl;
            cout<<"Left thread is : "<<parent->data<<" Right thread is : "<<temp->right->data<<endl;
        }
    }

    void deleteNode(){
        Node *parent = *current = head;
        if(head->left == head){

            cout<<"Sorry list is empty"<<endl;
            return;
        }
    }
};

int main(){
    ThreadedTree thTree;
    int opn;
    char choice;
    do{
        cout<<"1. Insert\n2. Delete\n3. Display"<<endl;
        cin>>opn;
        switch(opn){
            case 1:
                thTree.insertNode();
                break;
            case 2:
                thTree.deleteNode();
                break;
            case 3:
                break;
        }
        cout<<"Do you want to continue(y/n)"<<endl;
        cin>>choice;
    }while(choice == 'y' || choice == 'Y');
}
