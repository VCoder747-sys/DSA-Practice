/* https://leetcode.com/problems/implement-stack-using-queues/submissions/  */

#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node*next;
    node(int d)
    {
        data=d;
        next=NULL;
    }
    
};



class MyStack 
{
public:
    node *head;
    MyStack() {
        head=NULL;
    }
    
    void push(int x) {
       if(head==NULL)
           head=new node(x);
        else
        {
            node *n=new node(x);
	        n->next=head;
	        head=n;
        }
    }
    
    int pop() {
        if(head == NULL)
            return -1;
        else
        {
            int x= head->data;
            head=head->next;
            return x;
        }
	    
    }
    
    int top() {
        return head->data;
    }
    
    bool empty() {
        if(head==NULL)
            return true;
        else
            return false;
    }
};

