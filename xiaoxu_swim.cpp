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




int main()
{
	#ifdef DETAILS
	 clock_start_time=clock();
	 
	 //random value
	 srand(time(NULL));
	 random_value=rand();
	 
	 start_sign();
	 #endif
	 
	 
	 double swim_target=0.0;
	 double current=0.0;
	 double step=2.0;
	 int number=0;
	 
	 scanf("%lf",&swim_target);
	 
	 while(current<swim_target)
	 {
	 	current+=step;
	 	step *=0.98;
	 	number++;
	 	
	 }
	 printf("%d",number);
	 
	 
	 
	 
	#ifdef DETAILS 
	clock_end_time=clock();
	 
	//convert cpu time to (ms)
	double cpu_time_used=1000.0*(clock_end_time-clock_start_time)/CLOCKS_PER_SEC;
	
	end_sign();
	printf("\ncpu_time_used:%f ms",cpu_time_used);
	
	#endif	
	 
	
	return 0;
} 


