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


class CircularLL 
{
    node* head;
  
public:
    
    CircularLL() 
    { 
        head = NULL; 
    }

    void printList()
    {
        cout<<"\n";
	    node* temp=head;
        temp=temp->next;
        cout<<head->data<<"->";
	    while(temp!=head)
	    {
		    cout<<temp->data<<"->";
		    temp=temp->next;
	    }
    }

    int lengthoflist()
    {
        if(head==NULL)
            return 0;
	    int len=1;
        node* temp=head;
        temp=temp->next;
	    while(temp!=head)
	    {
		    temp=temp->next;
		    len++;
	    }
	    return len;
    }

    void insertattail(int data)
    {
	    if(head==NULL)
	    {
		    head=new node(data);
            head->next=head;
		    return;
	    }
	    else
	    {
		    node* tail=head;
            tail=tail->next;
		    while(tail->next!=head)
			    tail=tail->next;
		    tail->next=new node(data);
            tail->next->next = head;
            return;	
	    }
    }

    void insertintomiddle(int data,int p)
    {
	    if(head==NULL||p==0)
        {
            
		    head=new node(data);
            head->next=head;
		    return;
        }
		   
	    else if(p>lengthoflist())
	        insertattail(data);
	
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
    
    void deletiontohead()
    {
        if(head == NULL)
            return;
        else if(head->next==head)
        {
            head=NULL;
            return;
        }    
        node * temp =head->next;    
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        temp->next=head->next;
        head=head->next;

    }
    
    void deletionattail()
    {
        if(head==NULL)
            return;

        else if(head->next==head)
        {
            head=NULL;
            return;
        }    
        else
        {
            
            node* tail=head;
            node* prev=NULL;
            while(tail->next!=head)
            {
            prev=tail;
            tail=tail->next;
            }	
            delete tail;
            prev->next=head;
        }
    }

    void deletioninmiddle(int p)
    {
        if(p==lengthoflist()-1)
        {
            deletionattail();
            return;
        }
        
        node* temp = head;
        node* prev = NULL;
        int i=0;
        if(temp != NULL && p==0)
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

};

main()
{
    CircularLL L;
    L.insertattail(1);
    L.insertattail(2);
    L.insertattail(3);
    L.insertattail(4);
    L.printList();
    L.deletioninmiddle(3);
    L.printList();
}