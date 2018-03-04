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


struct twoint
{
	int first;
	int second;
};


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
	 char ch;
	 int w=0;
	 int l=0;
	 int r11=0;
	 int r21=0;
	 string s;
	 twoint example={0,0};
	 
	 vector<twoint> V11(1500,example);
	 vector<twoint> V21(1500,example);
	 
	 
	 
	 
	 
	 //输入 input
	 while(1)
	 {
	 	ch=getchar();
	 	if(ch=='E')
	 	{
	 		break;
	 	}
	 	else if(ch=='\n') 
	 	{
	 		continue;
	 	}
	 	else if(ch=='W')
	 	{
	 		V11[r11].first++;
	 		V21[r21].first++;
	 	}
	 	else if(ch=='L')
	 	{
	 		V11[r11].second++;
	 		V21[r21].second++;
	 	}
	 	else 
	 	{
	 		continue;
	 	}
	 	
	 	//题意不清啊... 
	 	if(V11[r11].first>=11||V11[r11].second>=11)
	 	{
	 		if(abs(V11[r11].first-V11[r11].second)>=2)
	 		{
		 		r11++;
		 		if(r11>=1500)
		 		V11.push_back(example);
	 			
	 		}
	 	}
	 	
	 	if(V21[r21].first>=21||V21[r21].second>=21)
	 	{
	 		if(abs(V21[r21].first-V21[r21].second)>=2)
	 		{
		 		r21++;
		 		if(r21>=1500)
		 		V21.push_back(example);
		 		
			}
	 	}
	 	
	 	
	 	
	 }
	 
     //detail time
	 #ifdef DETAILS
	 clock_running_start_time=clock();
	 #endif
	 
	 //running program
	 for(int i=0;i<=r11;i++)
	 {
	 	printf("%d:%d\n",V11[i].first,V11[i].second);
	 }
	 
	 for(int i=0;i<=r21;i++)
	 {
	 	printf("\n");
	 	printf("%d:%d",V21[i].first,V21[i].second);
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


