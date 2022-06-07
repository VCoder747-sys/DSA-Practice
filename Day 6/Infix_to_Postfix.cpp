#include<bits/stdc++.h>
using namespace std;

/*
1. Scan the infix expression from left to right. 
2. If the scanned character is an operand, output it. 
3. Else, 
      1 If the precedence and associativity of the scanned operator is greater than the precedence and associativity of the operator in the stack(or the stack is empty or the stack contains a ‘(‘ ), push it.

      2 ‘^’ operator is right associative and other operators like ‘+’,’-‘,’*’ and ‘/’ are left associative. Check especially for a condition when both top of the operator stack and scanned operator are ‘^’. In this condition the precedence of scanned operator is higher due to it’s right associativity. So it will be pushed in the operator stack. In all the other cases when the top of operator stack is same as scanned operator we will pop the operator from the stack because of left associativity due to which the scanned operator has less precedence. 
      3 Else, Pop all the operators from the stack which are greater than or equal to in precedence than that of the scanned operator. After doing that Push the scanned operator to the stack. (If you encounter parenthesis while popping then stop there and push the scanned operator in the stack.) 
4. If the scanned character is an ‘(‘, push it to the stack. 
5. If the scanned character is an ‘)’, pop the stack and output it until a ‘(‘ is encountered, and discard both the parenthesis. 
6. Repeat steps 2-6 until infix expression is scanned. 
7. Print the output 
8. Pop and output from the stack until it is not empty.*/


 bool isoperator(char ch)
    {
        if(ch=='+' || ch=='-' || ch=='*' || ch=='/' ||ch=='^')
            return true;
        return false;    
    }


string InfixtoPostfix(string s) {
    
        
        string ans="";
        int n=s.size();
        map<char,int> precedence;
        precedence['(']=4;
        precedence[')']=4;
        precedence['^']=3;
        precedence['*']=2;
        precedence['/']=2;
        precedence['+']=1;
        precedence['-']=1;
        stack<char> st;
        for(int i=0;i<n;i++)
        {
            if(!isoperator(s[i]) && s[i]!='(' && s[i]!=')')
                ans+=s[i];
            else if(s[i]=='(')
                st.push(s[i]);
            else if(isoperator(s[i]))
            {
                if(st.empty())
                    st.push(s[i]);
                else if(st.top()=='(')
                    st.push(s[i]);
                else if(isoperator(st.top()))
                {
                    if(precedence[st.top()]>=precedence[s[i]])
                    {
                        ans+=st.top();
                        st.pop();
                        st.push(s[i]);
                    }
                    else
                    {
                        st.push(s[i]);
                    }
                    
                }
                
            }
            else if(s[i]==')')
            {
                
                while(st.top()!='(')
                {
                    ans+=st.top();
                    st.pop();
                }
                st.pop();
                
            }
                
        }
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        
        return ans;
    }

main()
{
    string a = "(1+2)*3";
    string b = InfixtoPostfix(a);
    cout<<b;
}