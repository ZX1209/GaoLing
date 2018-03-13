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

void test_start_sign()
{
	printf("\n==test_start==\n");
} 


void test_end_sign()
{
	printf("\n==test_end===\n");
}

int N,M,T;
int sx,sy,fx,fy;
int zx,zy;
int result=0;

vector<vector<int> > V;

void fromto(int x,int y)
{
	if(x>0&&x<=N&&y>0&&y<=M)
	{
		if(V[x][y]!=0) return;
		
		if(x==fx&&y==fy)
		{
			result++;
			return;	
		}
		

		
		V[x][y]=1;
		fromto(x-1,y);
		fromto(x+1,y);
		fromto(x,y-1);
		fromto(x,y+1);
		V[x][y]=0;		
	}
	
	return;

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

	 
	  
	 
	 
	 
	 //ÊäÈë input
	 scanf("%d %d %d",&N,&M,&T);
	 scanf("%d %d %d %d",&sx,&sy,&fx,&fy);
	 V.resize(N+1);
	 for(int i=0;i<=N;i++)
	 {
	 	V[i].resize(M+1);
	 }
	 
	 
	 for(int i=0;i<T;i++)
	 {
	 	scanf("%d %d",&zx,&zy);
	 	V[zx][zy]=2;	
	 }
	 
     //detail time
	 #ifdef DETAILS
	 clock_running_start_time=clock();
	 #endif
	 
	 //test unit!!
	 #ifdef DETAILS
	 test_start_sign();
	 
	 //unit test
	 for(int i=1;i<=N;i++)
	 {
	 	for(int j=1;j<=M;j++)
		 {
		 	cout<<V[i][j]<<" ";
		 } 
		 cout<<endl;
	 }

	 test_end_sign();
	 
	 
	 #endif
	 
	 //running program
	 fromto(sx,sy);

	 //detail time
	 clock();
	 #ifdef DETAILS
	 clock_running_end_time=clock();
	 #endif	 
	 
	 //Êä³ö output
	 printf("%d",result);
	 
	 
	 
	 
	 
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


