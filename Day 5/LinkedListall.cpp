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


class Linkedlist 
{
    node* head;
  
public:
    
    Linkedlist() 
    { 
        head = NULL; 
    }

    void printList()
    {
        cout<<"\n";
	    node* temp=head;
	    while(temp!=NULL)
	    {
		    cout<<temp->data<<"->";
		    temp=temp->next;
	    }
    }

    int lengthoflist()
    {
	    int len=0;
	    while(head!=NULL)
	    {
		    head=head->next;
		    len++;
	    }
	    return len;
    }
  
    void insertintohead(int data)
    {
	    node *n=new node(data);
	    n->next=head;
	    head=n;
    }

    void insertattail(int data)
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

    void insertintomiddle(int data,int p)
    {
	    if(head==NULL||p==0)
		    insertintohead(data);
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
        cout<<"\n Deleting head: ";
	    head=head->next;
    }
    
    void deletionattail()
    {
        if(head==NULL)
            return;
        else
        {
            cout<<"\n Deleting Tail: ";
            node* tail=head;
            node* prev=NULL;
            while(tail->next!=NULL)
            {
            prev=tail;
            tail=tail->next;
            }	
            delete tail;
            prev->next=NULL;
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
        if (temp != NULL && p==0)
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

    void ReverseLL()
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

    void swapNodes(int d1,int d2)
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

    void FloydAlgorithm()
    {
        node* slow =head;
        node* fast =head;
        while(slow!=NULL && fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                cout<<"Loop Exists"<<endl;
                return;
            }
        }
        cout<<"Loop Doesn't Exists"<<endl;
    }

    void removeLoop()
    {
        //Step 1: Find a Node inside the loop using Floyd algorithm or any other algo
        node* slow =head;
        node* fast =head;
        while(slow!=NULL && fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                break;
            }
        }
        //Step 2: Count number of Nodes in Loop, let it be K;
        int k=1;
        slow=slow->next;
        while(slow!=fast)
        {
            slow=slow->next;
            k++;
        }

        //Step 3: place ptr1 on head and ptr 2 on K links ahead of head.
        slow =head;
        fast = head;
        for(int i=0;i<k;i++)
            fast=fast->next;

        //Step 4: Move both pointers at same pace, they will meet at starting point of Loop.
        while(slow!=fast)
        {
            slow=slow->next;
            fast=fast->next;
        }     
        
        //Step 5: Move Second ptr, till previus of first. Second is now at Last node. make its next as null.
        while(fast->next!=slow)
            fast=fast->next;
        fast->next=NULL;    
    }

    void rotateLLbyK(int k)
    {
        node* temp = head;
        node* prev =head;
        for(int i=0;i<k;i++)
        {   
            prev=head;
            head=head->next;
        }
        prev->next=NULL;
        node * temp2= head;
        while(temp2->next !=NULL)
            temp2=temp2->next;
        temp2->next=temp;
    }

    node * rotate_in_k(int k)
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


};

main()
{
    Linkedlist L;
    L.insertattail(1);
    L.insertattail(2);
    L.insertattail(3);
    L.insertattail(4);
    L.printList();
    L.ReverseLL();
    L.printList();
    L.swapNodes(4,1);
    L.printList();
}