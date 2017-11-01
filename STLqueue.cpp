#include<iostream>
#include<queue>

using namespace std;

int main()
{
	queue<int> q;
	q.push(1);q.push(2);q.push(3);q.push(4);
	cout<<q.size()<<endl;
	cout<<q.empty()<<endl;
	cout<<q.front()<<endl;
	cout<<q.back()<<endl;
	
	while(q.empty()!=true)
	{
		cout<<q.front()<<" ";
		q.pop();
	}
	
	
	
	
	return 0;
}
