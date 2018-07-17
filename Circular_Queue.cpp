#include<iostream>
#define MAX 5
using namespace std;

class Circular_Queue_Array
{
    public:
        int data[MAX];
        int front, rear;

        Circular_Queue(){
            front = rear = -1;
        }

    void insert(int num){
        if((front == 0 && rear == MAX-1) || (front == rear+1)){
            cout<<"Queue Overflow"<<endl;
            return;
        }
        if(front == -1){
            front = rear = 0;
        }
        else{
            if(rear = MAX-1)
                rear = 0;
            else
                rear = rear+1;
        }
        data[rear] = num;
    }

    void del(){
        if (front == -1){
            cout<<"Queue Underflow"<<endl;
            return ;
         }
         cout<<"Element deleted from queue is "<<data[front]<<endl;
         if(front == rear){
            front = rear = -1;
         }
         else{
            if(front == MAX-1)
                front = 0;
            else
                front = front+1;
         }
    }

    void display(){
        int front_pos = front, rear_pos = rear;
        if (front == -1){
           cout<<"Queue is empty\n";
           return;
        }
        cout<<"Queue elements :\n";
        if (front_pos <= rear_pos){
           while (front_pos <= rear_pos){
                cout<<data[front_pos]<<"  ";
                front_pos++;
           }
       }
       else{
            while (front_pos <= MAX - 1){
                cout<<data[front_pos]<<"  ";
                front_pos++;
            }
            front_pos = 0;
            while (front_pos <= rear_pos){
                cout<<data[front_pos]<<"  ";
                front_pos++;
           }
      }
      cout<<endl;
    }
};

int main(){
    int choice, item;
    Circular_Queue_Array cq;

    do{
        cout<<"1.Insert\n";
        cout<<"2.Delete\n";
        cout<<"3.Display\n";
        cout<<"4.Quit\n";
        cout<<"Enter your choice : ";
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"Input the element for insertion in queue : ";
                cin>>item;
                cq.insert(item);
                break;
            case 2:
                cq.del();
                break;
            case 3:
                cq.display();
                break;
            case 4:
            break;
            default:
            cout<<"Wrong choice\n";
        }
    }while(choice != 4);
    return 0;
}
