//Name	:	Dinesh Suthar
//RegNo	:	2022ca108
//Aim:	:	Implementation of Doubly linked list

#include<iostream>
using namespace std;

struct node{
	int data;
	node *next=NULL,*prev=NULL;
}*head=NULL,*tail=NULL,*temp=NULL,*p1=head;

void insertStart(int data)
{
	node *newNode=new node;
	newNode->data=data;
	newNode->prev=NULL;
	newNode->next=NULL;
	if(head!=NULL)
	{
		head->prev=newNode;
		newNode->next=head;
		head=newNode;
	}
	else
		head=tail=newNode;
}

void insertEnd(int data)
{
	node *newNode=new node;
	newNode->data=data;
	newNode->prev=NULL;
	newNode->next=NULL;
	if(head!=NULL)
	{
		tail->next=newNode;
		newNode->prev=tail;
		tail=newNode;
	}
	else
		head=tail=newNode;
}
void popFront()
{
	if(head==NULL)
		cout<<"List is Empty";
	else
	{
		node *t=head;
		head=head->next;
		head->prev=NULL;
		delete t;
	}
}
void popBack()
{
	if(head==NULL)
		cout<<"List is Empty";
	else
	{
		node *t=tail;
		tail=tail->prev;
		tail->next=NULL;
		delete t;
	}
}

void insertPos(int data,int pos)
{
	node *newNode=new node;
	newNode->data=data;
	newNode->prev=NULL;
	newNode->next=NULL;
	temp=head;
	if(head==NULL)
		head=newNode;
	else
	{
		int i=1;
		while(i!=pos)
		{
			temp=temp->next;
			i++;
			if(temp==tail)
			{
				cout<<"Position is greater than List";
				return;
			}
		}
		node *t=temp->next;
		temp->next=newNode;
		newNode->prev=temp;
		newNode->next=t;
		t->prev=newNode;
	}
}

void printList()
{
	node* temp=head;
	while(temp!=NULL)
	{
		if(temp->next==NULL)
			cout<<temp->data;
		else
			cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<endl;
}

int main()
{
	int choice,val;
	do{
		cout<<"\n1.Insert Start  /  2.Insert Position  /  3.Insert End  /  4.Delete Front  /  5.Delete Back\n";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Enter Value:";
				cin>>val;
				insertStart(val);
				printList();
				break;
			case 2:
				int pos;
				cout<<"Enter Value & val:";
				cin>>val>>pos;
				insertPos(val,pos);
				printList();
				break;
			case 3:
				cout<<"Enter Value:";
				cin>>val;
				insertEnd(val);
				printList();
				break;
			case 4:
				popFront();
				printList();
				break;
			case 5:
				popBack();
				printList();
				break;
		}
	}while(choice<=5);
	printList();
	return 0;
}
