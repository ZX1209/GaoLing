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

#define printInt(x) printf(#x " = %d",(x));
#define printFloat(x) printf(#x " = %f",(x));

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

void test_start_sign()
{
	printf("\n==test_start==\n");
} 


void test_end_sign()
{
	printf("\n==test_end===\n");
}

int N,sum;
vector<int> V;
vector<int> Set;
int flag=0;


inline int Cp(int base,int n)
{
	int upbase=1;
	int downbase=1;
	
	for(int i=(base-n+1);i<=base;i++)
	{
	    upbase*=i;
	    //cout<<"upbase : "<<upbase<<endl;
	}
	
	for(int i=1;i<=n;i++)
	{
	    downbase*=i;
	    //cout<<"downbase : "<<downbase<<endl;
	}
	
	return upbase/downbase;	
}      



void dloop(int n,int loopsum)
{ 
	if(!flag) 
	{
		if(loopsum<=sum)
		{
			if(n<=1)
			{	 
				if(!flag)
				{	
					int tmpint=sum-loopsum;
					if(tmpint>0&&tmpint<=N&&Set[tmpint]==0)
					{
						for(int i=N;i>1;i--)
						{
							printf("%d ",V[i]);	
						}
						printf("%d ",tmpint);
						flag=1;
						
					}
				} 
				return;
					
			}
			else
			{
				int tmploopsum=0;
				for(int i=1;i<=N;i++)
				{
					if(Set[i]==0)
					{
						Set[i]=1;
						V[n]=i;
						tmploopsum=loopsum+Cp(N-1,n-1)*i;
						dloop(n-1,tmploopsum);
						Set[i]=0;
						
					}
					
				}
				return;
				
			}
			
		}
		
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
	 scanf("%d %d",&N,&sum);
	 V.resize(N+1);
	 Set.resize(N+1); 
	 
	 
	 //ÊäÈë input
	 
     //detail time
	 #ifdef DETAILS
	 clock_running_start_time=clock();
	 #endif
	 
	 //test unit!!
	 #ifdef DETAILS
	 test_start_sign();
	 
	 //unit test

	 test_end_sign();
	 
	 
	 #endif
	 
	 //running program
	 dloop(N,0);

	 //detail time
	 clock();
	 #ifdef DETAILS
	 clock_running_end_time=clock();
	 #endif	 
	 
	 //Êä³ö outputh
	 

	 
	 
	 
	 
	 
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


