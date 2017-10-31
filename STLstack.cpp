#include<stack>
#include<stdio.h>
#include<iostream>

using namespace std;


int main()
{
	stack<int> test;
	
	
	char opt='\0';
	int tmp=0;
	int flag=1;
	
	char c;
	while(flag)
	{
		
		if(scanf("opt:%c;",&opt)==1)
		{
			switch(opt)
			{
				case 'p':
					printf("push:");
					scanf("%d;",&tmp);
					test.push(tmp);
					
					break;
				case 'o':
					if(!test.empty())
					test.pop();
					break;
				case 's':
				    cout<<test.size()<<endl;
					break;
					
				case 'e':
					cout<<test.empty()<<endl;
					break;
					
				case 't':
					
					if(!test.empty())
					cout<<test.top();
					printf("not correct!\n");
					
					break;
				case 'q':
					flag=0;
					
				default:
					printf("not correct!\n");
					
					break;
			}
			
		}
		else{
			while((c=getchar())!='\n'&&c!=EOF);
		}
		
    }

	return 0;
} 
