#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node* right;
    node (int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};

void preorder(node *root)
{
    if(root==NULL)
        return;
    cout<<" "<<root->data;
    preorder(root->left);
    preorder(root->right);
}

void inorder(node *root)
{   
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<" "<<root->data;
    inorder(root->right);
}

void postorder(node *root)
{
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<" "<<root->data;    
}

void levelorder(node *root)
{   
    if(root==NULL)
        return;
    queue <node *> Q;
    Q.push(root);
    Q.push(NULL);
    while(!Q.empty())
    {
        node *Node=Q.front();
        Q.pop();
        if(Node!=NULL)
        {
            
            cout<<" "<<Node->data;
            if(Node->left)
                Q.push(Node->left);
            if(Node->right)
                Q.push(Node->right);
        }
        else if(!Q.empty())
            Q.push(NULL);

    }
}


//Function to find Height of tree: O(n)
int HeightofTree(node* root)
{
    if(root==NULL)
        return 0;
    int lheight=HeightofTree(root->left);
    int rheight=HeightofTree(root->right);
    return max(lheight,rheight)+1;    
}

//Function to find Diameter of Tree: O(n^2)
int DiameterofTree(node* root)
{   
    if(root==NULL)
        return 0;
    int lheight=HeightofTree(root->left);
    int rheight=HeightofTree(root->right);
    int curr_diameter=lheight+rheight+1;
    int ldiameter=DiameterofTree(root->left);
    int rdiameter=DiameterofTree(root->right);
    return max(curr_diameter,max(ldiameter,rdiameter));
}

//Optimized Function to find diameter of Tree: O(n)
int calcDiameter(node* root,int* height)
{   
    if(root==NULL)
    {
        *height=0;
        return 0;
    }
    int lh=0,rh=0;
    int ldiameter=calcDiameter(root->left,&lh);
    int rdiameter=calcDiameter(root->right,&rh);
    int curr_diameter=lh+rh+1;
    *height=max(lh,rh)+1;
    return max(curr_diameter,max(ldiameter,rdiameter));
}



int main()
{
    struct node *root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);
    /*
            1
           / \
          2   3
         / \ / \
        4  5 6  7
    */ 
    cout<<"\n Preorder:";
    preorder(root);
    cout<<"\n Inorder: ";
    inorder(root);
    cout<<"\n Postorder: ";
    postorder(root);
    cout<<"\n Levelorder: ";
    levelorder(root);
    cout<<"\n Height of Tree: "<<HeightofTree(root);
    cout<<"\n Diameter of Tree: "<<DiameterofTree(root);
    int height=0;
    cout<<"\n Diameter of Tree with more efficiency: "<<calcDiameter(root,&height);
    /*        28
           / \
          11  16 
         / \ / \
        4  5 6  7
    */ 
    preorder(root);

    node* root2=new node(1);
    root2->left=new node(2);
    root2->left->left=new node(3);
    /*
            1
           /
          2
         /
        3    

    */
    
   return 0; 
}