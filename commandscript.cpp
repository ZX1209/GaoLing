#include<stdio.h>
#include<iostream>
#include<string> 

using namespace std;




int main()
{
	string command;
	
	
	while(1)
	{
		cin>>command;
		
		if(command=="quit")
		{
			cout<<"quit"<<endl;
			break;
		}
		
		cout<<command<<endl;
	}
	
	
	
	return 0;
}
