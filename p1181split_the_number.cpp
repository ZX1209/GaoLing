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
	 long n,m;
	 long tmpi; 
	 vector<long> V;
	 long result=0;
	 
	 
	 
	 // ‰»Î input
	 scanf("%ld %ld",&n,&m);
	 
	 for(int i=0;i<n;i++)
	 {
	 	scanf("%ld",&tmpi);
	 	V.push_back(tmpi);
	 	
	 }
	 
     //detail time
	 #ifdef DETAILS
	 clock_running_start_time=clock();
	 #endif
	 
	 tmpi=0;
	 //running program
	 for(int i=0;i<V.size();i++)
	 {
	 	tmpi+=V[i];
	 	
	 	if(tmpi>m)
	 	{
	 		tmpi=V[i];
	 		result++;
	 	}
	 	else if(tmpi==m)
	 	{
	 		tmpi=0;
	 		result++;	
	 	}
	 	else;
	 	
	 }
	 
	 if(tmpi!=0) result++;
	 //detail time
	 clock();
	 #ifdef DETAILS
	 clock_running_end_time=clock();
	 #endif	 
	 
	 // ‰≥ˆ output
	 printf("%ld",result);
	 
	 

	 
	 
	 
	 
	 
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


