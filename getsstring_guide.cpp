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


int lengthof(char * str)
{
	int count=0;
	for(int i=0;*str!='\0';i++)
	{
		count++;	
	}
	
	return count;
	
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
	 string flag;
	 string A;
	 int pos=-1;
	 int time=0;
	 int currentpos=0;
	 
	 // ‰»Î input
	 getline(cin,flag);
	 getline(cin,A);
	 for(int i=0;i<flag.size();i++)
	 {
	 	flag[i]=tolower(flag[i]);
	 }
	 
	 for(int i=0;i<A.size();i++)
	 {
	 	A[i]=tolower(A[i]);
	 }
	 
     //detail time
	 #ifdef DETAILS
	 clock_running_start_time=clock();
	 #endif
	 
	 //running program
	 flag=" "+flag+" "; 
	 A=" "+A+" ";
	 //cout<<flag<<";";
	 //cout<<A<<";";
	 
	 int ass=A.find(flag);
	 if(ass==string::npos)
	 {
	 	printf("-1");

	 }
	 else
	 {
	 	currentpos=A.find(flag,currentpos);
	 	pos=currentpos;
	 	time++;
	 	while(currentpos<A.size())
	 	{
	 		currentpos=A.find(flag,currentpos+1);
	 		
	 		
	 		if(currentpos!=string::npos)  time++;
	 	}
		 
		 printf("%d %d",time,pos);	
	 }
	 

	 //detail time
	 clock();
	 #ifdef DETAILS
	 clock_running_end_time=clock();
	 #endif	 
	 
	 // ‰≥ˆ output

	 
	 
	 
	 
	 
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


