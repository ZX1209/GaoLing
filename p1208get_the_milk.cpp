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


struct milkinfo{
	long P;
	long A;
};

bool cmp(milkinfo a,milkinfo b)
{
	return a.P<b.P;
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
	 long N,M;
	 vector<milkinfo> V;
	 milkinfo tmpm;
	 long getm=0,cost=0;
	 
	 // ‰»Î input
	 scanf("%ld %ld",&N,&M);
	 
	 
	 for(int i=0;i<M;i++)
	 {
	 	scanf("%ld %ld",&tmpm.P,&tmpm.A);
	 	V.push_back(tmpm);
	 }
	 
     //detail time
	 #ifdef DETAILS
	 clock_running_start_time=clock();
	 #endif
	 
	 //running program
	 sort(V.begin(),V.end(),cmp);
	 
	 for(int i=0;getm<N&&i<V.size();i++)
	 {
	 	//printf("%d :%ld %ld \n",i,V[i].P,V[i].A);
	 	long need=N-getm;
	 	if(need>=V[i].A)
	 	{
	 		getm+=V[i].A;   
	 		cost+=V[i].P*V[i].A;
	 		
	 	}
	 	else
	 	{
	 		getm+=need;
	 		cost+=V[i].P*need;
	 	}
	 	
	 	 
	 	
	 }
	 
	 
	 

	 //detail time
	 clock();
	 #ifdef DETAILS
	 clock_running_end_time=clock();
	 #endif	 
	 
	 // ‰≥ˆ output
	 printf("%ld",cost);

	 

	 
	 
	 
	 
	 
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


