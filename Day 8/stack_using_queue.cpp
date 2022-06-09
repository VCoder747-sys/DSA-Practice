#include<bits/stdc++.h>
using namespace std;

class Stack {
    public: 
    queue<int> q1;
    queue<int> q2;

    void pushS(int x)
    {
        q1.push(x);
    }

    int popS()
    {
        if(q1.empty())
            return -1;
        while(q1.size()!=1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int val=q1.front();
        q1.pop();
        while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        return val;
    }
    
};


main()
{
    Stack s;
    s.pushS(1);
    s.pushS(2);
    s.pushS(3);
    s.pushS(4);
    cout<<s.popS()<<" ";
    cout<<s.popS()<<" ";

}