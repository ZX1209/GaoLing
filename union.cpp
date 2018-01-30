#include<iostream>
#include<string>
#include<sstream>
using namespace std;

union uniontest
{
	double d;
	char c;
};


int main()
{
	uniontest test1={1.2};
	cout<<test1.c<<endl;
	return 0;
	
}
