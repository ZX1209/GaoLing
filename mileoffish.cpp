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

#include<ctime>
#include<cstdlib>


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
	 int week=0;
	 int n=0;
	 int totalmiles=0;
	 
	 // ‰»Î input
	 scanf("%d %d",&week,&n);
	 
	 
     //detail time
	 #ifdef DETAILS
	 clock_running_start_time=clock();
	 #endif
	 
	 //running program
	 int applesheight[10]={0};
	 int height=0;
	 int result=0;
	 for(int i=0;i<10;i++)
	 {
	 	scanf("%d",&applesheight[i]);
	 }
	 getchar();
	 
	 scanf("%d",&height);
	 

	 for(int i=0;i<10;i++)
	 {
	 	if(applesheight[i]<=height+30)  result++;
	 }	 
	 
	 
	 
	 // ‰≥ˆ output
	 printf("%d",result);
	 
	 
	 //detail time
	 #ifdef DETAILS
	 
	 clock_running_end_time=clock();
	 
	 #endif	 

	 
	 
	 
	 
	 
	#ifdef DETAILS 
	clock_end_time=clock();
	 
	//convert cpu time to (ms)
	double cpu_time_used=1000.0*(clock_end_time-clock_start_time)/CLOCKS_PER_SEC;
	
	double cpu_time_running=1000.0*(clock_running_end_time-clock_running_start_time)/CLOCKS_PER_SEC;
	
	end_sign();
	
	printf("\ntotal cpu_time_used:%10.3f ms",cpu_time_used);
	
	printf("\nrunning cpu_time_used:%10.3f ms",cpu_time_running);
	#endif	
	 
	
	return 0;
} 


