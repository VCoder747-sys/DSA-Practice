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

/* 

ALGORITHM: 
1. Reverse both LL
2. Addd them
3. Reverse the Resulting LL

*/
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

node* AddLL(node*h1, node* h2)
{
    //Reverse both LL
    ReverseLL(h1);
    ReverseLL(h2);
    
    //Find Addition of LL, store it in Ans
    node* ans=NULL;
    int carry=0;
    while(h1!=NULL && h2!=NULL)
    {
        int sum=h1->data + h2->data + carry;
        int d=sum%10;
        insertLL(ans,d);
        carry=sum/10;
        h1=h1->next;
        h2=h2->next;
    }

    while(h1!=NULL)
    {
        int sum=h1->data + carry;
        int d=sum%10;
        insertLL(ans,d);
        carry=sum/10;
        h1=h1->next;
    }

    while(h2!=NULL)
    {
        int sum= h2->data + carry;
        int d=sum%10;
        insertLL(ans,d);
        carry=sum/10;
        h2=h2->next;
    }
    while(carry!=0)
    {
        int sum=carry;
        int d=sum%10;
        insertLL(ans,d);
        carry=sum/10;
    }
    
    //Reverse Ans LL
    ReverseLL(ans);
    return ans;
}

main()
{
    node * h1=NULL;
    node * h2=NULL;

    insertLL(h1,9);
    insertLL(h1,9);
    insertLL(h1,9);
    insertLL(h2,9);
    insertLL(h2,9);
    insertLL(h2,9);
    print(h1);
    print(h2);
    node * ans=AddLL(h1,h2);
    print(ans);



}