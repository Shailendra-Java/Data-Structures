#include<iostream>
#define MAX 5
using namespace std;

class CircularQueue
{
    public:
        int data[MAX], front, rear;

        CircularQueue()
        {
            front = rear = -1;
        }

        int isEmpty()
        {
            if((front == -1 && rear == -1) || (front == rear))
                return 1;
            else
                return 0;
        }
        int isFull()
        {
            if((front == 0 && rear == MAX-1)||(front == rear+1))
                return 1;
            else
                return 0;
        }
        void push()
        {
            int num;
            cout<<"Enter any number"<<endl;
            cin>>num;
            if(isFull())
            {
                cout<<"Queue overflow"<<endl;
                return;
            }
            if(front == -1)
                front = 0;
            if(rear == MAX-1 && front != 0)
            {
                rear = 0;
            }
            else
                rear++;
            data[rear] = num;
            cout<<num<<" inserted in queue"<<endl;
        }
        void pop()
        {
            int temp;
            if(isEmpty())
            {
                cout<<"Queue is underflow"<<endl;
            }
            temp = data[front];
            cout<<temp<<" deleted from queue"<<endl;
            front++;
        }
        void display()
        {
            if(isEmpty())
            {
                cout<<"Queue is underflow"<<endl;
                return;
            }
            if(rear > front)
            {
                for(int i=front; i<= rear; i++)
                    cout<<data[i]<<" ";
            }
            if(front>rear)
            {
                for(int k=0; k<= rear; k++)
                    cout<<data[k]<<" ";
                for(int j= front; j< MAX; j++)
                    cout<<data[j]<<" ";

            }
            cout<<endl;
        }
};
int main()
{
    CircularQueue cq;
    int opn;
    char choice;
    do
    {
        cout<<"1. Push\n2. Pop\n3. Display"<<endl;
        cout<<"Enter your choice"<<endl;
        cin>>opn;
        switch(opn)
        {
            case 1:
                cq.push();
                break;
            case 2:
                cq.pop();
                break;
            case 3:
                cq.display();
                break;
        }
        cout<<"Do you want to continue(y/n)"<<endl;
        cin>>choice;
    }while(choice == 'y' || choice == 'Y');
}
