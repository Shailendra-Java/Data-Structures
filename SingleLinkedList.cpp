#include<iostream>
#include<stdlib.h>
using namespace std;

class Node
{
	public:
		int data;
		Node *next;
};
class LinkedListDemo
{
	public:
		Node *start;
		LinkedListDemo()
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
			}
			return temp;
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
				cout<<"Node inserted"<<endl;
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
				while(current->data <temp->data && current != NULL)
				{
				    prev = current;
					current = current->next;
				}
				prev->next = temp;
				temp->next = current;
				cout<<"Node inserted at their correct position"<<endl;
            }
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
                start = temp;
                cout<<"Node inserted "<<endl;
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
		void display()
		{
			Node *temp;
			temp = start;
			if(start==NULL)
				cout<<"List is empty"<<endl;
			else
			{
				while(temp != NULL){
					cout<<temp->data<<"->";
					temp = temp->next;
				}
				cout<<"null"<<endl;
			}
		}
};
int main()
{
	LinkedListDemo lld;
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
        cout<<"7=> Display all list elements"<<endl;
        cout<<"8=> Exit"<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"Enter your choice"<<endl;
        cin>>opr;
        switch(opr)
        {
            case 1:
                lld.insertFront();
                break;
            case 2:
                lld.insertAt();
                break;
            case 3:
                lld.insertLast();
                break;
            case 4:
                lld.deleteFront();
                break;
            case 5:
                lld.deleteMid();
                break;
            case 6:
                lld.deleteLast();
                break;
            case 7:
                lld.display();
                break;
            case 8:
                exit(0);
            default:
                cout<<"Invalid Operation"<<endl;
        }
        cout<<"Do you want to continue (y/n) "<<endl;
        cin>>choice;
    }while(choice!= 'n');
	return 0;
}
