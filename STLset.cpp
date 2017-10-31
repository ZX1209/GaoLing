#include<iostream>
#include<set>
#include<string>

using namespace std;

int main()
{
	set<string> str;
	str.insert("apple");
	str.insert("orange");
	str.insert("banana");
	str.insert("grapes");
	set<string>::iterator pos;
	
	for(pos=str.begin();pos!=str.end();pos++)
	{
		cout<<*pos<<" ";
	}
	cout<<endl;
	str.clear();
	return 0;
}
