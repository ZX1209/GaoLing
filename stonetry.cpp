#include <iostream>
using namespace std;



//石子数 N 
int N;
//每一个石子重量  
int weight[100];

//dp[i][j]  i 到 j 个石子 的最小 合并代价 
int dp[100][100];



//假装有已经最小合成两堆时的合成代价 
int sum(int i,int j){
    int sum=0;
    for(int m=i;m<=j;m++){
        sum+=weight[m];
    }
    return sum;
}


//动态规划  返回石子i 到 j 的最小合并费用 
int stoneMer(int i,int j)
{
	/////////////////////////////////////////
	//基准状态处理
	// 
	if(i==j) dp[i][j]=0;
	//邻进的合并费用 
	if(i+1==j) dp[i][j]=weight[i]+weight[j];
	//已经有结果就返回 
	if(dp[i][j]!=-1) return dp[i][j];
	///////////////////////////////////////// 
	
	//初始化最小合并费用,, 
	int min=stoneMer(i,i)+stoneMer(i+1,j);
	
	//比较 出 最小合并费用 
	for(int k=i+1;k<j;k++)
	{
		int temp = stoneMer(i,k)+stoneMer(k+1,j);
		if(temp<min)   min=temp;
	} 
	
	//合并堆的费用  和 合并合并堆的最小费用............ 
	dp[i][j] = sum(i,j)+min;
	return dp[i][j];

}

int main(){
    cin>>N;
    //初始化dp 状态数组 
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

