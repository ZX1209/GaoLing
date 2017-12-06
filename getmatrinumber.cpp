#include <iostream>
#include<vector>
#include<list>
using namespace std;


int n=0,m=0;
vector<int > dp(20,-1);

int FindMax(int i)
{
	if(dp[i]!=-1) return dp[i];
	
	
}



int main()
{
	cin>>n>>m;
	vector<list<int> > matrix(n);
	
	
	for(int i=0;i<n;i++)
	{
		int tmp;
		for(int j=0;j<m;j++)
		{
			
			cin>>tmp;
			matrix[i].push_back(tmp);
		}
	}
	
	/*
	for(int i=0;i<n;i++)
	{
			cout<<matrix[i].front()<<"  ";
	}
	 */
	
	
	                                         	
	
	return 0;
}
