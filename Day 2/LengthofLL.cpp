#include<bits/stdc++.h>
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

//length of linked list Itrative
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

int  recursiveLength(node *head)
{
    if(head==NULL)
        return 0;
    return 1 + recursiveLength(head->next);    
}


//Insertion at head of Linked List
void insertintohead(node *&head,int data)
{
	node *n=new node(data);
	n->next=head;
	head=n;
}

main()
{
    node *head=NULL;
    insertintohead(head,5);
	insertintohead(head,4);
	insertintohead(head,3);
    cout<<"\n Length of linked list: "<<lengthoflist(head);
    cout<<"\n Length of List (Recursive): "<<recursiveLength(head);
}