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


struct pos
{
	int a;
	int b;
	int g;
	int k;
};

pos poss[10001];



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
	 int n;
	 int a,b,g,k;
	 int findit=0;
	 
	 
	 
	 // ‰»Î input
	 scanf("%d",&n);
	 for(int i=1;i<=n;i++)
	 {
	 	scanf("%d %d %d %d",&a,&b,&g,&k);
	 	poss[i].a=a;
	 	poss[i].b=b;
	 	poss[i].g=g;
	 	poss[i].k=k;
	 	
	 }
	 
	 scanf("%d %d",&a,&b);
	 
//	 for(int i=1;i<=n;i++)
//	 {
//	 	printf("%d %d %d %d\n",poss[i].a,poss[i].b,poss[i].g,poss[i].k);
//	 	
//	 }
	 
	 
     //detail time
	 #ifdef DETAILS
	 clock_running_start_time=clock();
	 #endif
	 
	 //running program
	 for(int i=n;i>=1;i--)
	 {
	 	if(a>=poss[i].a&&a<=poss[i].a+poss[i].g&&b>=poss[i].b&&b<=poss[i].b+poss[i].k) 
		 {
		 	findit=1;
		 	printf("%d",i);
		 	break;
		 }
		 	
	 }
	 
	 
	 if(!findit)
	 printf("-1");

	 //detail time
	 clock();
	 #ifdef DETAILS
	 clock_running_end_time=clock();
	 #endif	 
	 
	 // ‰≥ˆ output
	 

	 
	 
	 
	 
	 
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


