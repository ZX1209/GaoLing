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

inline int isprimer(int number)
{
	for(int i=2;i<=sqrt(number);i++)
	{
		if(number%i==0) return 0;
	}
	return 1;
	
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
	 int theodd;
	 
	 
	 //ÊäÈë input
	 scanf("%d",&theodd);
	 
	 
	 
     //detail time
	 #ifdef DETAILS
	 clock_running_start_time=clock();
	 #endif
	 
	 //running program
//	 for(int i=theodd;i>1;i--)
//	 {
//	 	//confirm the first largest primer number
//	 	if(isprimer(i))
//	 	{
//	 		for(int j=2;j<theodd;j++)
//	 		{
//	 			//confirm the second largset primer number
//	 			if(isprimer(j))
//	 			{
//	 				if(isprimer(theodd-i-j)&&theodd-i-j>=j)
//	 				{
//	 					printf("%d %d %d",j,theodd-i-j,i);
//	 					return 0;
//	 				}
//	 			}
//	 		}
//	 	}
//	 }

	for(int i=2;i<theodd;i++)
	{
		if(isprimer(i))
		{
			for(int j=i;j<theodd;j++)
			{
				if(isprimer(j))
				{
					if(isprimer(theodd-i-j)&&theodd-i-j>=j)
					{
						printf("%d %d %d",i,j,theodd-i-j);
	 					return 0;
					}
					
				}
				
			}
			
		}
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


