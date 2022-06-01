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

//Insertion at Tail
void insertattail(node *&head,int data)
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


//Deletion at head of Linked List
void deletiontohead(node *&head)
{
    if(head == NULL)
        return;
        cout<<"\n Deleting head: ";
	head=head->next;
}

//Deletion at Tail of Linked LIst 
void deletionattail(node *&head)
{
	if(head==NULL)
		return;
	else
	{
		cout<<"\n Deleting Tail: ";
		node* tail=head;
		node* prev=NULL;
		while(tail->next!=NULL)
		{
		prev=tail;
		tail=tail->next;
		}	
		delete tail;
		prev->next=NULL;
	}
}
//Deletion in middle of node at position p
void deletioninmiddle(node *&head,int p)
{

	cout<<"\n Deleting at index "<<p<<": ";
	if(p==lengthoflist(head)-1)
	{
		deletionattail(head);
		return;
	}
	
	node* temp = head;
    node* prev = NULL;
    int i=0;
    if (temp != NULL && p==0)
    {
        head = temp->next; 
        delete temp;
    }
 
   else
    {
    	while (temp != NULL && i!=p)
    	{
        	prev = temp;
        	temp = temp->next;
        	i++;
    	}
 
    	prev->next = temp->next;
    	delete temp;
    }

}	

main()
{	
	node* head=NULL;
	insertattail(head,12);
	insertattail(head,3);
	insertattail(head,5);
	insertattail(head,16);
	insertattail(head,19);
	insertattail(head,20);
	cout<<lengthoflist(head);
	print(head);
	deletiontohead(head);
	print(head);
	deletionattail(head);
	print(head);
	deletioninmiddle(head,2);
	print(head);
	deletioninmiddle(head,0);
	print(head);
	deletioninmiddle(head,lengthoflist(head)-1);
	print(head);
	
}
