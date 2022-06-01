#include<iostream>
using namespace std;

class node
{	public:
	int data;
	node *next;
	node(int d)
	{
		data=d;
		next=NULL;
	}
};

//Print Linked list
void print(node *head)
{	
	cout<<"\n";
	node* temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<"->";
		temp=temp->next;
	}
}

//length of linked list
int lengthoflist(node *head)
{
	int len=0;
	while(head!=NULL)
	{
		head=head->next;
		len++;
	}
	return len;
}

//Insertion at head of Linked List
void insertintohead(node *&head,int data)
{
	node *n=new node(data);
	n->next=head;
	head=n;
}

//Insertion at Tail of Linked LIst 
void insertattail(node *head,int data)
{
	if(head==NULL)
	{
		head=new node(data);
		return;
	}
	else
	{
		node* tail=head;
		while(tail->next!=NULL)
			tail=tail->next;
		tail->next=new node(data);
		return;	
	}
}
//Insertion in middle of node at position p
void insertintomiddle(node *&head,int data,int p)
{
	if(head==NULL||p==0)
	{
		insertintohead(head,data);
	}
	else if(p>lengthoflist(head))
	{
		insertattail(head,data);
	}
	else
	{
		int jump=1;
		node *temp=head;
		while(jump<=p-1)
		{
			temp=temp->next;
			jump++;
		}
		node *n=new node(data);
		n->next=temp->next;
		temp->next=n;
	}

}	

main()
{	
	node* head=NULL;
	insertintohead(head,5);
	insertintohead(head,4);
	insertintohead(head,3);
	print(head);
	insertintomiddle(head,9,2);
	print(head);
	insertattail(head,12);
	print(head);
}
