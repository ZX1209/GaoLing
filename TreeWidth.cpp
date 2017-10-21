/****************************************
*Filename:TreeWidth.cpp
*CreateTime:2017/10/16 Mon 19:14:43
*CreateBy:GaoLing
*Email:zxgaoling@gamil.com/1404919041@qq.com
*CopyRight:whatever
****************************************/


#include <iostream>
using namespace std;


int Max(int A,int B)
{
  if (A>=B) {
    return A;
  }
  else 
  return B;
  
}

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

/////////////////////////
//
int TreeDeep(int i)
{
  if (i==0) {
    return 0;
  }else if (tree[i-1][0]==0&&tree[i-1][1]==0) {
    return 1;
  }

  return Max(TreeDeep(tree[i-1][0]),TreeDeep(tree[i-1][1]))+1;
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

///////////////////////////
//copy array B to array A
//only for 32 int array 
//i will improve it
//////////////////////////
void ArraySwap(int* A,int* B)
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
  int work[32]={1};
  int tmp[32]={0};
  int count=0;
  int k=0;
  for (int j = 0; j < N; j++) {
   for (int i = 0; i < 32; i++) {
    if (work[i]!=0) {
      tmp[k++]=tree[work[i]-1][0];
      tmp[k++]=tree[work[i]-1][1];
    }
   }
   ArraySwap(work,tmp);
   k=0;
  }

  for (int i = 0; i < 32; i++) {
    if (work[i]!=0) {
      count++; 
    }
  }
  return count;
}

int main()
{
  int n;
  int maxwidth=0;
  cin>>n;


  for (int i = 0; i < n; i++) {
    cin>>tree[i][0]>>tree[i][1];
  }

  //cout<<FindFather(4)<<endl;

  for (int i = 0; i < n ; i++) {
    if (maxwidth<Width(i)) {
      maxwidth=Width(i);
    }
  }
  cout<<maxwidth<<" "<<TreeDeep(1)<<endl;
  //cout<<findx(3);




  return 0;
}
