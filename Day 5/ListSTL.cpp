#include<bits/stdc++.h>
using namespace std;

void printList(list<int> L)
{
    cout<<endl;
    for(auto it:L)
        cout<<it<<"->";
}

main()
{
    list<int> l;
    for(int i=0;i<5;i++)
        l.push_back(i+1);
    for(int i=6;i<10;i++)
        l.push_front(i*2);
    printList(l);
    l.pop_back();
    l.pop_front();
    printList(l);
    l.remove(12);
    printList(l);
    l.reverse();  
    printList(l) ;
    l.sort();
    printList(l);  
    cout<<"\n"<<l.size();   
}