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





vector<int> Sorting(10,0); 	
int n=0;
int m=0;



inline int isprimer(int number)
{
	for(int i=2;i<=sqrt(number);i++)
	{
		if(number%i==0) return 0;
	}
	return 1;
	
}

inline char isodd(int n)
{
	return n&0x1;
}

vector<int> V(8,-1);



inline int times(int val,int time)
{
	int result=1;
	for(int i=0;i<time;i++){
		result*=val;
	}
	
	return result;
}

//似乎只能算出正整数的吧...有int的位数限制.... 
inline int wei(int n)
{
	int i=0;
	while(n/times(10,i++));
	
	return i;
}


void last_loop1()
{
	int i=0;
	int result1=0;
	int wei=0;
	while(i<8&&V[i]!=-1)
	{
		i++;
	}
	
	if(V[0]==0) return;
			
	for(int j=0;j<i;j++)
	{
		result1+=V[j]*times(10,wei++);
	}
	for(int j=i-2;j>=0;j--)
	{
		result1+=V[j]*times(10,wei++);
	}
	
	if(isprimer(result1)&&result1<=m&&result1>=n)
	Sorting.push_back(result1);	
	return;
	
}

void last_loop2()
{
	int i=0;
	int result2=0;
	int wei=0;
	while(i<8&&V[i]!=-1)
	{
		i++;
	}
	
	if(V[0]==0) return;
	for(int j=0;j<i;j++)
	{
		result2+=V[j]*times(10,wei++);
	}
	for(int j=i-1;j>=0;j--)
	{
		result2+=V[j]*times(10,wei++);
	}	
	if(isprimer(result2)&&result2<=m&&result2>=n)
	Sorting.push_back(result2);
	
	return;
	
	
	
}


void d_loop(int level,int loop_time,int loop_step)
{
	//最后一层循环的操作 
	if(level==0)
	{
		last_loop1();
		last_loop2();
		return;
	}
	else if(level==1)
	{
		for(int i=-1;i<loop_time-1;i+=2){
			V[level-1]+=2;
			d_loop(level-1,loop_time,loop_step);
		} 
		V[level-1]=-1;
		return;
		
	}
	
	//loop_change(&level,&loop_time,&loop_step); 
	
	
	for(int i=0;i<loop_time;i+=loop_step){
		V[level-1]++;
		d_loop(level-1,loop_time,loop_step);
	} 
	V[level-1]=-1;
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

	 
	 
	 
	 //输入 input
	 scanf("%d %d",&n,&m);
	 
	 
	 
     //detail time
	 #ifdef DETAILS
	 clock_running_start_time=clock();
	 #endif
	 
	 //running program
	 for(int i=wei(n)/2;i<=wei(m)/2;i++)
	 {
	 	d_loop(i,10,1);
	 }
	 
	 
	 sort(Sorting.begin(),Sorting.end());
	 
	 for(int i=0;i<Sorting.size();i++)
	 {
	 	if(Sorting[i]==0);
	 	else
	 	printf("%d\n",Sorting[i]);
	 }

	 //detail time
	 clock();
	 #ifdef DETAILS
	 clock_running_end_time=clock();
	 #endif	 
	 
	 //输出 output
	 

	 
	 
	 
	 
	 
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




