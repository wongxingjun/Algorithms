#include <iostream>
#include <stack>
using namespace std;

int insertBottom(stack<int> *s, int item)
{
	int tmp;
	if(s->empty())
		s->push(item);
	else
	{
		tmp=s->top();
		s->pop();
		insertBottom(s, item);
		s->push(tmp);
	}
	return 0;
}

int  reverse(stack<int> *s)
{
	int tmp;
	if(!s->empty())
	{
		tmp=s->top();
		s->pop();
		reverse(s);
		insertBottom(s,tmp);
	}
	return 0;
}


int main()
{
	stack<int> s;
	int i;
	for(i=0;i<10;i++)
		s.push(i);
	reverse(&s);
	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}
	return 0;
}
