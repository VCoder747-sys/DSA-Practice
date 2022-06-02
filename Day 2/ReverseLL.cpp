#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *next;
    node (int val)
    {
        data =val;
        next = NULL;
    }
};

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


void ReverseLL(node* &head)
{
    node *curr = head;
    node *prev = NULL, *next = NULL;
    while (curr != NULL) 
    {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
}


void RecursiveReverseLL(node* head)
{
    if(head==NULL)
        return;
    RecursiveReverseLL(head->next);
    cout<<head->data<<"->";
}

main()
{
    node *head = NULL;
    insertattail(head,1);
    insertattail(head,2);
    insertattail(head,3);
    insertattail(head,4);
    insertattail(head,5);
    insertattail(head,6);
    print(head);
    ReverseLL(head);
    print(head);
    cout<<"\n";
    RecursiveReverseLL(head);
}