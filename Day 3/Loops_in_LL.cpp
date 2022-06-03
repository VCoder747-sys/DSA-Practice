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

// DETECTING LOOPS
//METHOD 1 : Use mapping to keep track of Visited Nodes/Data 
void LoopusingMap(node * head)
{
    unordered_map<int,bool> visited;
    while(head != NULL)
    {
        if(visited[head->data])
        {
            cout<<"Loop Exists"<<endl;
            return;
        }
        else
        visited[head->data]=true;
        head=head->next;
    }
    cout<<"Loop Doesn't Exists"<<endl;
}

//Method 2: Detection of Loop Using Sets
void LoopUsingSets(node *head)
{
    unordered_set<node*> s;
    while(head!=NULL)
    {
        if(s.find(head)!=s.end())
        {
            cout<<"Loop Exists"<<endl;
            return;
        }
        else
        s.insert(head);
        head=head->next;
    }
    cout<<"Loop Doesn't exists"<<endl;
}

//METHOD 3: Modify LL structure and add a parameter Visited with each node.
//METHOD 4: Floyd'c Cycle Finding Algorithm

void FloydAlgorithm(node *head)
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
 //METHOD 5: Using temprory Node - each traversed node must points its next to this temp node. 



 // REMOVAL OF LOOPS
 void removeLoop(node *&head)
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

main()
{
    node *head1 = NULL, *head2=NULL;
    insertLL(head1,1);
    insertLL(head1,2);
    insertLL(head1,3);
    insertLL(head1,4);
    insertLL(head1,5);
    
    insertLL(head2,11);
    insertLL(head2,12);
    insertLL(head2,13);
    //creating a Loop
    head1->next->next->next = head1;
    
    LoopusingMap(head1);
    LoopusingMap(head2);
    LoopUsingSets(head1);
    LoopUsingSets(head2);
    FloydAlgorithm(head1);
    FloydAlgorithm(head2);
    removeLoop(head1);
    FloydAlgorithm(head1);
}