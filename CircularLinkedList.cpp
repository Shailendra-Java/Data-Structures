#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;
};

class CircularLinkedList
{
    public:
        Node *last;

        CircularLinkedList()
        {
            last = NULL;
        }

        Node* createNode(int value)
        {
            Node *temp = new Node;
            if(temp == NULL)
                cout<<"Node creation failed"<<endl;
            else
            {
                temp->data = value;
                temp->next = NULL;
            }
            return temp;
        }
        void insertFront()
        {
            Node *temp;
            int num;
            cout<<"Enter any value"<<endl;
            cin>>num;
            temp = createNode(num);
            if(last ==NULL)
            {
                last = temp;
                temp->next = last;
            }
            else
            {
                temp->next = last->next;
                last->next = temp;
            }
        }
        void insertAt()
		{
			Node *current, *prev, *temp;
			int data;
			cout<<"Enter Element"<<endl;
			cin>>data;
			temp = createNode(data);
			current = last->next;
			prev = NULL;
			if(last==NULL)
			{
				last = temp;
				last->next = last;
				cout<<"First Node created"<<endl;
			}
			else
            {
				while(current->data < temp->data && prev != last)
				{
				    prev = current;
					current = current->next;
				}
				prev->next = temp;
				temp->next = current;
				cout<<"Node inserted at their correct position"<<endl;
            }
		}
        void display()
        {
            Node *current;
            current = last->next;
            while(current != last)
            {
                cout<<current->data<<" -> ";
                current = current->next;
            }
            cout<<last->data<<endl;
        }
};
int main()
{
    CircularLinkedList cll;
    for(int i=0; i<3; i++)
        cll.insertFront();
    cll.insertAt();
    cll.display();
}
