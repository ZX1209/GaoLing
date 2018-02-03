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
	 stack<char> S;
	 char tmpc;
	 
	 
	 
	 // ‰»Î input
	 
     //detail time
	 #ifdef DETAILS
	 clock_running_start_time=clock();
	 #endif
	 
	 //running program
	 string A;
	 int s1=1,s2=1,s3=1;
	 int total=0;
	 getline(cin,A); 
	 string::iterator start;
	 string::iterator end;
	 string::iterator it; 
	 
	 if(A.find('%')==string::npos) s1=0;
	 if(A.find('/')==string::npos) s2=0;
	 if(A.find('.')==string::npos) s3=0;
	 
	 total=s1+s2+s3;
	 
	 switch(total)
	 {
	 	case 1:
	 		{
	 			if(s1)
	 			{
	 				reverse(A.begin(),A.end()-1); 
					start=A.begin();
					end=A.end()-1;
					while((start+1)!=end) 
					{
					 	if(*start!='0')  break;
					 	start++;
					}
					
					end=A.end();
	 				
	 			}
	 			else if(s2)
	 			{
					 it=find(A.begin(),A.end(),'/');
					 reverse(A.begin(),it);
					 reverse(it+1,A.end());
					  
					  
					start=A.begin();
					end=A.end()-1;
					while((start+1)!=it) 
					{
					 	if(*start!='0')  break;
					 	start++;
					}
					
					while((it+2)!=A.end())
					{
						if(*(it+1)!='0') break;
						A.erase(it+1);	
					}
					end=A.end();
					
					
					
//					end=A.end();
//	 					 string::iterator it=find(A.begin(),A.end(),'/');
//						 reverse(A.begin(),it);
//						 reverse(it+1,A.end()); 
//						 {
//						 	if(*tmpit1!='0')  break;
//						 	A.erase(tmpit1);
//						 }
//						 
//						 
//						 
//						 string::iterator tmpit2=it+1; 
//						 while(tmpit2!=it)
//						 {
//						 	if(*tmpit2!='0')  break;
//						 	A.erase(tmpit2);
//						 }
//						 
//						 	 if(tmpit1==it) A="0"+A;
//	 
//	 						if(tmpit2==it) A=A+"0";
//	 
//	 				
	 			}
	 			else if(s3)
	 			{
	 				 it=find(A.begin(),A.end(),'.');
					 reverse(A.begin(),it);
					 reverse(it+1,A.end());
					  
					  
					start=A.begin();
					end=A.end();
					while((start+1)!=it) 
					{
					 	if(*start!='0')  break;
					 	start++;
					}
					
					while((end-2)!=it)
					{
						if(*(end-1)!='0') break;
						end--;
					}
	 				
	 				
//				 	 string::iterator it=find(A.begin(),A.end(),'.');
//					 reverse(A.begin(),it);
//					 reverse(it+1,A.end()); 
//					 
//					 string::iterator tmpit1=A.begin();
//					 
//					 
//					 while(tmpit1!=it)
//					 {
//					 	if(*tmpit1!='0')  break;
//					 	A.erase(tmpit1);
//					 }
//					 
//					 string::iterator tmpit2=A.end()-1;
//					 while(tmpit2!=it)
//					 {
//					 	if(*tmpit2!='0')  break;
//					 	
//					 	A.erase(tmpit2);
//					 	tmpit2--;
//					 	
//					 }
//					 
//					 	 if(tmpit1==it) A="0"+A;
//						 
//						 if(tmpit2==it) A=A+"0";
						 
	 
		
	 				
	 			}
	 		}
	 		break;
	 	case 0:
	 		reverse(A.begin(),A.end());
			start=A.begin();
			end=A.end();
			while((start+1)!=end) 
			{
			 	if(*start!='0')  break;
			 	start++;
			}
	 		break;
		default:
			printf("\nits complex\n");
	 		
	 }
	 


	 
	 

	 //detail time
	 clock();
	 #ifdef DETAILS
	 clock_running_end_time=clock();
	 #endif	 
	 
	 // ‰≥ˆ output
	 while(start!=end)
	 {
	 	printf("%c",*start);
	 	start++;
	 }

	
	 

	 
	 
	 
	 
	 
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


