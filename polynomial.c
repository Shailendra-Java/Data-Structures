#include<stdio.h>
#include<stdlib.h>
struct node
{
	int coeff;
	int expo;
	struct node* link;
};
struct node* one=NULL;
struct node* two=NULL;
struct node* sum=NULL;
void append1()
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the next data of first polynomial");
	printf("\nEnter the coefficient:");
	scanf("%d",&temp->coeff);
	fflush(stdin);
	printf("\nEnter the expo:");
	scanf("%d",&temp->expo);
	fflush(stdin);
	temp->link=NULL;
	if(one==NULL)
	   one=temp;
	 else
	 {
	 	struct node* p=one;
	 	while(p->link!=NULL){
		 	puts("inside loop "); 
		 p=p->link; 
		}
			p->link=temp;
		
	   }     
}
void append2()
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the next data of second polynomial");
	printf("\nEnter the coefficient:");
	scanf("%d",&temp->coeff);
	printf("\nEnter the expo:");
	scanf("%d",&temp->expo);
	temp->link=NULL;
	if(two==NULL)
	   two=temp;
	 else
	 {
	 	struct node* p=two;
	 	while(p->link!=NULL)
	 	   p=p->link;
	 	p->link=temp;   
	   }   
}
void appendsum(int a,int b)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->coeff=a;
    temp->expo=b;
    temp->link=NULL;
	if(sum==NULL){
	   sum=temp;
	   puts("inside 3");
	}
	 else
	 {
	 	struct node* p=sum;
	 	while(p->link!=NULL){
	 		puts("inside 8");
	 	   p=p->link;
	 }
	 	p->link=temp;   
	   }     
}
void display()
{
	struct node* temp=sum;
	while(temp!=NULL)
	{
		printf("%dx^%d+",temp->coeff,temp->expo);
		temp=temp->link;
	}
}
void finalsum()
{
	struct node* temp1=one;
	struct node* temp2=two;
	struct node* temp3=sum;
	while((temp1!=NULL)&&(temp2!=NULL))
	{
		puts("inside 1");
		if(temp1->expo==temp2->expo)
		{
			puts("inside 5");
			appendsum(temp1->coeff+temp2->coeff,temp1->expo);
			temp1=temp1->link;
			temp2=temp2->link;
					}
		else if(temp1->expo>temp2->expo)
		{
			puts("inside 4");
		  appendsum(temp1->coeff,temp1->expo);	
		  temp1=temp1->link;
		}
		else
		{
			puts("inside 2");
			appendsum(temp2->coeff,temp2->expo);	
		  temp2=temp2->link;
		}
	}
	while(temp1!=NULL)
	{
		puts("inside 6");
	temp1=temp1->link;
	 appendsum(temp1->coeff,temp1->expo);
	}
    while(temp2!=NULL)
	{
		puts("inside 7");
	temp2=temp2->link;
	 appendsum(temp2->coeff,temp2->expo);
	}
}

void main()
{
	int choice;
	printf("\nEnter the term of first polynomial");
	append1();
	while(1)
	{
		printf("\n1.Enter more");
		printf("\n2.Exit");
		scanf("\n%d",&choice);
		if(choice==1)
		  append1();
		  else
		   break;	
		           
	
		}
	printf("\nEnter the term of second polynomial");
		append2();
	while(1)
	{
	
		printf("\n1.Enter more");
		printf("\n2.Exit");
		scanf("%d",&choice);
		if(choice==1)
		  append2();
		  else
		    break;	
		}	
	finalsum();
	display();
}
