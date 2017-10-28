#include<cstdio>
#include<cstring>
int a[1010],f[1010],b[1010],n,max,k;
int main()
{
	while(scanf("%d",&k)!=EOF) f[++n]=k;
	for(int i=1;i<=n;i++)
	{
		k=0;
		for(int j=i;j>=0;j--)
			if( ( f[i]<=f[j] ) && ( k<a[j] ) ) k=a[j];
		a[i]=k+1;
		if(a[i]>max) max=a[i];
	}
	printf("%d\n",max);
	memset(b,0,sizeof(b)); max=0;
	for(int i=1;i<=n;i++)
	{
		k=0;
		for(int j=1;j<=i;j++)
			if( ( f[i]>f[j] ) && ( k<b[j] ) ) k=b[j];
		b[i]=k+1;
		if(b[i]>max) max=b[i];
	}
	printf("%d",max);
	return 0;
}
