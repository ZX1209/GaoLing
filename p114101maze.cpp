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


struct twoint
{
	int x;
	int y;
}; 

int n;
int m;

vector<vector<int> > V;
vector<vector<int> > answer;
vector<vector<int> > record;

vector<twoint> questions;
int lin[1000001][2];
int tmpwalk=0;

int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

void dfs(int x, int y)
{
	tmpwalk++;
	lin[tmpwalk][0]=x;
	lin[tmpwalk][1]=y;
	record[x][y]=1;
	
	int tmp=V[x][y];
	int tmpx=x;
	int tmpy=y;
	
	for(int i=0;i<4;i++)
	{
		tmpx=x+dir[i][0];
		tmpy=y+dir[i][1];
		
		
		if(tmpx>=1&&tmpx<=n&&tmpy>=1&&tmpy<=n)
		{
			if(V[tmpx][tmpy]!=tmp&&record[tmpx][tmpy]!=1)//can
			{
				dfs(tmpx,tmpy);
				
		 	}
		 	else
		 	{
		 		continue;
		 		
		 	}
		}
		else
		{
			continue;
		}
	}
	//record[x][y]=0;
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
	 scanf("%d %d",&n,&m);
	 V.resize(n+1);
	 answer.resize(n+1);
	 questions.resize(m);
	 record.resize(n+1);
	 
	 for(int i=0;i<=n;i++)
	 {
	 	V[i].resize(n+1);
	 	answer[i].resize(n+1);
	 	record[i].resize(n+1);
	 }
	 
	 
	 
	 //ÊäÈë input
	 for(int i=1;i<=n;i++)
	 {
	 	for(int j=1;j<=n;j++)
	 	{
	 		scanf("%1d",&V[i][j]);
	 	}
	 }
	
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&questions[i].x,&questions[i].y);
	}
     //detail time
	 #ifdef DETAILS
	 clock_running_start_time=clock();
	 #endif
	 
	 
	 //test unit!!
	 #ifdef DETAILS
	 test_start_sign();
	 
	 for(int i=1;i<=n;i++)
	 {
	 	for(int j=1;j<=n;j++)
	 	{
	 		cout<<V[i][j]<<" ";
	 	}
	 	cout<<endl;
	 }
	 test_end_sign();
	 #endif
	 
	 //running program
	 for(int i=0;i<m;i++)
	 {
	 	if(answer[questions[i].x][questions[i].y]!=0) 
	 	{
	 		printf("%d\n",answer[questions[i].x][questions[i].y]);    
		}
		else
		{
			tmpwalk=0;
			dfs(questions[i].x,questions[i].y);
			for(int i=1;i<=tmpwalk;i++)
			{
				answer[lin[i][0]][lin[i][1]]=tmpwalk;
			}
			printf("%d\n",tmpwalk);
				
		} 
	 }
	 
	 
	 
	 
	 
	 
	 

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


