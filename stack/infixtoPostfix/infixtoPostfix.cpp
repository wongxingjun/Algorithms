#include <iostream>
#include <cstring>
#include "mystack.h"
using namespace std;
#define MAX 1000
bool isOperand(char c)
{
    if((c>='a'&c<='z')||(c>='A'&&c<='Z'))
        return true;
    else
        return false;
}

int precedence(char c)
{
    switch(c)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    }
    return -1;
}


int main()
{
    char expr[MAX];
    cin>>expr;
    Stack st(strlen(expr));
    int i,k;
    i=0;
    k=-1;
    for(; expr[i]; i++)
    {
        if(isOperand(expr[i]))
            expr[++k]=expr[i];
        else if(expr[i]=='(')
            st.push(expr[i]);
        else if(expr[i]==')')
        {
            while(!st.isEmpty()&&st.pick()!='(')
                expr[++k]=st.pop();
            if(!st.isEmpty()&&st.pick()!='(')
            {
                cout<<"Invalid expression"<<endl;
                return 0;
            }
            else
                st.pop();
        }
        else
        {
            while(!st.isEmpty()&&precedence(expr[i])<=st.pick())
                expr[++k]=st.pop();
            st.push(expr[i]);
        }

    }
    while(!st.isEmpty())
        expr[++k]=st.pop();
    expr[++k]='\0';
    cout<<expr<<endl;
    return 0;
}
