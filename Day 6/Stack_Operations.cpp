#include<bits/stdc++.h>
using namespace std;

class STACK
{
    int top=-1;
    vector<int> v;
    public:
    void push(int s)
    {
        v.push_back(s);
        top++;
    }

    void pop()
    {
        v.pop_back();
        top--;
    }

    int size()
    {
        return top+1;
    }

    int attop()
    {
        return v[top];
    }

    void isempty()
    {
        if(top==-1)
            cout<<"\n Empty Stack";
        else
            cout<<"\n Not Empty";
    }

};

main()
{
    STACK st;
    st.isempty();
    st.push(10);
    st.push(22);
    st.push(35);
    st.push(46);
    cout<<"\n"<<st.size();
    cout<<"\n"<<st.attop();
    st.pop();
    st.pop();
    cout<<"\n"<<st.size()<<" "<<st.attop();
}