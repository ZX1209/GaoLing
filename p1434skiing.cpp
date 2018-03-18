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
#define br printf("\n");

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


int R,C;
vector<vector<int> > V;
vector<vector<int> > A;
int dis=0;
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int maxpoint[100000][2];
int maxnum=1;

void dfs(int x,int y,int step)
{
	if(step>dis)
	{
		dis=step;
	}
	
	if(A[x][y]==0||A[x][y]<step)
	{
		int tmpx=x;
		int tmpy=y;
		
		for(int i=0;i<4;i++)
		{
			tmpx=x+dir[i][0];
			tmpy=y+dir[i][1];
			
			if(tmpx>0&&tmpx<=R&&tmpy>0&&tmpy<=C)
			{
				if(V[tmpx][tmpy]<V[x][y])
				{
					dfs(tmpx,tmpy,step+1);
				}
				
			}
			
		}
		A[x][y]=step;

		
	}
	 
	//printf("[debug] %3d %3d %3d %3d",A[x][y],)
	//cout<<"[debug] "<<A[x][y]<<x<<" "<<y<<" "<<step<<endl; 
	
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
	 int maxx;
	 int maxy;
	 int max;
	 
	 
	 
	 //ÊäÈë input
	 scanf("%d %d",&R,&C);
	 V.resize(R+1);
	 A.resize(R+1);
	 for(int i=1;i<=R;i++)
	 {
	 	V[i].resize(C+1);
	 	A[i].resize(C+1);
	 }
	 
	 for(int i=1;i<=R;i++)
	 {
	 	for(int j=1;j<=C;j++)
	 	{
	 		scanf("%d",&V[i][j]);
	 	}
	 }
	 
     //detail time
	 #ifdef DETAILS
	 clock_running_start_time=clock();
	 #endif
	 
	 //test unit!!
	 #ifdef DETAILS
	 test_start_sign();
	 
	 //unit test
	 for(int i=1;i<=R;i++)
	 {
	 	for(int j=1;j<=C;j++)
	 	{
	 		printf("%3d ",V[i][j]);
	 	}
	 	 br;
	 }
	 

	 test_end_sign();
	 
	 
	 #endif
	 
	 //running program
	 max=V[1][1];
 	 maxnum=0;
 	 maxpoint[maxnum][0]=1;
	 maxpoint[maxnum][1]=1;

	 for(int i=1;i<=R;i++)
	 {
	 	for(int j=1;j<=C;j++)
	 	{
	 		if(max<V[i][j])
	 		{
	 			maxnum=0;
	 			maxpoint[maxnum][0]=i;
	 			maxpoint[maxnum][1]=j;
	 			maxnum++;
	 			max=V[i][j];
	 		}
	 		else if(max==V[i][j])
	 		{
	 			maxpoint[maxnum][0]=i;
	 			maxpoint[maxnum][1]=j;
	 			maxnum++;
	 			
	 		}
	 		
	 	}
	 	
	 }
	 
	 
	 
	 
	 
	 
	 
	 for(int i=0;i<maxnum;i++)
	 {
	 	dfs(maxpoint[i][0],maxpoint[i][1],1);	 	
	 }
	 
	 
	 

	 //detail time
	 clock();
	 #ifdef DETAILS
	 clock_running_end_time=clock();
	 
	 for(int i=1;i<=R;i++)
	 {
	 	for(int j=1;j<=C;j++)
	 	{
	 		printf("%3d ",A[i][j]);
	 	}
	 	 br;
	 }
	 #endif	 
	 
	 //Êä³ö output
	 printf("%d",dis);
	 

	 
	 
	 
	 
	 
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


