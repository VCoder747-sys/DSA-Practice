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


node * rotate_in_k(node* head, int k)
{
    stack<node*> st;
    node* current = head;
    node* prev = NULL;
 
    while (current != NULL) 
    {
        int count = 0;
        while (current != NULL && count < k) 
        {
            st.push(current);
            current = current->next;
            count++;
        }
        while (st.size() > 0) 
        {
            if (prev == NULL)
            {
                prev = st.top();
                head = prev;
                st.pop();
            }
            else
            {
                prev->next = st.top();
                prev = prev->next;
                st.pop();
            }
        }
    }
    prev->next = NULL;
 
    return head;
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
    node * ans =rotate_in_k(head,2);
    print(ans);
}