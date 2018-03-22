#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int n,v[1001];//v数组——>标记是否到过此点 
double x[100];
double y[20];//(x,y)——>坐标 
double dis[1001][1001];//dis[i][j]——>点i到点j的距离（要预处理） 
double ans=1231234424.0; //保证ans比每条路径都要长 
void dfs(int step,int now,double length) //step 已经走过几个点 now 当前走到的点 
                                         //length 走到的当前路径长 
{
    if(length>ans)//剪枝（不然会超时） 当前路径已经比当前最短的要长了，就不必继续搜索，
      return;                                                        //直接返回上一层                                                
    if(step==n)   //走完n个点 
      {
          ans=min(ans,length);  //更新最短路径值 
          return;
      }
    for(int i=1;i<=n;i++)  //枚举所有点 
      if(!v[i])   //没有走过 
        {
            v[i]=1;  //标记为走过 
            dfs(step+1,i,length+dis[now][i]);  //深搜下一层（好理解，不解释） 
            v[i]=0;  //回溯  从刚才上一层退回，把标记过的点取消标记 
        }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
      cin>>x[i]>>y[i];
    x[0]=0;y[0]=0;  //设起点为第0个点 
    for(int i=0;i<=n;i++)  //预处理两点间距离 
      for(int j=0;j<=n;j++)
        dis[i][j]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
    dfs(0,0,0.0);  //已走过0个点  上一个点是第0个点  已走了长0.0的路径 
    printf("%.2f",ans);
    return 0;
}
