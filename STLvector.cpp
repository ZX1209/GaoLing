#include<vector>
#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
	int n;
	
	cin>>n;
	vector<int> test(n);
	for(int i=0;i<n;i++)
	cin>>test[i];
	
	for(int i=0;i<n;i++)
	cout<<test[i]<<endl;
	return 0;
}
