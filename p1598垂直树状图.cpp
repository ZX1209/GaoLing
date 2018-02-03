#include<stdio.h>
#include<cstring>
#include<algorithm> 
int main()
{
	 
	 //init value
	 char tmpc;
	 int hz[26]={0};
	 int end=0;
	 int max=0;
	 int endpos=25;
	 char a[81];     
	 //输入 input	 
	for(int i=0;i<4;i++)
    {
        gets(a);//gets读入
        endpos=strlen(a);
        for(int j=0;j<endpos;j++)if(a[j]>='A'&&a[j]<='Z')hz[a[j]-'A']++;//统计字符出现次数
    }
	 //running program
	 max=*std::max_element(hz,hz+26);
	 
	 
	 while(max>=1)
	 {

	 	for(endpos=25;endpos>0;endpos--)
	 	{
	 		if(hz[endpos]>=max) break;
	 	}	
	 	for(int i=0;i<=endpos;i++)
	 	{
	 		if(hz[i]>=max) printf("* ");
	 		else if(hz[i]!=0) printf("  "); 
	 	}
	 	printf("\n");
	 	max--;
	 }
	 
 	for(endpos=25;endpos>0;endpos--)
 	{
 		if(hz[endpos]!=0) break;
 	}
 
 	for(int i=0;i<endpos;i++)
 	{
 		printf("%c ",'A'+i);
 		
 	}
 	
 	printf("%c",'A'+endpos);
	 
	 //输出 output
	
	
	return 0;
} 


