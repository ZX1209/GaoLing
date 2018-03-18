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
#define printInt(x) printf(#x " = %d",(x));

#define printFloat(x) printf(#x " = %f",(x));



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

struct rule
{
	string a;
	string b;
};

string A;
string B;
rule tmprule;
vector<rule> V;
int least=11;
set<string> Set;
int maxa=0,mina=10;

int ruleto(string a, string b)
{
	return 0;	
}


void stringchange(string s,int n)
{  
	if(n<10)
	{
		if(s==B)
		{
			if(least>n)
			{
				least=n;
			}
			return;
		}
		else if(!Set.count(s))
		{
			//cout<<"s is "<<s<<" n is "<<n<<endl;
			//cout<<"[debug "<<((int)s.length()+maxa*(9-n))<<"----"<<B.length()<<endl;
			//cout<<"[debug "<<((int)s.length()+mina*(9-n))<<"----"<<B.length()<<endl;
			if(((int)s.length()+maxa*(9-n))<(int)B.length()) return;
			if(((int)s.length()+mina*(9-n))>(int)B.length()) return;
			
			Set.insert(s);
			for(int i=0;i<V.size();i++)
			{				
				int pos=0;
				string tmp;
				while((pos=s.find(V[i].a,pos))!=string::npos)
				{
				    tmp=s;
				    tmp.erase(pos,V[i].a.size());
				    tmp.insert(pos,V[i].b);  
		
				    stringchange(tmp,n+1);
				    
				    pos++;			
				}
			}
			
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

	 
	 cin>>A>>B;
	 
	 while(cin>>tmprule.a>>tmprule.b)
	 {
	 	V.push_back(tmprule);
	 }
	 
	 for(int i=0;i<V.size();i++)
	 {
	 	int tmp=V[i].b.length()-V[i].a.length();
	 	if(tmp>maxa) maxa=tmp;
	 	if(tmp<mina) mina=tmp;
	 }
	 
	 
	 
	 
	 
	 
	 
	 //ÊäÈë input
	 
     //detail time
	 #ifdef DETAILS
	 clock_running_start_time=clock();
	 #endif
	 
	 //test unit!!
	 #ifdef DETAILS
	 test_start_sign();
	 
	 //unit test
	 cout<<A<<"    "<<B<<endl;
	 for(int i=0;i<V.size();i++)
	 {
	 	cout<<V[i].a<<" to "<<V[i].b<<endl;
	 }
	 
	 cout<<endl<<maxa<<"  "<<mina<<endl;

	 test_end_sign();
	 
	 
	 #endif
	 
	 //running program
	 stringchange(A,0);
	 
	 
	 
	 

	 //detail time
	 clock();
	 #ifdef DETAILS
	 clock_running_end_time=clock();
	 #endif	 
	 
	 //Êä³ö output
	 if(least<=10) 
	 {
	 	printf("%d",least);
	 }
	 else 
	 {
	 	printf("NO ANSWER!");
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


