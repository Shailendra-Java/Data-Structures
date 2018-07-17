#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        Node *next;
};

class QueueBYLinkedList{
    public:
        Node *front, *rear;

        QueueBYLinkedList(){
            front = rear = NULL;
        }

        Node* createNode(int num){
            Node *temp = new Node;
            if(temp == NULL){
                cout<<"Node creation failed"<<endl;
            }
            else{
                temp->data = num;
                temp->next = NULL;
            }
            return temp;
        }

        void addRequest(){
            Node *temp;
            int num;
            cout<<"Enter any number"<<endl;
            cin>>num;
            temp = createNode(num);
            if(rear == NULL && front == NULL){
                rear = front = temp;
                cout<<"First element inserted in queue"<<endl;
            }
            else{
                rear->next = temp;
                rear = temp;
                cout<<rear->data<<" element inserted"<<endl;
            }
        }

        void processRequest(){
            Node *current;
            if(front == NULL){
                cout<<"Queue is underflow"<<endl;
                return;
            }
            current = front;
            front = front->next;
            cout<<current->data<<" deleted from queue"<<endl;
            delete(current);
        }

        void display(){
            Node *temp;
            if(rear == NULL && front == NULL){
                cout<<"Queue underflow"<<endl;
                return;
            }
            temp = front;
            cout<<"FRONT <- ";
            while(temp != NULL){
                cout<<temp->data<<" -> ";
                temp = temp->next;
            }
            cout<<"REAR"<<endl;
        }
};
int main(){
    QueueBYLinkedList qbl;
    int opn;
    char choice;
    do{
        cout<<"1. Add\n2. Delete\n3. Display"<<endl;
        cout<<"Enter your choice"<<endl;
        cin>>opn;

        switch(opn){
            case 1:
                qbl.addRequest();
                break;
            case 2:
                qbl.processRequest();
                break;
            case 3:
                qbl.display();
                break;
        }
        cout<<"Do you want to continue(y/n)"<<endl;
        cin>>choice;
    }while(choice == 'y' || choice == 'Y');
}
