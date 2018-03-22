#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int n,v[1001];//v���顪��>����Ƿ񵽹��˵� 
double x[100];
double y[20];//(x,y)����>���� 
double dis[1001][1001];//dis[i][j]����>��i����j�ľ��루ҪԤ���� 
double ans=1231234424.0; //��֤ans��ÿ��·����Ҫ�� 
void dfs(int step,int now,double length) //step �Ѿ��߹������� now ��ǰ�ߵ��ĵ� 
                                         //length �ߵ��ĵ�ǰ·���� 
{
    if(length>ans)//��֦����Ȼ�ᳬʱ�� ��ǰ·���Ѿ��ȵ�ǰ��̵�Ҫ���ˣ��Ͳ��ؼ���������
      return;                                                        //ֱ�ӷ�����һ��                                                
    if(step==n)   //����n���� 
      {
          ans=min(ans,length);  //�������·��ֵ 
          return;
      }
    for(int i=1;i<=n;i++)  //ö�����е� 
      if(!v[i])   //û���߹� 
        {
            v[i]=1;  //���Ϊ�߹� 
            dfs(step+1,i,length+dis[now][i]);  //������һ�㣨����⣬�����ͣ� 
            v[i]=0;  //����  �Ӹղ���һ���˻أ��ѱ�ǹ��ĵ�ȡ����� 
        }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
      cin>>x[i]>>y[i];
    x[0]=0;y[0]=0;  //�����Ϊ��0���� 
    for(int i=0;i<=n;i++)  //Ԥ������������ 
      for(int j=0;j<=n;j++)
        dis[i][j]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
    dfs(0,0,0.0);  //���߹�0����  ��һ�����ǵ�0����  �����˳�0.0��·�� 
    printf("%.2f",ans);
    return 0;
}
