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


int wa[21][21][21]={0};


int w(long long a,long long b,long long c)
{
	
	
	
	if(a<=0||b<=0||c<=0) return 1;
	
	else if(a>20||b>20||c>20) return w(20,20,20);
	
	else if(wa[a][b][c]!=0) return wa[a][b][c];
	
	else if(a<b&&b<c)                                 
	{
		wa[a][b][c]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
		return wa[a][b][c];
		
	} 
	else
	{
		wa[a][b][c]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
		return wa[a][b][c];
	} 
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
	 long long a,b,c;
	 
	 
	 
	 //ÊäÈë input
	 while(1)
	 {
	 	scanf("%lld %lld %lld",&a,&b,&c);
	 	if(a==-1&&b==-1&&c==-1) break;
	 	else
	 	{
	 		printf("w(%lld, %lld, %lld) = %d\n",a,b,c,w(a,b,c));
	 	}
	 }
	 
     //detail time
	 #ifdef DETAILS
	 clock_running_start_time=clock();
	 #endif
	 
	 //running program

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


