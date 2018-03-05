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

struct studentinfo{
	int i;
	int yw;
	int sx;
	int yy;
	int sum;
};

bool cmp(studentinfo a,studentinfo b)
{
	if(a.sum==b.sum)
	{
		if(a.yw==b.yw)
		{
			return a.i<b.i;
		}
		else{
			return a.yw>b.yw;
		}
	}
	else{
		return a.sum>b.sum;
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
	 int n;
	 studentinfo V[302];
	 
	 
	 
	 
	 // ‰»Î input
	 scanf("%d",&n);
	 
	 for(int i=1;i<=n;i++)
	 {
	 	V[i].i=i;
	 	scanf("%d %d %d",&V[i].yw,&V[i].sx,&V[i].yy);
	 	V[i].sum=V[i].yw+V[i].sx+V[i].yy;
	 }
	 
	 sort(V+1,V+n+1,cmp);
	 
	 
	 for(int i=1;i<=5;i++) printf("%d %d\n",V[i].i,V[i].sum);
	 
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


