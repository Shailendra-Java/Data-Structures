#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *next, *prev;
};

class DList
{
    Node *START, *LAST;
    public:
        DList()
        {
            START = LAST = NULL;
        }
        Node* createNode(int n)
        {
            Node *tmp = new Node;
            tmp->data = n;
            tmp->next = tmp->prev = NULL;
            return tmp;
        }
        void insertNode(){
            int num;
            Node *newNode, *curr = START, *bck = NULL;
            cout<<"Enter number to insert"<<endl;
            cin>>num;

            newNode = createNode(num);

            if(START == NULL){
                START = LAST = newNode;
                cout<<"First node added "<<endl;
            }
            else{
                while(curr != NULL && num > curr->data)
                {
                    bck = curr;
                    curr = curr->next;
                }
                if(bck == NULL){
                    newNode->next = START;
                    START->prev = newNode;
                    START = newNode;
                    cout<<"Node added at beginning"<<endl;
                }
                else if(curr == NULL){
                    bck->next = newNode;
                    newNode->prev = bck;
                    LAST = newNode;
                    cout<<"Node added at last"<<endl;
                }
                else{
                    bck->next = newNode;
                    newNode->next = curr;
                    curr->prev = newNode;
                    newNode->prev = bck;
                    cout<<"Node added between two nodes"<<endl;
                }
            }
        }
        void deleteNode(){
            int num;
            Node *curr = START, *bck = NULL;
            cout<<"Enter number to delete"<<endl;
            cin>>num;
            if(START == NULL)
                cout<<"List is empty"<<endl;
            else{
                while(curr != NULL && num != curr->data){
                    bck = curr;
                    curr = curr->next;
                }
                if(bck == NULL){
                    START = START->next;
                    if(START != NULL)
                        START->prev = NULL;
                    delete curr;
                    cout<<"Node deleted from front"<<endl;
                }
                else if(curr->next == NULL){
                    LAST = LAST->prev;
                    LAST->next = NULL;
                    delete curr;
                    cout<<"Node deleted from last"<<endl;
                }
                else{
                    bck->next = curr->next;
                    curr->next->prev = bck;
                    delete curr;
                    cout<<"Node deleted from between two nodes"<<endl;
                }
            }
        }
        void printList(){
            Node *curr = START;
            if(START == NULL)
                cout<<"List is empty"<<endl;

            else{
                cout<<"List in forward direction : "<<endl;
                while(curr != NULL){
                  cout<<curr->data<<" ";
                  curr = curr->next;
                }
                cout<<endl;
                cout<<"List in backward direction : "<<endl;
                curr = LAST;
                while(curr != NULL){
                  cout<<curr->data<<" ";
                  curr = curr->prev;
                }
                cout<<endl;
            }
        }
};
main()
{
    int opns;
    DList dl;
    do{
        cout<<"1. Insert Node\n2. Print List\n3. Delete Node\n0. Exit"<<endl;
        cin>>opns;
        switch(opns)
        {
            case 1:
                dl.insertNode();
                break;
            case 2:
                dl.printList();
                break;
            case 3:
                dl.deleteNode();
                break;
        }
    }while(opns != 0);
}
