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
	 int i[9];
	 char c[10];
	 char tmpc;
	 int tmpi=0;
	 char result;
	 
	 // ‰»Î input
	 for(int j=0;j<9;)
	 {
	 	scanf("%c",&tmpc);
		if(tmpc!='-')
		{
			c[j]=tmpc;
			i[j]=c[j]-'0';
			j++;
		}  
	 }
	 
	 
	 
     //detail time
	 #ifdef DETAILS
	 clock_running_start_time=clock();
	 #endif
	 
	 //running program
	 for(int j=0;j<9;j++)
	 {
	 	tmpi+=(j+1)*i[j];
	 	
	 }
	 
	 tmpi%=11;
	 
	 if(tmpi==10) result='X';
	 else result=tmpi+'0';
	 
	 scanf("-%c",&c[9]);
	 
	 if(c[9]==result) printf("Right");
	 else 
	 {
	 	c[9]=result;
	 	printf("%c-%c%c%c-%c%c%c%c%c-%c",c[0],c[1],c[2],c[3],c[4],c[5],c[6],c[7],c[8],c[9]);	
	 }
	 
	 
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


