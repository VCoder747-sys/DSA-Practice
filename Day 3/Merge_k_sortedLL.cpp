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


node* merge2Lists(node* l1, node* l2) {
        if (l1==NULL)
            return l2;
        if (l2==NULL) 
            return l1;
        node* head = l1->data <= l2->data? l1:l2;
        head->next = l1->data <= l2->data ? merge2Lists(l1->next, l2) : merge2Lists(l1, l2->next);
        return head;
    }

node *mergeLL( vector<node*> &v)
{
    if (v.size() == 0) 
        return NULL;
        node* head = v[0];
        
        for (int i = 1; i < v.size(); i++)
            head = merge2Lists(head, v[i]);
        
        return head;
}

main()
{
    vector<node*> v;
    node* h1 = NULL, *h2 =NULL, *h3=NULL;
    insertLL(h1,1);
    insertLL(h1,4);
    insertLL(h1,5);
    insertLL(h2,1);
    insertLL(h2,3);
    insertLL(h2,4);
    insertLL(h3,2);
    insertLL(h3,6);
    print(h1);
    print(h2);
    print(h3);
    v.push_back(h1);
    v.push_back(h2);
    v.push_back(h3);
    node *merge =  mergeLL(v);
    print(merge);
}