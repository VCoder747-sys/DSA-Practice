#include<bits/stdc++.h>
using namespace std;

template<typename T>
class node{
    public:
    T data;
    node<T> *next;
   
};

template<typename Q>
class Queue{
    public:
    node<Q> *head=NULL;

    bool empty()
    {
        if(head==NULL)
            return true;
        else
            return false;    
    }

    void push(Q d)
    {
            node<Q>* nptr = new node<Q>;
            nptr->data = d;
            nptr->next=NULL;
            if(empty()){
                head = nptr;
            }else{
                node<Q>* temp = head;
                while(temp->next != NULL){
                    temp = temp->next;
                }
                temp->next = nptr;
            }
    }

    void pop()
    {
       if(empty())
       {
                cout<<"queue is empty"<<endl;
                return;
        }
        head = head->next;
    }

    void print()
    {
        node<Q> *temp = head;
        cout<<"\n";
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }

   

};



main()
{
    Queue<string> av;
    av.push("hello");
    av.push("world");
    av.push("NSUT");
    av.push("abc");
    av.push("def");
    av.print();
    av.pop();
    av.print();



}