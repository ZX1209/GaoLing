#include<iostream>
#include<algorithm>

using namespace std;

void show(int Start[],int N)
{
	for(int i=0;i<N;i++)
	{
		cout<<Start[i];
	}
	cout<<endl;
}

int main()
{
	int V,n;
	int v[30]={0};
	int vsum=0;
	int rest[20001]={0};
	int REST=0;
	cin>>V>>n;
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
		vsum+=v[i];
	}
	
	if(vsum==V){
		REST=0;
	}
	else if(vsum<V){
		REST=V-vsum;
	}
	else{
		for(int i=0;i<n;i++)
		{
			for(int j=V;j>=v[i];j--)
			{
				rest[j]=max(rest[j],rest[j-v[i]]+v[i]);
			}
		}
		
		REST=V-rest[V]; 
			
	}
	
	//show(v,n);
	
	
	
	
	
	
	cout<<REST;
	
	return 0;
}
