#include<iostream>
#include<stdlib.h>
using namespace std;

class Node
{
	public:
		int data;
		Node *next;
		Node *prev;
};
class DoublyListDemo
{
	public:
		Node *start;
		DoublyListDemo()
		{
			start = NULL;
		}

		Node* createNode(int x)
		{
			Node *temp = new Node;
			if(temp==NULL)
				cout<<"Node creation failed"<<endl;
			else
			{
				temp->data = x;
				temp->next = NULL;
				temp->prev = NULL;
			}
			return temp;
		}
		void insertFront()
		{
            int data;
            Node *temp;
            cout<<"Enter any element"<<endl;
            cin>>data;
            temp = createNode(data);
            if(start==NULL)
            {
                start = temp;
                cout<<"First Node created"<<endl;
            }
            else{
                temp->next = start;
                temp->prev = NULL;
                start = temp;
                cout<<"Node inserted "<<endl;
            }

		}
		void insertAt()
		{
			Node *current, *prev, *temp;
			int data;
			cout<<"Enter Element"<<endl;
			cin>>data;
			temp = createNode(data);
			current = start;
			prev = NULL;
			if(start==NULL)
			{
				start = temp;
				cout<<"First Node created"<<endl;
			}
			else
            {
				while(current->data < temp->data && current != NULL)
				{
				    prev = current;
					current = current->next;
				}
				temp->next = current;
				temp->prev = prev;
				if(current != NULL)
                    current->prev = temp;
				prev->next = temp;
				cout<<"Node inserted at their correct position"<<endl;
            }
		}
		void insertLast()
		{
			Node *temp, *last;
			int num;
			cout<<"Enter a number"<<endl;
			cin>>num;
			temp = createNode(num);
			last = start;
			if(start==NULL)
			{
				start = temp;
				cout<<"First Node created"<<endl;
			}
			else
			{
				while(last->next != NULL)
				{
					last = last->next;
				}
				last->next = temp;
				temp->prev = last;
				cout<<"Node inserted"<<endl;
			}
		}

        void deleteFront()
		{
            Node *current;
            current = start;
            if(start == NULL)
                cout<<"Sorry List is empty"<<endl;
            else
            {
                start = start->next;
                start->prev = NULL;
                cout<<"Node to be deleted :  "<<current->data<<endl;
                delete(current);
                cout<<"First Node Deleted"<<endl;
            }
		}

		void deleteMid()
		{
            Node *prev, *current;
            int data;
            cout<<"Enter element to delete"<<endl;
            cin>>data;
            prev = current = start;
            if(start==NULL)
            {
                cout<<"Sorry list is empty"<<endl;
            }
            else
            {
                while(current->data != data && current->next != NULL)
                {
                    prev = current;
                    current = current->next;
                }
                prev->next = current->next;
                if(current->next != NULL)
                    current->next->prev = prev;
                cout<<"Node to be deleted :  "<<current->data<<endl;
                delete(current);
                cout<<"Node deleted"<<endl;
            }
		}

		void deleteLast()
		{
            Node *last, *prev;
            last = start;
            prev = NULL;
            if(start == NULL)
                cout<<"List is empty"<<endl;
            else
            {
                while(last->next != NULL){
                    prev = last;
                    last = last->next;
                }
                prev->next = NULL;
                cout<<"Node to be deleted :  "<<last->data<<endl;
                delete(last);
                cout<<"Node deleted"<<endl;
            }
		}

		void displayForwad()
		{
			Node *temp;
			temp = start;
			if(start==NULL)
				cout<<"List is empty"<<endl;
			else
			{
			    cout<<"null <- ";
				while(temp != NULL)
                {
                    if(temp->next == NULL)
                    {
                        cout<<temp->data<<" -> ";
                        temp = temp->next;
                    }
                    else
                    {
                        cout<<temp->data<<" <-> ";
                        temp = temp->next;
                    }
				}
				cout<<"null"<<endl;
			}
		}
		void displayBackwad()
		{
			Node *last;
			last = start;
			if(start==NULL)
				cout<<"List is empty"<<endl;
			else
			{
			    while(last->next != NULL)
				{
					last = last->next;
				}
				cout<<"null <- ";
				while(last != NULL)
                {
                    if(last->prev == NULL)
                    {
                        cout<<last->data<<" -> ";
                        last = last->prev;
                    }
                    else
                    {
                        cout<<last->data<<" <-> ";
                        last = last->prev;
                    }
				}
				cout<<"null"<<endl;
			}
		}
};
int main()
{
	DoublyListDemo dld;
	char choice;
	int opr;
	do
    {
        cout<<"Linked List Operations"<<endl;
        cout<<"============================="<<endl;
        cout<<"1=> Insert at beginning"<<endl;
        cout<<"2=> Insert at position"<<endl;
        cout<<"3=> Insert at last"<<endl;
        cout<<"4=> Delete at beginning"<<endl;
        cout<<"5=> Delete at position"<<endl;
        cout<<"6=> Delete at last"<<endl;
        cout<<"7=> Display in forward direction"<<endl;
        cout<<"8=> Display in backward direction"<<endl;
        cout<<"9=> Exit"<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"Enter your choice"<<endl;
        cin>>opr;
        switch(opr)
        {
            case 1:
                dld.insertFront();
                break;
            case 2:
                dld.insertAt();
                break;
            case 3:
                dld.insertLast();
                break;
            case 4:
                dld.deleteFront();
                break;
            case 5:
                dld.deleteMid();
                break;
            case 6:
                dld.deleteLast();
                break;
            case 7:
                dld.displayForwad();
                break;
            case 8:
                dld.displayBackwad();
                break;
            case 9:
                exit(0);
            default:
                cout<<"Invalid Operation"<<endl;
        }
        cout<<"Do you want to continue (y/n) "<<endl;
        cin>>choice;
    }while(choice!= 'n');
	return 0;
}
