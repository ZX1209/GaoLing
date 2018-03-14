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

int V[31][31]={0};
int N;


void infection(int x,int y)
{
	if(x>=1&&x<=N&&y>=1&&y<=N)
	{
		if(V[x][y]==0||V[x][y]==3)
		{
			V[x][y]+=3;
			infection(x+1,y);
			infection(x,y+1);
			infection(x-1,y);
			infection(x,y-1);
			
			infection(x-1,y-1);
			infection(x+1,y-1);

			infection(x-1,y+1);
			infection(x+1,y+1);
			
		}
		
	}
	
	return ;
}

//give me the set of 0 position
int onearound(int x,int y)
{
	int result=0;
	int tmpx=x;
	int tmpy=y;	
	while(tmpx>=1&&tmpx<=N)
	{
		if(V[tmpx][tmpy]==1) 
		{
			result++;
			break;
		}
		tmpx++;
	}
	
	tmpx=x;
	while(tmpx>=1&&tmpx<=N)
	{
		if(V[tmpx][tmpy]==1) 
		{
			result++;
			break;
		}
		tmpx--;
	}
	
	tmpy=y;
	while(tmpy>=1&&tmpy<=N)
	{
		if(V[tmpx][tmpy]==1) 
		{
			result++;
			break;
		}
		tmpy++;
	}
	
	tmpy=y;
	while(tmpy>=1&&tmpy<=N)
	{
		if(V[tmpx][tmpy]==1) 
		{
			result++;
			break;
		}
		tmpy--;
	}
	
	return result;
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
	 int startx=1,starty=1;
	 int startfind=0;
	 scanf("%d",&N);
	 
	 for(int i=1;i<=N;i++)
	 {
	 	for(int j=1;j<=N;j++)
	 	{
	 		scanf("%d",&V[i][j]);
	 	}
	 }
	 
	 //ÊäÈë input
	 
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
	 	for(int j=1;j<=N;j++)
	 	{                                                                
			 cout<<V[i][j]<<" ";
	 	}
	 	cout<<endl;
	 }
	 test_end_sign();
	 
	 
	 #endif
	 
	 //running program
//	for(int i=1;i<=N;i++)
//	 {
//	 	for(int j=1;j<=N;j++)
//	 	{                                                                
//	 		if(V[i][j]==0&&(onearound(i,j)<4))
//	 		{
//			     startfind=1;
//				 startx=i;
//				 starty=j;
//				 break;	
//	 		}
//	 	}
//	 	if(startfind) break;
//	 }

	for(int i=1;i<=N;i++) 
	{
		infection(1,i);
		infection(N,i);
		
	}
	
	for(int i=1;i<=N;i++) 
	{
		infection(i,1);
		infection(i,N);
		
	}


	 //detail time
	 clock();
	 #ifdef DETAILS
	 clock_running_end_time=clock();
	 #endif	 
	 
	 //Êä³ö output
	 //cout<<endl<<endl;
	 for(int i=1;i<=N;i++)
	 {
	 	for(int j=1;j<=N;j++)
	 	{                                                                
			 if(V[i][j]==3||V[i][j]==6) 
			 {
			 	printf("0 ");
			 }
			 else if(V[i][j]==0)
			 {
			 	printf("2 ");
			 }
			 else 
			 {
			 	printf("%d ",V[i][j]);
			 }
			 
	 	}
	 	printf("\n");
	 }
	 

	 
	 
	 
	 
	 
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


