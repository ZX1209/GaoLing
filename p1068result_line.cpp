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
	int left;
	int right;
};


//can be struct{
//   ...
// }twointcmp;
//can be different standar
struct test{
	bool operator()(twoint first,twoint second)
	{
		if(first.right>second.right)
		{
			return true;
		}
		else if(first.right==second.right)
		{
			if(first.left<=second.left)
			{
				return  true;
			}
			else{
				return false;
			}
		}
		else{
			return false;
		}
		
	}

	
} twointcmp;




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
	 twoint example={0,0};
	 int n,m;
	 int tmpa,tmpb;
	 int line;
	 int result=0;
	 
	 //ÊäÈë input
	 scanf("%d %d",&n,&m);
	 vector<twoint> v(n,example);
	 
	 for(int i=0;i<n;i++)
	 {
	 	scanf("%d %d",&tmpa,&tmpb);
	 	v[i].left=tmpa;
	 	v[i].right=tmpb;
	 	
	 }
	 
	 
	 sort(v.begin(),v.end(),twointcmp);
	 
	 line=v[(int)(m*1.5)-1].right;
	 
	 
	 
     //detail time
	 #ifdef DETAILS
	 clock_running_start_time=clock();
	 #endif
	 
	 //running program
	 
	 for(int i=0;i<n;i++)
	 {
	 	if(v[i].right<line)
		 {
		 	result=i;
		 	break;	
		 } 
	 }
	 
	 printf("%d %d\n",line,result);
	 
	 for(int i=0;i<result;i++)
	 {
	 		printf("%d %d\n",v[i].left,v[i].right);
	 	
	 }
	 
	 
//	for(int i=0;i<n;i++)
//	 {
//	 		printf("%d %d\n",v[i].left,v[i].right);
//	 	
//	 }

	 //detail time
	 clock();
	 #ifdef DETAILS
	 clock_running_end_time=clock();
	 #endif	 
	 
	 //Êä³ö output
	 

	 
	 
	 
	 
	 
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


