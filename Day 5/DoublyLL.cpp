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

class DoublyLinkedList
{
    node* head;
    node* tail;

 
public:

    DoublyLinkedList()
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
    DoublyLinkedList L;
    L.pushFront(1);
    L.pushFront(2);
    L.pushFront(3);
    L.pushBack(4);
    L.pushBack(5);
    L.PrintBackward();
    L.PrintForward();
    L.deleteFront();
    L.deleteLast();
    L.PrintForward();
}