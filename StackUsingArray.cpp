#include<iostream>
#define MAX 5
using namespace std;

class StackUsingArray
{
    public:
        int STACK[MAX],TOP;

        StackUsingArray()
        {
            TOP = -1;
        }
        int isEmpty(){
            if(TOP==-1)
                return 1;
            else
                return 0;
        }

        int isFull(){
            if(TOP==MAX-1)
                return 1;
            else
                return 0;
        }

        void push(int num){
            if(isFull()){
                cout<<"STACK Overflow"<<endl;
                return;
            }
            ++TOP;
            STACK[TOP] = num;
            cout<<num<<" Has been inserted"<<endl;
        }

        void pop(){
            int temp;
            if(isEmpty()){
                cout<<"STACK Underflow"<<endl;
                return;
            }
            temp = STACK[TOP];
            --TOP;
            cout<<temp<<" Has been deleted"<<endl;
        }

        void display(){
            int i;
            if(isEmpty()){
                cout<<"STACK Underflow"<<endl;
                return;
            }
            for(i=TOP; i>=0; i--)
                cout<<STACK[i]<<" ";
            cout<<endl;
        }
};
int main(){
    StackUsingArray sua;
    int num, opn;
    char ch;
    do{
        cout<<"1 => Push\n2 => Pop\n3 => Display"<<endl;
        cout<<"Enter your choice"<<endl;
        cin>>opn;
        switch(opn){
            case 1:
                cout<<"Enter an Integer number"<<endl;
                cin>>num;
                sua.push(num);
                break;
            case 2:
                sua.pop();
                break;
            case 3:
                sua.display();
                break;
            default:
                cout<<"An invalid choice!"<<endl;
        }
        cout<<"Do you want to continue(y/n)"<<endl;
        cin>>ch;
    }while(ch == 'y' || ch == 'Y');
    return 0;
}
