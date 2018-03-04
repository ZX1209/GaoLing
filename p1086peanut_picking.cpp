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

int M,N,k;

vector<vector<int> > land;

struct twoint
{
	int start;
	int end;
};

twoint findMax()
{
	 int max=0;
	 twoint pos={0,0};
	 for(int i=0;i<M;i++)
	 {
	 	for(int j=0;j<N;j++)
	 	{
	 		if(max<land[i][j])
	 		{
	 			max=land[i][j];
	 			pos.start=i;
	 			pos.end=j;
	 		}
	 	}
	 }
	 
	 if(max=0) pos={-1,-1}; 
	 
	 return pos;
	
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
	 

	 int result=0;
	 twoint cpos={0,0};
	 twoint npos={0,0};
	 int dis=0;
	 
	 
	 //ÊäÈë input
	 scanf("%d %d %d",&M,&N,&k);
	 land.resize(M);
	 for(int i=0;i<M;i++)
	 {
	 	land[i].resize(N);
	 }
	 
	 
	 for(int i=0;i<M;i++)
	 {
	 	for(int j=0;j<N;j++)
	 	{
	 		scanf("%d",&land[i][j]);
	 	}
	 }
	 
     //detail time
	 #ifdef DETAILS
	 clock_running_start_time=clock();
	 #endif
	 
	 cpos=findMax();
	 cpos.start=-1;
	 //running program
	 while(1)
	 {
	 	
	 	npos=findMax();
	 	//printf("%d %d %d %d %d\n",cpos.start,cpos.end,npos.start,npos.end,k);
	 	if(npos.start==-1) break;
	 	
	 	dis=(abs(cpos.start-npos.start)+abs(cpos.end-npos.end));
	 	
	 	if(k-dis-1>npos.start) 
		 {
		 	k-=(dis+1);
		 	cpos=npos;
		 	result+=land[cpos.start][cpos.end];
		 	land[cpos.start][cpos.end]=0;
		 }
		 else
		 {
		 	break;
		 }
	 	
	 	
	 	
	 }

	 //detail time
	 clock();
	 #ifdef DETAILS
	 clock_running_end_time=clock();
	 #endif	 
	 
	 //Êä³ö output
	 
	 printf("%d\n",result);

	 
	 
	 
	 
	 
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


