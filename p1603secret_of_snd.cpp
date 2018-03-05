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


bool strcmp(string a,string b)
{
	return a<b;
	
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
	 string tmps;
	 string dir[]={"zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty","a","both","another","first","second","third"};
	 string dic[]={"00","01","04","09","16","25","36","49","64","81","00","21","44","69","96","25","56","89","24","61","00","01","04","09","01","04","09"};
     vector<string> all;	 
     //首位为零
	 int zero_flag=1; 
	 int count=0; 
	 
	 
	 //输入 input
	 while(tmps!=".")
	 {
	 	cin>>tmps;
	 	tmps[0]=tolower(tmps[0]);
	 	for(int i=0;i<26;i++)
	 	{
	 		if(tmps==dir[i])
	 		{
	 			count++;
	 			all.push_back(dic[i]);
	 		}
	 	}
	 	//cout<<"\""<<tmps<<"\",";
	 }
	 
	 if(count==0)
	 {
	 	cout<<"0";
	 	return 0;
	 	
	 } 

	 
     //detail time
	 #ifdef DETAILS
	  for(int i=0;i<all.size();i++)
	 {
	 	cout<<all[i]<<endl;
	 }
	 clock_running_start_time=clock();
	 #endif
	 
	 //running program
	 //vector<string>::iterator  it;
	 sort(all.begin(),all.end(),strcmp);
	 tmps="";
	 
	 for(int i=0;i<all.size();i++)
	 {
	 	tmps+=all[i];
	 }
	 //除首零.... 
	 
	 for(int i=0;i<tmps.length();i++)
	 {
	 	if(tmps[i]=='0'){
	 		if(zero_flag) continue;
	 		cout<<tmps[i];
	 	}
	 	else{
	 		zero_flag=0;
	 		cout<<tmps[i]; 
	 	}
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


