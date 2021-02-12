#include<iostream>
using namespace std;
class node
{
    public:
        int data;
        node *next;
};
class Operations
{
    public:
    int a;
    node *start,*last;
    Operations()
    {
        start=NULL;
    }
    node *NewNode(int x)
    {
        node *temp=new node;
        temp->data=x;
        temp->next=NULL;
        return temp;
    }
    void insertfront()
    {
        node *temp;
        cout<<"Enter data"<<endl;
        cin>>a;
        temp=NewNode(a);
        if(start==NULL)
        {
            start = temp;
            cout<<"First Node created"<<endl;
        }
        else
        {
            temp->next=start;
            start=temp;
            cout<<"Data inserted"<<endl;
        }
    }
    void insertmid()
    {
        node *temp,*prev,*curr;
        cout<<"Enter data"<<endl;
        cin>>a;
        temp=NewNode(a);
        curr=start;
        prev=NULL;
        if(start==NULL)
        {
            start = temp;
            cout<<"First Node created"<<endl;
        }
        else
        {
            while(curr->data < temp->data && curr->next!=NULL)
            {
                prev=curr;
                curr=curr->next;
            }
            if(prev==NULL)
            {
                temp->next=start;
                start=temp;
            }
            else
                if(curr->next==NULL)
            {
                curr->next=temp;
            }
            else
            {
                prev->next=temp;
                temp->next=curr;
            }
            cout<<"Data inserted"<<endl;
        }
    }
    void insertlast()
    {
        node *temp;
        cout<<"Enter data";
        cin>>a;
        temp=NewNode(a);
        last=start;
        if(start==NULL)
        {
            start = temp;
            cout<<"First Node created"<<endl;
        }
        else
        {
            while(last->next!=NULL)
            {
                last=last->next;
            }
            last->next=temp;
            cout<<"Data inserted"<<endl;
        }
    }
    void deletebeg()
    {
        node *temp;
        temp=start;
        if(start==NULL)
        {
            cout<<"EMPTY LIST!"<<endl;
        }
        else
        {
            start=start->next;
            delete temp;
            cout<<"First node deleted"<<endl;
        }
    }
    void deletemid()
    {
        node *prev,*curr;
        cout<<"Enter element to be deleted"<<endl;
        cin>>a;
        curr=start;
        prev=NULL;
        if(start==NULL)
        {
            cout<<"EMPTY LIST!"<<endl;
        }
        else
        {
            /*while(curr->data != a && curr->next!=NULL)     //to delete first come
            {
                prev=curr;
                curr=curr->next;
            }
            if(curr->data!=a)
            {
                cout<<"DATA NOT FOUND"<<endl;
            }
            else
            {
                prev->next=curr->next;
                delete curr;
            }*/
            rec(a,curr,prev);      //to delete multiple elements
        }
    }
    void rec(int a,node *curr,node *prev)      //recursive function to delete multiple elements
    {
        node *temp=curr;
        if(a==curr->data)
        {
            if(temp==start)
            {
                curr=curr->next;
                start=curr;
                delete temp;
                cout<<"Element deleted from start"<<endl;
            }
            else
            {
                curr=curr->next;
                prev->next=curr;
                if(temp==last)
                {
                    last=prev;
                    prev->next=NULL;
                    cout<<"Element deleted from last"<<endl;
                }
                else
                    cout<<"Element deleted from mid"<<endl;
                delete temp;
            }
        }
        else
        {
            prev=curr;
            curr=curr->next;
        }
        if(curr!=NULL)
            rec(a,curr,prev);
            else
                cout<<"Element NOT FOUND"<<endl;
    }
    void deletelast()
    {
        node *curr,*prev;
        curr=start;
        prev=NULL;
        if(start==NULL)
        {
            cout<<"EMPTY LIST!"<<endl;
        }
        else
        {
            while(curr->next!=NULL)
            {
                prev=curr;
                curr=curr->next;
            }
            if(prev==NULL)
            {
                start=NULL;
                delete(curr);
                cout<<"The list is empty now."<<endl;
            }
            else
            {
                prev->next=NULL;
                delete curr;
                cout<<"Last element deleted"<<endl;
            }
        }
    }
    void display()
    {
        node *temp;
        temp=start;
        if(start==NULL)
        {
            cout<<"EMPTY LIST";
        }
        else
        {
            cout<<"The list is \t";
            while(temp!=NULL)
            {
                cout<<temp->data<<"\t";
                temp=temp->next;
            }
            cout<<endl;
        }
    }
};
main()
{
    Operations list;
    int choice;
    do
    {
        cout<<"1.Insert front\t 2. Insert middle\t 3. Insert last\n4. Delete front\t 5. Delete middle\t 6. Delete last\n7. Display\t 0. END"<<endl;
        cout<<"Enter choice :";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Insert data at begining\n";
            list.insertfront();
            break;
        case 2:
            cout<<"Insert data at middle\n";
            list.insertmid();
            break;
        case 3:
            cout<<"Insert data at last\n";
            list.insertlast();
            break;
        case 4:
            cout<<"Delete data from begining\n";
            list.deletebeg();
            break;
        case 5:
            cout<<"Delete data from middle\n";
            list.deletemid();
            break;
        case 6:
            cout<<"Delete data from last\n";
            list.deletelast();
            break;
        case 0:
            break;
        case 7:
            list.display();
            break;
        default:
            cout<<"INVALID COMMAND\n";
        }
    }while(choice!=0);
}
