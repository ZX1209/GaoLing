#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
struct node{
    string xm;//����
    int qm,bj;//��ĩƽ���ɼ����༶����ɼ�
    char bgb,xb;//�Ƿ���ѧ���ɲ����Ƿ�������ʡ��ѧ��
    int lw;//�����������
    int ans;//��������Ľ�����
    int sum;//���������Ϊ��ĿҪ������������Ľ�������ͬʱ������ȳ��ֵģ�����ŽϿ�ǰ�ģ���С�ģ�
}a[101];
int n,tot=0;
bool cmp(node x,node y)
{
    if(x.ans==y.ans)return x.sum<y.sum;
    else return x.ans>y.ans;//��ѧ�����Ӵ�С������ͬʱ���������С��������
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].xm>>a[i].qm>>a[i].bj>>a[i].bgb>>a[i].xb>>a[i].lw;
        if(a[i].qm>80&&a[i].lw>=1)a[i].ans+=8000;
        if(a[i].qm>85&&a[i].bj>80)a[i].ans+=4000;
        if(a[i].qm>90)a[i].ans+=2000;
        if(a[i].xb=='Y'&&a[i].qm>85)a[i].ans+=1000;
        if(a[i].bj>80&&a[i].bgb=='Y')a[i].ans+=850;
        a[i].sum=i;
        tot+=a[i].ans;//totΪ�ܵĽ�ѧ����
    }
    sort(a+1,a+n+1,cmp);
    cout<<a[1].xm<<endl<<a[1].ans<<endl<<tot;
    return 0;
} 
//����ϲ��������ճ���ں��棬����
