#include<iostream>
#include<stdio.h>  

using namespace std; 

int main()
{
	char opt='\0';
	char str[100]={'\0'};
	int i=0;
	
	char c;
	while(1)
	{
		
		if(scanf("command:%c;",&opt)==1)
		{
			switch(opt)
			{
				case 'p':
					getchar();
					
					while((c=getchar())!='\n'&&c!=EOF){
						str[i++]=c;
					 }
					 str[i]='\0';
					 i=0;
					printf("%s\n",str);
					break;
				case 'b':
					printf("this is what you want??\n");
					break;
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
