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

void swap(int* T,int start,int end)
{
	T[start]=T[start]^T[end];
	T[end]=T[end]^T[start];
	T[start]=T[start]^T[end];
	
	return;
}


//x,y all can be indexed!
void quick_sort(int* T,int x,int y)
{
	if(y-x==2)
	{ 
		if(T[x]>T[y])
		{
			swap(T,x,y);
		}
		else
		{
			return;
		}
	} 
	else if(x==y)
	{
		return;
	}
	else if(y-x<0)
	{
		return;
	}
	else;
	
	//see the first element as the middle value
	//tmp
	int left=x+1;
	int right=y;
	
	//
	
	while(left<right)
	{
		if(T[left]<=T[x])
		{
			left++;
		}
		else
		{
			while(left<right&&T[right]>T[x])
			{
					right--;
			}
			
			swap(T,left,right);
			
		}
		
	}
	
	
	if(T[left]>=T[x])
	{
		swap(T,left,x);
		
	}
	else
	{
		left++;
	}		
	
	//µü´ú 
	quick_sort(T,x,left-1);
	quick_sort(T,left+1,y);
	
	
	
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
	 int N;
	 int n;
	 int V[100001];
	 
	 //ÊäÈë input
	 scanf("%d",&N);
	 
	 
	 for(int i=0;i<N;i++)
	 {
	 	scanf("%d",&n);
		 V[i]=n; 
	 }
	 
	 
	 
	 quick_sort(V,0,N-1);
	 
	 
	 
	 for(int i=0;i<N;i++)
	 {
	 	printf("%d ",V[i]); 
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


