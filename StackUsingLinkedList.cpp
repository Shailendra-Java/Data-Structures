#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
};

class StackUsingLinkedList{
    public:
    Node *top;
    StackUsingLinkedList(){
        top = NULL;
    }

    Node* createNode(int num){
        Node *temp = new Node;
        if(temp == NULL)
            cout<<"Node creation failed"<<endl;
        else{
            temp->data = num;
            temp->next = NULL;
            return temp;
        }
    }

    void push(){
        int num;
        Node *ptr;
        cout<<"Enter a number"<<endl;
        cin>>num;
        ptr = createNode(num);
        if(top == NULL){
            top = ptr;
            cout<<"First "<<top->data<<" element pushed"<<endl;
        }
        else{
            ptr->next = top;
            top = ptr;
            cout<<"Element "<<ptr->data<<" pushed in stack"<<endl;
        }
    }

    void pop(){
        Node *temp;
        if(top == NULL)
            cout<<"Stack Underflow"<<endl;
        else{
            temp = top;
            top = top->next;
            cout<<"Element"<<temp->data<<" popped from stack"<<endl;
            delete(temp);
        }
    }
    void display(){
        Node *temp;
        temp = top;
        if(top == NULL)
            cout<<"Stack Underflow"<<endl;
        else{
            while(temp != NULL){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
    }
};
int main(){
    StackUsingLinkedList sul;
    int opn;
    char ch;
    do{
        cout<<"1 => Push\n2 => Pop\n3 => Display"<<endl;
        cout<<"Enter your choice"<<endl;
        cin>>opn;
        switch(opn){
            case 1:
                sul.push();
                break;
            case 2:
                sul.pop();
                break;
            case 3:
                sul.display();
                break;
            default:
                cout<<"An invalid choice!"<<endl;
        }
        cout<<"Do you want to continue(y/n)"<<endl;
        cin>>ch;
    }while(ch == 'y' || ch == 'Y');
    return 0;
}
