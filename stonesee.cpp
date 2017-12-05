#include <iostream>
using namespace std;



int N;
int weight[100];
int dp[100][100];



void show()
{
	static int i=0;
	i++;
	printf("-------------------%d--------------------------\n",i);
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			printf("%2d ",dp[i][j]);
		}
		printf("\n");
	}
	
	printf("--------------------%d-------------------------\n",i);
	
	getchar();
}

void show(int i, int j)
{
	printf("%d %d is %d\n",i,j,dp[i][j]);
}


int sum(int i,int j){
    int sum=0;
    for(int m=i;m<=j;m++){
        sum+=weight[m];
    }
    return sum;
}

int stoneMer(int i,int j){
	show(i,j) ;
    if(i==j){
        dp[i][j]=0;
        show();
    }
    if(i+1==j){
        dp[i][j]=weight[i]+weight[j];
        show();
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    
    int min=stoneMer(i,i)+stoneMer(i+1,j);
    for(int m=i+1;m<j;m++){
        int temp=stoneMer(i,m)+stoneMer(m+1,j);
        if(temp<min){
            min=temp;
        }
    }
    
    dp[i][j]=min+sum(i,j);
    show();
    return dp[i][j];
}

int main(){
    cin>>N;
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            dp[i][j]=-1;
        }
    }
    for(int i=0;i<N;i++){
        cin>>weight[i];
    }
    cout<<stoneMer(0,N-1)<<endl;
    return 0;
}

