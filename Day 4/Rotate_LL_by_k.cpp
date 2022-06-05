#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *next;

    node(int d)
    {
        data =d;
        next =NULL;
    }
};

void print(node *head)
{
    cout<<"\n";
    node* temp =head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
}


void insertLL(node *&head,int data)
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

void rotateLLbyK(node *& head,int k)
{
    node* temp = head;
    node* prev =head;
    for(int i=0;i<k;i++)
    {   
        prev=head;
        head=head->next;
    }
    prev->next=NULL;
    node * temp2= head;
    while(temp2->next !=NULL)
        temp2=temp2->next;
    temp2->next=temp;
}

main()
{
    node * head =NULL;
    insertLL(head,10);
    insertLL(head,20);
    insertLL(head,30);
    insertLL(head,40);
    insertLL(head,50);
    insertLL(head,60);
    print(head);
    rotateLLbyK(head,4);
    print(head);
}