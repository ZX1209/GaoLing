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
	 string y;
	 string m;
	 string p;
	 int mset[26]={0};
	 map<char,char> cmap;
	 map<char,char>::iterator mapit;
	 
	 
	 
	 getline(cin,y);
	 getline(cin,m);
	 getline(cin,p);
	 

	 
	 // ‰»Î input

     //detail time
	 #ifdef DETAILS
	 
	 clock_running_start_time=clock();
	 #endif
	 
	 //running program
	 for(int i=0;i<(y.length()-1);i++)
	 {
	 	mset[m[i]-'A']=1;
	 	//cout<<y[i]<<":"<<(int)y[i]<<endl;
			mapit=cmap.find(y[i]);
			if(mapit==cmap.end())
			{
				cmap.insert(make_pair(y[i],m[i]));
			}
			else
			{
				if(cmap[y[i]]!=m[i]) {
					printf("Failed");
					return 0;
				}
			}
			
	 } 
	 
	 for(int i=0;i<26;i++)
	 {
	 	if(mset[i]!=1)
	 	{
	 		printf("Failed");
			return 0;
	 		
	 	}
	 }
	 
	 //cout<<cmap.size()<<endl;
	 if(cmap.size()<26) 	
	 {
		printf("Failed");
		return 0;	
	 }
	 
	 
	 for(int i=0;i<(p.length()-1);i++)
	 {
	 	printf("%c",cmap[p[i]]);
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


