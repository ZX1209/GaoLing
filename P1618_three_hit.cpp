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

inline int times(int val,int time)
{
	int result=1;
	for(int i=0;i<time;i++){
		result*=val;
	}
	
	return result;
}

int getdigit(int value,int digit)
{
	//printf("getdigit:%d %d\n",value,digit);
	return (value/times(10,digit-1))%10;
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
	 int a,b,c;
	 int digit[9]={0};
	 int AB=0;
	 int AC=0;
	 int chen=1;
	 int hen=0;
	 int have=0;
	 
	 
	 
	 //ÊäÈë input
//	 while(1)
//	 {
//	 	scanf("%d %d",&v,&d);
//	 	getchar();
//	 	printf("result:%d\n",getdigit(v,d));
//	 	
//	 }

	scanf("%d %d %d",&a,&b,&c);
	 
     //detail time
	 #ifdef DETAILS
	 clock_running_start_time=clock();
	 #endif
	 
	 //running program
	 for(int i=123;i<987;i++)
	 {
	 	AB=(i*b)/a;
	 	AC=(i*c)/a;
	 	
	 	digit[0]=getdigit(i,1);
	 	digit[1]=getdigit(i,2);
	 	digit[2]=getdigit(i,3);
	 	digit[3]=getdigit(AB,1);
	 	digit[4]=getdigit(AB,2);
	 	digit[5]=getdigit(AB,3);
	 	digit[6]=getdigit(AC,1);
	 	digit[7]=getdigit(AC,2);
	 	digit[8]=getdigit(AC,3);
	 	
	 	
	 	for(int j=0;j<9;j++)
	 	{
	 		chen*=digit[j];
	 		hen+=digit[j]; 
	 	}
	 	
	 	if(AB>987||AC>987) continue;
	 	
	 	if(chen==362880&&hen==45)
	 	{
	 		have=1;
	 		printf("%d %d %d\n",i,AB,AC);
	 	}
	 	
	 	chen=1;
	 	hen=0;
	 	
	 }
	 
	 if(!have) printf("No!!!");

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


