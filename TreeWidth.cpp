/****************************************
*Filename:TreeWidth.cpp
*CreateTime:2017/10/16 Mon 19:14:43
*CreateBy:GaoLing
*Email:zxgaoling@gamil.com/1404919041@qq.com
*CopyRight:whatever
****************************************/


#include <iostream>
using namespace std;


int tree[16][2]={0};

int findx(int x)
{
  int i=0;
  while(tree[i][0]!=x&&tree[i][1]!=x)
  {
    i++;
    if(i==16) return -1;
  }
  return i+1;
}

int TreeDeep(int i)
{
  if (tree[i-1][0]==0) {
    return 1;
  }
  else {
    TreeDeep(tree[i-1][0]);
  }

  if (tree[i-1][1]==0) {
    return 0;
  }
  cout<<tree[i][0]<<tree[i][1];
  return 0;
}

//////////////////////
//find the father of node N
//-1 for not found!
//////////////////////
int FindFather(int N)
{
  for(int i=0;i<16;i++)
  {
    if (tree[i][0]==N||tree[i][1]==N) {
      return i+1;
    }
  }

  return -1;
}

int ArraySwap(int* A,int* B)
{
  int tmp=0;
  for (int i = 0; i < 32; i++) {
    tmp=A[i];
    A[i]=B[i];
    B[i]=tmp;
  }


}


int Width(int N)
{
  int work[32]={0};
  int tmp[32]={0};
  work[0]=1;
  int j=0;
  int k=0;

  for (int i = 0; i < N; i++) {
    for (int j = 0,int k=0; j < 32; j++) {
      tmp[k++]=tree[j][0];
      tmp[k++]=tree[j][1];
    }
    
    
  }
}


int main()
{
  int n;
  cin>>n;


  for (int i = 0; i < n; i++) {
    cin>>tree[i][0]>>tree[i][1];
  }

  cout<<FindFather(4);

  //cout<<findx(3);




  return 0;
}
