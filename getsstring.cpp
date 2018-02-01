#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<list>
#include<stack>
#include<map>
#include<queue>
#include<string>
#include<bitset>

#include<ctime>
#include<cstdlib>

using namespace std;

#define DETAILS


clock_t clock_start_time;
clock_t clock_end_time; 

clock_t clock_running_start_time;
clock_t clock_running_end_time;

int random_value;

void start_sign()
{
	printf("\n==start==\n");
} 


void end_sign()
{
	printf("\n==end===\n");
} 


int lengthof(char * str)
{
	int count=0;
	for(int i=0;*str!='\0';i++)
	{
		count++;	
	}
	
	return count;
	
}



int main()
{
	#ifdef DETAILS
	 clock_start_time=clock();
	 
	 //random value
	 srand(time(NULL));
	 random_value=rand();
	 
	 start_sign();
	 #endif
	 
	 //init value
	 int pos=-1;
	 int currentpos=0;
	 int time=0;
	 int same=0;
	 int flagsize=0;
	 int strsize=0;
	 string flag(10,'\0');
	 string A(10,'\0');
	 A.resize(10);
	 
	 // ‰»Î input
	 scanf("%s",&flag[0]);
	 flagsize=lengthof(&flag[0]);
	 

	 
     //detail time
	 #ifdef DETAILS
	 clock_running_start_time=clock();
	 #endif
	 
	 //running program
	 while(scanf("%s",&A[0])==1)
	 {
	 	strsize=lengthof(&A[0]);
	 	
	 	
	 	if(flagsize==strsize)
	 	{
	 		int i=0;
	 		for(i=0;i<flagsize;i++)
	 		{
	 			if(!(A[i]==flag[i]||A[i]==flag[i]+32||A[i]==flag[i]-32))  break;
	 		}
	 		
	 		if(i==flag.size()-1) time++;
	 		
	 		
	 		if(time==1) pos=currentpos;
	 		
	 		
	 	}
	 	currentpos+=A.size()+1;
	 	A.clear();
	 }

	 //detail time
	 clock();
	 #ifdef DETAILS
	 clock_running_end_time=clock();
	 #endif	 
	 
	 // ‰≥ˆ output
	 if(pos==-1) 
	 {
	 	printf("-1");
	 }
	 else
	 {
	 	printf("%d %d",time,pos);
	 }
	 

	 
	 
	 
	 
	 
	#ifdef DETAILS 
	clock_end_time=clock();
	 
	//convert cpu time to (ms)
	double cpu_time_used=1000.0*(clock_end_time-clock_start_time)/CLOCKS_PER_SEC;
	
	double cpu_time_running=1000.0*(clock_running_end_time-clock_running_start_time)/CLOCKS_PER_SEC;
	
	end_sign();
	printf("\ntotal cpu_time_used:%f ms",cpu_time_used);
	printf("\nrunning cpu_time_used:%lf ms",cpu_time_running);
	#endif	
	 
	
	return 0;
} 


