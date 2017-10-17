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


int main()
{
  int n;
  cin>>n;


  for (int i = 0; i < n; i++) {
    cin>>tree[i][0]>>tree[i][1];
  }

  cout<<findx(3);




  return 0;
}
