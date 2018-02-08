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


 //init value
 int n;
 int k;
 int x[20];
 int total=0;
 int repeat_time=1;

inline int isprimer(int number)
{
	for(int i=2;i<=sqrt(number);i++)
	{
		if(number%i==0) return 0;
	}
	return 1;
	
}

void dfs(int pos,int sum,int get)
{
	if(get==k||pos==n)
	{
		if(get==k&&isprimer(sum)) total++;
		return;
	}
	
	dfs(pos+1,sum+x[pos],get+1);
	dfs(pos+1,sum,get); 
	return;
}



void chose_loop(int step,int sum,int pos)
{
	int tmpval=x[pos];
	sum+=x[pos];
	x[pos]=0;
	
	
	if(step==k)
	{
		if(isprimer(sum)) total++;
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			if(x[i]!=0) chose_loop(step+1,sum,i);	
		}
		
	}
	
	x[pos]=tmpval;
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
	 

	 
	 //ÊäÈë input
	 scanf("%d %d ",&n,&k);
	 for(int i=0;i<n;i++)
	 {
	 	scanf("%d",x+i);	
	 }
	 for(int i=1;i<=k;i++)
	 {
	 	repeat_time*=i;
	 }
	 
	 
	 
     //detail time
	 #ifdef DETAILS
	 clock_running_start_time=clock();
	 #endif
	 
	 //running program
	 dfs(0,0,0);
	 

	 //detail time
	 clock();
	 #ifdef DETAILS
	 clock_running_end_time=clock();
	 #endif	 
	 
	 //Êä³ö output
	 printf("%d",total);
	 

	 
	 
	 
	 
	 
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


