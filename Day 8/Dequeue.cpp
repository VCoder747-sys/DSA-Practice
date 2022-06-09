#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *next;
    node *prev;

    node(int d)
    {
        data =d;
        next =NULL;
        prev =NULL;
    }
};

class Dequeue
{
    node* head;
    node* tail;

 
public:

    Dequeue()
    {
        head = NULL;
        tail = NULL;
    }

    void pushFront(int d)
    {
        if(head==NULL)
        { 
           head=new node(d);
           tail =head;
        }
        else
        {
            node* temp=new node(d);
            temp->next=head;
            head->prev=temp;
            head=temp;
        }
    }

    void pushBack(int d)
    {
        if(tail==NULL)
        {  
             tail=new node(d);
            head=tail;
        }
        else
        {
            node* temp=new node(d);
            tail->next=temp;
            temp->prev=tail;
            tail=temp;
        }
    }

    void deleteFront()
    {
        if(head==NULL)
            return;
        head=head->next;
        head->prev=NULL;    
    }

    void deleteLast()
    {
        if(tail==NULL)
            return;
        tail=tail->prev;
        tail->next=NULL;    
    }

    void PrintForward()
    {
        cout<<"\n";
        node* temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<"->";
            temp=temp->next;
        }
    }

    void PrintBackward()
    {
        cout<<"\n";
        node*temp=tail;
        while(temp!=NULL)
        {
            cout<<temp->data<<"->";
            temp=temp->prev;
        }
    }


};

main()
{
    Dequeue dq;
    dq.pushFront(1);
    dq.pushFront(2);
    dq.pushFront(3);
    dq.pushBack(4);
    dq.pushBack(5);
    dq.PrintBackward();
    dq.PrintForward();
    dq.deleteFront();
    dq.deleteLast();
    dq.PrintForward();
}