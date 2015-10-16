#include<iostream>
#include<stack>
using namespace std;


void insert(stack<int> *s, int item)
{
	int tmp;
	if(s->empty()||item<s->top())
	{
		s->push(item);
		return;
	}
	tmp=s->top();
	s->pop();
	insert(s,item);
	s->push(tmp);
}

void sort(stack<int> *s)
{
	int tmp;
	if(!s->empty())
	{
		tmp=s->top();
		s->pop();
		sort(s);
		insert(s,tmp);
	}
}



int main()
{
	stack<int> s;
	int i=0;
	for(;i<10;i++)
		s.push(i);
	sort(&s);
	while(!s.empty())
	{
		cout<<s.top()<<endl;
		s.pop();
	}
	return 0;
}
