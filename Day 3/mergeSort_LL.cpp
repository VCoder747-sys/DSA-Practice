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

//Merge 2 sorted LL
node* merge2Lists(node* l1, node* l2)
{
    if (l1==NULL)
        return l2;
    if (l2==NULL) 
        return l1;
    node* head = l1->data <= l2->data? l1:l2;
    head->next = l1->data <= l2->data ? merge2Lists(l1->next, l2) : merge2Lists(l1, l2->next);
    return head;
}

//Split List in 2 hlves and store head of each halves at front and back ptrs passed as arguments
void SplitList(node* source, node*& front, node*& back) 
{ 
	node* ptr1; 
	node* ptr2; 
	ptr2 = source; 
	ptr1 = source->next; 

	// ptr1 is incrmented twice and ptr2 is icremented once.
	while (ptr1 != NULL) { 
		ptr1 = ptr1->next; 
		if (ptr1 != NULL) { 
			ptr2 = ptr2->next; 
			ptr1 = ptr1->next; 
		} 
	} 

	// ptr2 is at the midpoint.
	front = source; 
	back = ptr2->next; 
	ptr2->next = NULL; 
} 



// Merge Sort
void MergeSort(node*& thead) 
{ 
	node* head = thead; 
	node* ptr1; 
	node* ptr2; 
    // Base Case
    if ((head == NULL) || (head->next == NULL)) { 
		return; 
	} 

	// Splitting list
	SplitList(head, ptr1, ptr2); 

	// Recursively sorting two lists.
	MergeSort(ptr1); 
	MergeSort(ptr2); 

	// Sorted List.
	thead = merge2Lists(ptr1, ptr2); 
} 

main()
{
    node *head =NULL;
    insertLL(head,4);
    insertLL(head,7);
    insertLL(head,2);
    insertLL(head,1);
    insertLL(head,5);
    print(head);
    MergeSort(head);
    print(head);
    

}