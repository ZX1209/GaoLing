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


struct studentinfo{
	string s;
	int qm; 
	int bj;
	char isa;
	char isb;
	int lunwen;
	int money;
}V[102];


bool cmp(studentinfo a,studentinfo b)
{
	if(a.money==b.money)
	{
		return true;
		
	} 
	else{
		return a.money>b.money;	
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
	 int N=0;
	 int result=0;                  
	 
	 //输入 input
	 scanf("%d ",&N);
	 
	 for(int i=1;i<=N;i++)
	 {
	 	V[i].money=0;                                   
	 	cin>>V[i].s>>V[i].qm>>V[i].bj>>V[i].isa>>V[i].isb>>V[i].lunwen;    
	 }
	 
	 

	 
	 
	 
	 
     //detail time
	 #ifdef DETAILS
	 clock_running_start_time=clock();
	 #endif
	 
	 //running program
	 for(int i=1;i<=N;i++)
	 {
	 	//班级贡献奖 
	 	if(V[i].bj>80&&V[i].isa=='Y') V[i].money+=850;
	 	
	 	//西部奖学金 
	 	if(V[i].qm>85&&V[i].isb=='Y') V[i].money+=1000;
	 	
	 	//成绩优秀奖
	 	if(V[i].qm>90) V[i].money+=2000;
		 
		//五四奖学金
		if(V[i].qm>85&&V[i].bj>80) V[i].money+=4000;
		
		//院士奖学金 
		if(V[i].qm>80&&V[i].lunwen>=1) V[i].money+=8000;	
	 }
	 
	 sort(V+1,V+N+1,cmp);
	 
	 for(int i=1;i<=N;i++)
	 {
	 	result+=V[i].money;
	 }
	 
	 cout<<V[1].s<<"\n"<<V[1].money<<"\n"<<result;
	 
	 
	 

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


