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

int random_value;

void start_sign()
{
	printf("\n==start==\n");
} 


void end_sign()
{
	printf("\n==end===\n");
} 



//special code



int main()
{
	#ifdef DETAILS
	 clock_start_time=clock();
	 
	 //random value
	 srand(time(NULL));
	 random_value=rand();
	 
	 start_sign();
	 #endif
	 
	 
	 //progroming
	 char buffer[100];
	 int tmpi=0;
	 double tmpd=0.0;
	 sprintf(buffer,"this is a %s ,%d %f\n","amazing day",1,2.3);
	 printf(buffer); 
	 
	 sscanf("thisis 23.7897987","%*[a-z] %lf",&tmpd); 
	 
	 printf("\n\n%lf",tmpd);
	 
	 
	 
	 
	 
	 
	#ifdef DETAILS 
	clock_end_time=clock();
	 
	//convert cpu time to (ms)
	double cpu_time_used=1000.0*(clock_end_time-clock_start_time)/CLOCKS_PER_SEC;
	
	end_sign();
	printf("\ncpu_time_used:%3.3f ms",cpu_time_used);
	
	#endif	
	 
	
	return 0;
} 


