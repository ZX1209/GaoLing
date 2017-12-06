#include <iostream>
using namespace std;



int N;
unsigned int heads[100]={0};
unsigned int dp[100][100];


int nextp(int i, int p)
{
	return (i+p)%N;
}

int nextp(int i)
{
	return (i+1)%N;
}

//do it right ok
int prep(int i, int p)
{
	return (i+N-p)%N;
}

//do it right ok
int prep(int i)
{
	return (i+N-1)%N;
}

unsigned int MaxEnergy(int i, int j)
{
	//返回缓存结果 
	if(dp[i][j]!=-1)  return dp[i][j];
	int head=heads[j];
	int end =heads[prep(i)];
	
	//向下找出最大的
	unsigned int max=MaxEnergy(i,i)+MaxEnergy(nextp(i),j)+head*end*heads[i];
	for(int m=nextp(i);m!=j;m=nextp(m))
	{
		int temp=MaxEnergy(i,m)+MaxEnergy(nextp(m),j)+head*end*heads[m];
		
		if(temp>max) max=temp;
	}
	
	dp[i][j]=max;
	
	return dp[i][j];
	
	
} 

int main()
{
	//get the data in
	cin>>N;	
	for(int i=0;i<N;i++)
	cin>>heads[i];
	
	//init the dp array stats
	for(int i=0;i<100;i++)
	{
		for(int j=0;j<100;j++)
		{
			
			//-1 means that does not know yet
			dp[i][j]=-1;
			//obvious 
			if(i==j) dp[i][j]=0;
			//if j is the next of i then it gets it own value
			if(nextp(i)/*next position*/==j) dp[i][j]=heads[prep(i)]*heads[i]*heads[j];
			 
		}
		
	}
	
	int Max=MaxEnergy(0,N-1);
	for(int i=1;i<N;i++)
	{
		unsigned int temp=MaxEnergy(i,prep(i));
		
		if(temp>Max) Max=temp; 
	} 
	
	cout<<Max;
	
	return 0;
	
	
	
	
	
}



