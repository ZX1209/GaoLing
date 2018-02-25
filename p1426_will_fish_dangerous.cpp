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
	 double s,x;
	 double speed=7;
	 double dis=0;
	 
	 
	 
	 //ÊäÈë input
	 scanf("%lf %lf",&s,&x);
	 
     //detail time
	 #ifdef DETAILS
	 clock_running_start_time=clock();
	 #endif
	 
	 //running program
	 
	 while(1)
	 {
	 	if(dis>s-x)
	 	{ 
	 	 	//printf("%lf %lf %lf %lf\n",dis,speed,s,x);
	 		
	 	 	dis+=speed;
		 	speed*=0.98;
		 	//printf("%lf %lf %lf %lf\n",dis,speed,s,x);
		 	if(dis>s+x) printf("n");
		 	else printf("y");
		 	
		 	break;
	 		
	 	}
	 	
	 	
	 	//printf("%lf %lf %lf %lf\n",dis,speed,s,x);
	 	dis+=speed;
	 	speed*=0.98;
	 	
	 	

	 	
	 	
	 }
	 
	 
	 

	 //detail time
	 clock();
	 #ifdef DETAILS
	 clock_running_end_time=clock();
	 #endif	 
	 
	 //Êä³ö output
	 

	 
	 
	 
	 
	 
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


