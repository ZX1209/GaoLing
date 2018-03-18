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
#include<utility>

using namespace std;

#define DETAILS

#define printInt(x) printf(#x " = %d",(x));
#define printFloat(x) printf(#x " = %f",(x));
#define br printf("\n");
#define max(x,y) (x)>(y)?(x):(y)
#define min(x,y) (x)>(y)?(y):(x) 

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

vector<pair<double,double> > V;
vector<int> Set; 
int N;
vector<vector<double> > dis;
map<pair<double,double>,int> M;

double backforward(double x,double y)
{
	int count=0;
	for(int i=1;i<=N;i++)
	{
		if(Set[i]==1)  count++; 
	} 
	if(count>=N) return 0;
	
	
	int rpos; 
 	map<pair<double,double>,int>::iterator it=M.find(make_pair(x,y));
 	if(it!=M.end()) 
 	{
 		rpos=it->second;	
 	}
 	else 
 	{
 		cout<<"error"<<endl;
 		return 0;
 	}
	
	//if(dis[rpos]!=0) return dis[rpos];
	
	double min=-1;
	int time=0;
	double tmpdis=0;
	
	for(int i=1;i<=N;i++)	
	{
		//是否走过了...
		//如果没走过啊.. 
		
		if(Set[i]==0)
		{
			
			Set[i]=1;
			
			//for tmpdis
			if(dis[rpos][i]==0)
			{
				double tmpxx=(x-V[i].first);
				double tmpyy=(y-V[i].second);
				tmpdis=sqrt(tmpxx*tmpxx+tmpyy*tmpyy);
				dis[i][rpos]=tmpdis;
				dis[rpos][i]=tmpdis;
				
			}
			else
			{
				tmpdis=dis[rpos][i]; 			
			}
			
			//for min
			if(time==0)
			{
				min=tmpdis+backforward(V[i].first,V[i].second);
				time++;
			}
			else
			{
				tmpdis=tmpdis+backforward(V[i].first,V[i].second);
				if(min>tmpdis)
				{
					min=tmpdis;
				}
				
			}		
			Set[i]=0;
	
		} 
	}
	
	//sort(tmpv.begin(),tmpv.end());
	/*
	 for(int i=0;i<N;i++)
	 {
	 	printf("[debug] x:%.3lf y:%.3lf i:%d V[i]:%.3lf\n",x,y,i,tmpv[i]);
	 }
	 */
	
	//cout<<"debug:"<<min<<endl;
	return min;
	
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
	 double tmpx;
	 double tmpy;
	 double ans=0;
	 
	 
	 
	 //输入 input
	 scanf("%d",&N);
	 V.resize(N+1);
	 dis.resize(N+1);
	 dis[0].resize(N+1);
	 V[0].first=0;
	 V[0].second=0;
	 M.insert(make_pair(make_pair(0,0),0));
	 
	 Set.resize(N+1);
	 Set[0]=1;
	 for(int i=1;i<=N;i++)
	 {
	 	scanf("%lf %lf",&tmpx,&tmpy);
	 	V[i].first=tmpx;
	 	V[i].second=tmpy;
	 	M.insert(make_pair(make_pair(tmpx,tmpy),i));
	 	dis[i].resize(N+1);
	 }
	 
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
	 	printf("[debug] i:%2d first:%3.2lf second:%3.2lf\n",i,V[i].first,V[i].second);
	 }


	 test_end_sign();
	 
	 
	 #endif
	 
	 //running program
	 for(int i=0;i<=N;i++)
	 {
	 	for(int j=0;j<=N;j++)
	 	{
	 		if(dis[j][i]==0)
	 		{
	 			double tmpxx=(V[j].first-V[i].first);
				double tmpyy=(V[j].first-V[i].second);
				double tmpdis=sqrt(tmpxx*tmpxx+tmpyy*tmpyy);
				dis[j][i]=tmpdis;
				dis[i][j]=tmpdis;	 			
	 		}
 		
	 	}
	 }
	 
	 
	 
	 ans=backforward(0,0);

	 //detail time
	 clock();
	 #ifdef DETAILS
	 clock_running_end_time=clock();
	 #endif	 
	 
	 //输出 output
	 printf("%.2lf",ans);
	 

	 
	 
	 
	 
	 
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


