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


//init value
int N=0;
int result=0;

int tmpmark[14]={0};
int tmpset[14]={0};
int rightmark[27];
int leftmark[27];
//int resultmark[4][14];


//输入 原坐标
// 
inline int leftmarkf(int x,int y)
{
	int rx;
	int ry;
	if(x>=y)
	{
		rx=x-(y-1);
		ry=y-(y-1);
		if(leftmark[rx]!=0)
		{
			return 1;
		}
		else{
			leftmark[rx]=1;
			return 0;
		}
		
	}
	else
	{
		rx=x-(x-1);
		ry=y-(x-1);
		if(leftmark[ry+N]!=0)
		{
			return 1;
		}
		else{
			leftmark[ry+N]=1;
			return 0;
		}
		
	}
	
	
}

//输入原坐标
//输出对应斜行的值,
//0 表示无
//1 表示有 
inline int leftsetf(int x,int y)
{
	int rx;
	int ry;
	if(x>=y)
	{
		rx=x-(y-1);
		ry=y-(y-1);
		return leftmark[rx];
		
	}
	else
	{
		rx=x-(x-1);
		ry=y-(x-1);
		return leftmark[ry+N];
		
	}
	
	
}

inline int rightsetf(int x,int y)
{
	int rx;
	int ry;
	if((9-x)>=y)
	{
		rx=x+(y-1);
		ry=y-(y-1);
		return rightmark[rx];
		
	}
	else
	{
		rx=x+(N-x);
		ry=y-(N-x);
		return rightmark[ry+N];
		
	}
	
	
	
}


inline int rightmarkf(int x,int y)
{
	int rx;
	int ry;
	if((9-x)>=y)
	{
		rx=x+(y-1);
		ry=y-(y-1);
		if(rightmark[rx]!=0)
		{
			return 1;
		}
		else{
			rightmark[rx]=1;
			return 0;
		}
		
	}
	else
	{
		rx=x+(N-x);
		ry=y-(N-x);
		if(rightmark[ry+N]!=0)
		{
			return 1;
		}
		else{
			rightmark[ry+N]=1;
			return 0;
		}
		
	}
	
	
	
}

inline void lefterasef(int x,int y)
{
	int rx;
	int ry;
	if(x>=y)
	{
		rx=x-(y-1);
		ry=y-(y-1);
		leftmark[rx]=0;
		return ;
		
	}
	else
	{
		rx=x-(x-1);
		ry=y-(x-1);
		leftmark[ry+N]=0;
		return;
		
	}
	
	
}

inline void righterasef(int x,int y)
{
	int rx;
	int ry;
	if((9-x)>=y)
	{
		rx=x+(y-1);
		ry=y-(y-1);
		rightmark[rx]=0;
		return ;
		
	}
	else
	{
		rx=x+(N-x);
		ry=y-(N-x);
		rightmark[ry+N]=0;
		return;
		
	}
	
	
}


void process(int c)
{
	if(c==N)
	{
	//	for(int i=1;i<=N;i++) 
//		{
//			 //not j=i j=i+1!!!!!!!! 
//			for(int j=i+1;j<=N;j++) 
//			{
//				if(abs(tmpmark[i]-tmpmark[j])==abs(i-j)) return ;
//				
//			}
//				
//		}
//		
		result++;
		if(result<=3)
		{
		 	for(int j=1;j<=N;j++)
		 	{
		 		printf("%d ",tmpmark[j]);
		 	}
		 	printf("\n");
			
		}
		
		return ;
	}
	
	//chen yu shucheng buduiying 
//	if(c>3)
//	{
//		for(int i=1;i<c;i++) 
//		{
//			 //not j=i j=i+1!!!!!!!! 
//			for(int j=i+1;j<=c;j++) 
//			{
//				if(abs(tmpmark[i]-tmpmark[j])==abs(i-j)) return ;
//				
//			}
//				
//		}
//		
//	}
	
	

	
	
	
	for(int i=1;i<=N;i++)
	{	
		
		if(tmpset[i]!=1&&!leftsetf(i,c+1)&&!rightsetf(i,c+1))
		{
			//flag set
			tmpset[i]=1;
			
			//mark level number
			tmpmark[c+1]=i;
			
			leftmarkf(i,c+1);
			rightmarkf(i,c+1);
			
			//next level
			//printf("level:%d insert:%d\n",c,i);
			process(c+1);
			
			//unset flag
			tmpset[i]=0;
			
			lefterasef(i,c+1);
			righterasef(i,c+1);
			
//			//for security
//			tmpmark[c+1]=0;
			
			
		}	
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
	 

	 
	 
	 
	 //输入 input
	 scanf("%d",&N);
	 
     //detail time
	 #ifdef DETAILS
	 clock_running_start_time=clock();
	 #endif
	 
	 //running program
	 process(0);

	 //detail time
	 clock();
	 #ifdef DETAILS
	 clock_running_end_time=clock();
	 #endif	 
	 
//	 //输出 output
//	 for(int i=1;i<=3;i++)
//	 {
//	 	for(int j=1;j<=N;j++)
//	 	{
//	 		printf("%d ",resultmark[i][j]);
//	 	}
//	 	printf("\n");
//	 }
//	 
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


