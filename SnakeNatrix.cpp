#include<iostream>


using namespace std;


int IsEven(int N)
{             
	return 1-N%2;
}

int main()
{
	
	int n;
	scanf("%d",&n);
	int row=n/2;
	int column=row;
	
	
	if(!IsEven(n))
	{
		int matrix[n][n]; //matrix[n/2+1][n/2+1]
		matrix[row][column]=1;
		
		int chesum=n/2;//form 0 to max
		int sum=1;
		//层循环 
		for(int che=1;che<=chesum;che++)
		{
			//基于层的行,差,对角线和计算 
			int hang=che*2+1;
			int stdcha=(hang-1);
			int chengsum=4*(che*2+1)*(che*2+1)-6*stdcha;
			sum+=chengsum;
			
			
			//关键点赋值 
			matrix[row+che][column+che]=hang*hang;
			matrix[row-che][column-che]=hang*hang-2*stdcha;
			
			//层完善 
				for(int i=1;i<hang;i++)            	
			{
				/*
						for(int i=0;i<n;i++)
						{
							for(int j=0;j<n;j++)
							{
								printf("%5d\t",matrix[i][j]);
							}
							printf("\n");
						} 
						printf("\n\n"); 
				*/
				//从中心(row,column),向左上移动(row-che,column-che)
				//差值下面递增hang-1次 
				matrix[row-che+i][column-che]=matrix[row-che][column-che]+i;
				//差值右边递减hang-1次 
				matrix[row-che][column-che+i]=matrix[row-che][column-che]-i;
				//全值左侧递减hang-1次(多余了) 
				matrix[row+che][column+che-i]=matrix[row+che][column+che]-i;
				//全值上方以原先的递增n-1次 
				matrix[row+che-i][column+che]=matrix[row+che-1][column+che-1]+i;
				
			}	
		}
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<matrix[i][j];  	
			}
			cout<<endl;
		} 
		
		cout<<sum;
		
		
		
	}
	return 0;
}

 
