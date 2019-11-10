#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;
        Node *prev;
};

class List{
    Node *START, *LAST;
    public:
        List(){
            START = LAST = NULL;
        }

        Node* createNode(int num){
            Node *tmp = new Node;
            tmp->data = num;
            tmp->next = tmp->prev = NULL;
            return tmp;
        }

        int getNum(){
            int n;
            cout<<"Enter a number"<<endl;
            cin>>n;
            return n;
        }

        void addAtBeg(){
            Node *newNode = createNode(getNum());
            if(START == NULL){
                START = LAST = newNode;
                cout<<"First node added"<<endl;
            }else{
                if(newNode->data > START->data){
                    cout<<"Largest values not allowed at beginning"<<endl;
                    return;
                }
                newNode->next = START;
                START->prev = newNode;
                START = newNode;
                cout<<"Node added at beginning"<<endl;
            }
        }

        void addBetween(){
            Node *curr=START, *prv=NULL, *newNode;
            newNode = createNode(getNum());
            if(START == NULL){
                START = LAST = newNode;
                cout<<"First node added"<<endl;
            }else{
                while(curr != NULL && curr->data < newNode->data){
                    prv = curr;
                    curr = curr->next;
                }
                if(curr == NULL){
                    LAST->next = newNode;
                    newNode->prev = LAST;
                    LAST = newNode;
                    cout<<"Node added at last"<<endl;
                }else if(prv == NULL){
                    newNode->next = START;
                    START->prev = newNode;
                    START = newNode;
                    cout<<"Node added at beginning"<<endl;
                }else{
                    newNode->next = curr;
                    newNode->prev = prv;
                    prv->next = newNode;
                    curr->prev = newNode;
                    cout<<"Node added between two nodes"<<endl;
                }
            }
        }

        void addAtLast(){
            Node *newNode = createNode(getNum());
            if(START == NULL){
                START = LAST = newNode;
                cout<<"First node added"<<endl;
            }else{
                if(newNode->data < LAST->data){
                    cout<<"Smaller values not allowed at last"<<endl;
                    return;
                }
                LAST->next = newNode;
                newNode->prev = LAST;
                LAST = newNode;
                cout<<"Node added at last"<<endl;
            }
        }

        void deleteFromBeg(){
            Node *curr = START;
            if(START == NULL){
                cout<<"List is empty"<<endl;
                return;
            }
            START = START->next;
            if(START != NULL){
                START->prev = NULL;                
            }
            delete curr;
            cout<<"\aNode deleted from beginning"<<endl;
        }

        void deleteFromLast(){
            Node *curr = LAST;
            if(START == NULL){
                cout<<"List is empty"<<endl;
                return;
            }
            LAST = LAST->prev;
            if(LAST != NULL){
                LAST->next = NULL; 
            }
            delete curr;
            cout<<"\aNode deleted from last"<<endl;
        }

        void deleteFromBtw(){
            Node *curr = START, *prv=NULL;
            int x = getNum();
            if(START == NULL){
                cout<<"List is empty"<<endl;
                return;
            }
            while(curr!= NULL && curr->data != x){
                prv = curr;
                curr = curr->next;
            }
            if(curr == NULL){
                cout<<"Node is not there"<<endl;
                return;
            }
            if(curr == LAST){
                LAST = LAST->prev;
                if(LAST != NULL){
                    LAST->next = NULL;
                    delete curr;
                    cout<<"\aNode deleted from last"<<endl;
                }
            }
            else if(prv == NULL){
               START = START->next;
                if(START != NULL){
                    START->prev = NULL;
                    delete curr;
                    cout<<"\aNode deleted from beginning"<<endl;
                }
            }else{
                prv->next = curr->next;
                curr->next->prev = prv;
                delete curr;
                cout<<"\aNode deleted from between two nodes"<<endl;
            }
        }

        void printList(){
            Node *curr = START;
            if(START == NULL){
                cout<<"List is empty"<<endl;
                return;
            }
            cout<<"List in Forward Direction"<<endl;
            while(curr != NULL){
                cout<<curr->data<<"  ";
                curr = curr->next;
            }
            cout<<"\nList in Backward Direction"<<endl;
            curr = LAST;
            while(curr != NULL){
                cout<<curr->data<<"  ";
                curr = curr->prev;
            }
            cout<<endl;
        }
};
main(){
    int choice;
    List lst;
    do{
        cout<<"1. Add Beginning\n2. Add Last\n3. Add Between\n4. Print List"<<endl;
        cout<<"5. Delete From Beginning\n6. Delete From Last\n7. Delete From Between"<<endl;
        cout<<"0. Exit"<<endl;
        cin>>choice;
        switch(choice){
            case 1:
                lst.addAtBeg();
                break;
            case 2:
                lst.addAtLast();
                break;
            case 3:
                lst.addBetween();
                break;
            case 4:
                lst.printList();
                break;
            case 5:
                lst.deleteFromBeg();
                break;
            case 6:
                lst.deleteFromLast();
                break;
            case 7:
                lst.deleteFromBtw();
                break;
        }
    }while(choice != 0);
}
