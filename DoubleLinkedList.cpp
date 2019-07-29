#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;
        Node *prev;
};

class Operations
{
    Node *START, *LAST;
    public:
        Operations()
        {
            START = LAST = NULL;
        }
        Node* createNode(int n)
        {
            Node *temp = new Node;
            temp->data = n;
            temp->next = temp->prev = NULL;
            return temp;
        }
        void insertAtFront()
        {
            int num;
            Node *newNode;
            cout<<"Enter a number"<<endl;
            cin>>num;
            newNode = createNode(num);
            if(START == NULL)
            {
                START = LAST = newNode;
                cout<<"First Node inserted"<<endl;
            }
            else{
                START->prev = newNode;
                newNode->next = START;
                START = newNode;
                cout<<"Node inserted at Front"<<endl;
            }
        }
        void insertAtMid()
        {
            int num;
            Node *newNode, *curr, *prev;
            cout<<"Enter a number"<<endl;
            cin>>num;
            newNode = createNode(num);
            curr = START;
            prev = NULL;
            if(START == NULL)
            {
                START = LAST = newNode;
                cout<<"First Node inserted"<<endl;
            }
            else{
                while(num > curr->data && curr->next != NULL)
                {
                    prev = curr;
                    curr = curr->next;
                }
                if(curr->next == NULL)
                {
                    curr->next = newNode;
                    newNode->prev = curr;
                    LAST = newNode;
                }
                else if(prev == NULL)
                {
                    curr->prev = newNode;
                    newNode->next = curr;
                    START = newNode;
                }
                else{
                    prev->next = newNode;
                    newNode->prev = prev;
                    newNode->next = curr;
                    curr->prev = newNode;
                }
                cout<<"Node inserted at their position"<<endl;
            }
        }
        void insertAtLast()
        {
            int num;
            Node *newNode;
            cout<<"Enter a number"<<endl;
            cin>>num;
            newNode = createNode(num);
            if(START == NULL)
            {
                START = LAST = newNode;
                cout<<"First Node inserted"<<endl;
            }
            else{
                LAST->next = newNode;
                newNode->prev = LAST;
                LAST = newNode;
                cout<<"Node inserted at Last"<<endl;
            }
        }
        void deleteFromFront()
        {
            Node *curr = START;
            if(START == NULL)
            {
                cout<<"List is empty"<<endl;
            }
            else{
                START = START->next;
                START->prev = NULL;
                delete(curr);
                cout<<"Node Deleted from front"<<endl;
            }
        }
        void deleteFromMid()
        {
            int num;
            Node *curr, *prev;
            cout<<"Enter a number to delete"<<endl;
            cin>>num;
            curr = START;
            prev = NULL;
            if(START == NULL)
            {
                cout<<"List is empty"<<endl;
            }
            else{
                while(num != curr->data && curr->next != NULL)
                {
                    prev = curr;
                    curr = curr->next;
                }
                if(START == LAST)
                {
                    START = LAST = NULL;
                    delete(curr);
                }
                else if(curr->next == NULL)
                {
                    LAST = LAST->prev;
                    LAST->next = NULL;
                    delete(curr);
                }
                else if(prev == NULL)
                {
                    START = START->next;
                    START->prev = NULL;
                    delete(curr);
                }
                else{
                    prev->next = curr->next;
                    curr->next->prev = prev;
                    delete(curr);
                }
                cout<<"Node deleted from their position"<<endl;
            }
        }
        void deleteFromLast()
        {
            Node *curr = LAST;
            if(START == NULL)
            {
                cout<<"List is empty"<<endl;
            }
            else{
                LAST = LAST->prev;
                LAST->next = NULL;
                delete(curr);
                cout<<"Node Deleted from last"<<endl;
            }
        }
        void search()
        {
            int item;
            Node *curr = START;
            cout<<"Enter number to search"<<endl;
            cin>>item;
            if(START == NULL){
                cout<<"List is empty"<<endl;
                return;
            }
            while(curr != NULL){
                if(item == curr->data){
                    cout<<"Number found in list"<<endl;
                    break;
                }
            }
            if(curr == NULL)
                cout<<"Number not found"<<endl;
        }
        void printAsc()
        {
            Node *curr = START;
            if(START == NULL)
                cout<<"List is empty"<<endl;
            else{
                while(curr != NULL)
                {
                    cout<<curr->data<<"  ";
                    curr = curr->next;
                }
                cout<<endl;
            }
        }
        void printDesc()
        {
            Node *curr = LAST;
            if(START == NULL)
                cout<<"List is empty"<<endl;
            else{
                while(curr != NULL)
                {
                    cout<<curr->data<<"  ";
                    curr = curr->prev;
                }
                cout<<endl;
            }
        }
};
main()
{
    Operations lio;
    int choice;
    do
    {
        cout<<"1. Insert Front\t2. Insert Mid"<<endl;
        cout<<"3. Insert Last\t4. Display"<<endl;
        cout<<"5. Delete Front\t6. Delete Mid"<<endl;
        cout<<"7. Delete Last\t8. Search"<<endl;
        cout<<"0. Exit"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
                lio.insertAtFront();
                break;
            case 2:
                lio.insertAtMid();
                break;
            case 3:
                lio.insertAtLast();
                break;
            case 4:
                cout<<"Forward Direction >>"<<endl;
                lio.printAsc();
                cout<<"Backward Direction >>"<<endl;
                lio.printDesc();
                break;
            case 5:
                lio.deleteFromFront();
                break;
            case 6:
                lio.deleteFromMid();
                break;
            case 7:
                lio.deleteFromLast();
                break;
            case 8:
                lio.search();
                break; */

        }
    }while(choice != 0);
}

