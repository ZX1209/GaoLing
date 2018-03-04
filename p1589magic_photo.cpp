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



struct twoint{
	int left;
	int right;
};


struct test{
	bool operator()(twoint first,twoint second)
	{
		if(first.right>second.right)
		{
			return true;
		}
		else if(first.right==second.right)
		{
			if(first.left<=second.left)
			{
				return  true;
			}
			else{
				return false;
			}
		}
		else{
			return false;
		}
		
	}

	
} twointcmp;


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
	 int E[10];      
	 int n,k;
	 
	 twoint example={0,0};
	 
	 
	 
	 //ÊäÈë input
	 scanf("%d %d",&n,&k);
	 vector<twoint> V(n,example);
	 
	 for(int i=0;i<10;i++) 
	 {
		   scanf("%d",&E[i]);
	 }
	 
	 for(int i=0;i<n;i++)
	 {
	 	V[i].left=i+1;
	 	scanf("%d",&V[i].right);
	 }
	 
	 sort(V.begin(),V.end(),twointcmp);
	 
	 for(int i=0;i<n;i++)
	 {
	 	V[i].right+=E[i%10];
	 }
	 
	 sort(V.begin(),V.end(),twointcmp);
	 for(int i=0;i<k;i++)
	 {
	 	printf("%d ",V[i].left);
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


