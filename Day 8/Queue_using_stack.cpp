#include<bits/stdc++.h>
using namespace std;


class Queue {
    stack<int> input, output;
public:

    void enqueue(int x) {
        input.push(x);
    }

    int dequeue() {
        while(!input.empty())
        {
            output.push(input.top());
            input.pop();
        }
         int t=output.top();
         output.pop();
        while(!output.empty())
        {
            input.push(output.top());
            output.pop();
        }
        return t;
    }


};

main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    cout<<q.dequeue()<<" ";
    cout<<q.dequeue()<<" ";



}