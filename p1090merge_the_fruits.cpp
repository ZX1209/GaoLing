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



struct node{
	int w;
	
	bool operator< (const node& a) const
	{
		return a.w<w;
	}
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
	 int n;
	 
	 priority_queue<node> Q;
	 int min;
	 node tmpnode;
	 node p,q;
	 long result=0;
	 
	 scanf("%d",&n);
	 
	 for(int i=0;i<n;i++)
	 {
	 	scanf("%d",&min);
	 	tmpnode.w=min;
	 	Q.push(tmpnode);
	 }
	 
	 //ÊäÈë input
	 while(Q.size()>1){
	 	p=Q.top();
	 	Q.pop();
	 	q=Q.top();
	 	Q.pop();
	 	
	 	p.w+=q.w;
	 	result+=p.w;
	 	Q.push(p);
	 	
	 }

	 
	 
	 
     //detail time
	 #ifdef DETAILS
	 clock_running_start_time=clock();
	 #endif
	 
	 
//	 while(L.size()>1)
//	 {
////	 	L.sort();
////	 	min1=L.begin();
////	 	min2=++min1;
////		min1--;
////	 	*min1+=*min2;
////	 	result+=*min1;
////	 	L.erase(min2);

//		for(it=L.begin();it!=L.end();it++)
//		{
//			cout<<*it<<" ";
//		}
//		cout<<endl;
//		
//		min2=min1=L.begin();

//		for(it=L.begin();it!=L.end();it++)
//		{
//			if(*it<*min1) min1=it;
//		}
//		
//		for(it=L.begin();it!=L.end();it++)
//		{
//			if(*it<*min2&&min2!=min1) min2=it;
//		}
//		
//		*min1=*min1+*min2;
//		result=result+*min1;
//		L.erase(min1);
//		
//		
//	 }
	 
	 
	 //detail time
	 clock();
	 #ifdef DETAILS
	 clock_running_end_time=clock();
	 #endif	 
	 
	 //Êä³ö output
	 printf("%ld",result);

	 
	 
	 
	 
	 
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


