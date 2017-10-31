#include<iostream>
#include<list>

using namespace std;

int main()
{
	list< int > mylist(5,100);
	mylist.push_front(-13);
	mylist.push_back(300);
	list<int>::iterator p = mylist.begin();
	mylist.erase(p);
	
	for(p=mylist.begin();p!=mylist.end();p++)
	{
		cout<<* p<<" ";
	}
	
	cout<<endl;
	cout<<mylist.size()<<endl;
	
	mylist.clear();
}
