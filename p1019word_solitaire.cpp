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



struct wordinfo{
	string s;
	int times;
};

char D;
int N;
wordinfo tmpwi={"",0};
vector<wordinfo> V; 
int maxlength=0;

int min(string &a,string &b)
{
	return a.length()<b.length()?a.length():b.length();
}

int samematch(string a,string b)
{
    int pos=a.size()+1;
    int answer=-1;
    
    while(pos>0)
    {
    	pos--;
        pos=a.rfind(b[0],pos);
        if(pos==(int)string::npos) return answer;
        
        a.substr(pos);
        if(b.find(a.substr(pos))!=0) return answer;
        answer=a.size()-pos;
        
    }
    return answer;
		
}


int canmatch(string s)
{
	
	for(int i=0;i<N;i++)
	{
		if((samematch(s,V[i].s)!=-1)&&(V[i].times<2)) return 1;
	}
	
	return 0;
}


void worddp(string s)
{
	if(canmatch(s))
	{
		for(int i=0;i<N;i++)
		{
			if(V[i].times<2)
			{
				int pos=samematch(s,V[i].s);
				if(pos!=-1)
				{
					V[i].times++;
					worddp(s+V[i].s.substr(pos));
					V[i].times--;
				}
				
			}
			
		}
 	}
	else
	 {
	 	if(s.length()>maxlength)
	 	{
	 		maxlength=s.length();
	 	}
	 	
	 }
	 return ;
	
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

	 
	 
	 // ‰»Î input
	 scanf("%d",&N);
	 for(int i=0;i<N;i++)
	 {
	 	cin>>tmpwi.s;
	 	tmpwi.times=0;
	 	V.push_back(tmpwi);
	 }
	 
	 getchar();
	 scanf("%c",&D);
	 
     //detail time
	 #ifdef DETAILS
	 clock_running_start_time=clock();
	 #endif
	 
	 //running program
	 for(int i=0;i<N;i++)
	 {
	 	if(V[i].s[0]==D)
	 	{
	 		V[i].times++;
	 		worddp(V[i].s);
	 		V[i].times--;
	 	}
	 }

	 //detail time
	 clock();
	 #ifdef DETAILS
	 clock_running_end_time=clock();
	 #endif	 
	 
	 // ‰≥ˆ output
	 cout<<maxlength;
	 

	 
	 
	 
	 
	 
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


