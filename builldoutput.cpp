#include<vector>
#include<iostream>
#include<cstdio>

using namespace std;

int main(){
	int i=0;
	int tmpi=0;
	vector<int> V(10,0);
	while(1)
	{
		scanf("%d",&tmpi);
		getchar();
		
		if(tmpi) V.push_back(tmpi);
		else break;
		
	}
	
	for(int j=0;j<V.size();j++)
	{
		printf("%d,",V[j]);
	}
	
	getchar();
	getchar();
	
	
	return 0;
}
