#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node *next;
        node(int d)
        {
            data=d;
            next= NULL;
        }
};

void print(node *head)
{	
	cout<<"\n";
	node* temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<"->";
		temp=temp->next;
	}
}
/*
ALGORITHM
1. Search for keys d1 and d2, if any of them is not present return.
2. While searching for x and y, keep track of current and previous pointers.
3. First change next of previous pointers, then change next of current pointers. 

*/
void swapNodes(node *&head, int d1,int d2)
{
    if(d1==d2)
        return;
    node *prev1 =NULL;
    node *curr1 = head;
    while(curr1 != NULL && curr1->data!=d1)
    {
        prev1 = curr1;
        curr1 = curr1->next;
    }

    node *prev2 =NULL;
    node *curr2 = head;
    while(curr2 != NULL && curr2->data!=d2)
    {
        prev2 = curr2;
        curr2 = curr2->next;
    }
    
    //Any of the value don't find in LL
    if(curr1 == NULL || curr2 == NULL)
        return;

    // CHANGING THE NEXT OF PREVIOUS POINTERS
    // Case 1: if d1 is not head
    if (prev1 != NULL)
        prev1->next = curr2;  //prev of d1 points to d2
    else 
        head = curr2;   //d1 is head, make d2 as head
    
    //Case 2: if d2 is not head
    if (prev2 != NULL)
        prev2->next = curr1;  //prev of  d2 points to d1
    else 
        head = curr1;
 
    // CHANGING THE NEXT OF CURRENT POINTERS
    node* temp = curr2->next;
    curr2->next = curr1->next;
    curr1->next = temp;    
}
void insertintohead(node *&head,int data)
{
	node *n=new node(data);
	n->next=head;
	head=n;
}

main()
{
    node *head=NULL;
    insertintohead(head,5);
	insertintohead(head,4);
	insertintohead(head,3);
    insertintohead(head,6);
    insertintohead(head,7);
    insertintohead(head,8);
    insertintohead(head,9);
    print(head);
    swapNodes(head,7,4);
    print(head);
}