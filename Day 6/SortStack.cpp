#include<bits/stdc++.h>
using namespace std;

void SortedInsert(stack<int> &st, int e)
{
    if(st.empty() || e>st.top())
        st.push(e);
    else
    {
        int temp = st.top();
        st.pop();
        SortedInsert(st,e);
        st.push(temp);
    }    
}


void SortStack(stack<int> &st)
{
    if(st.empty())
        return;
    else
    {
        int temp=st.top();
        st.pop();
        SortStack(st);
        SortedInsert(st,temp);
    }
}

void printStack(stack<int>st)
{
    while(!st.empty())
    {
        cout<<st.top()<<"\n";
        st.pop();
    }
}

main()
{
    stack<int> st;
    st.push(30);
    st.push(-5);
    st.push(18);
    st.push(14);
    st.push(-3);
 
    cout << "Stack elements before sorting:\n";
    printStack(st);
 
    SortStack(st);
    cout << "\n";
 
    cout << "Stack elements after sorting:\n";
    printStack(st);
 
    return 0;
}
