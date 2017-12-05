#include <iostream>
using namespace std;



//ʯ���� N 
int N;
//ÿһ��ʯ������  
int weight[100];

//dp[i][j]  i �� j ��ʯ�� ����С �ϲ����� 
int dp[100][100];



//��װ���Ѿ���С�ϳ�����ʱ�ĺϳɴ��� 
int sum(int i,int j){
    int sum=0;
    for(int m=i;m<=j;m++){
        sum+=weight[m];
    }
    return sum;
}


//��̬�滮  ����ʯ��i �� j ����С�ϲ����� 
int stoneMer(int i,int j)
{
	/////////////////////////////////////////
	//��׼״̬����
	// 
	if(i==j) dp[i][j]=0;
	//�ڽ��ĺϲ����� 
	if(i+1==j) dp[i][j]=weight[i]+weight[j];
	//�Ѿ��н���ͷ��� 
	if(dp[i][j]!=-1) return dp[i][j];
	///////////////////////////////////////// 
	
	//��ʼ����С�ϲ�����,, 
	int min=stoneMer(i,i)+stoneMer(i+1,j);
	
	//�Ƚ� �� ��С�ϲ����� 
	for(int k=i+1;k<j;k++)
	{
		int temp = stoneMer(i,k)+stoneMer(k+1,j);
		if(temp<min)   min=temp;
	} 
	
	//�ϲ��ѵķ���  �� �ϲ��ϲ��ѵ���С����............ 
	dp[i][j] = sum(i,j)+min;
	return dp[i][j];

}

int main(){
    cin>>N;
    //��ʼ��dp ״̬���� 
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

