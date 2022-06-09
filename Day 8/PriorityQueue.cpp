#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    int priority; //Lower value -> higher priority
    node *next;
    node(int d, int p)
    {
        data=d;
        priority=p;
        next=NULL;
    }

};

class PQueue 
{
    node * head;
    public:
    PQueue()
    {
        head=NULL;
    }

    bool empty()
    {
        return head==NULL;
    }

    void push(int d, int p)
    {
        node* temp = new node(d,p);
        if(head==NULL)
            head=temp;
        else if(head->priority > p)
        {
            temp->next=head;
            head=temp;
        }
        else
        {
            node * t = head;
            while (t->next != NULL && t->next->priority < p) {
                t = t->next;
        }
 
        temp->next = t->next;
        t->next = temp;
        }
    }

    void pop()
    {
        head=head->next;
    }

    int peek()
    {
        return head->data;
    }

};


main()
{
    PQueue q;
    q.push(5,2);
    q.push(6,3);
    q.push(7,0);
    while (!q.empty()) {
        cout << " " << q.peek();
        q.pop();
    }
}