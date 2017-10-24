/****************************************
*Filename:1098Card.cpp
*CreateTime:2017/10/23 Mon 12:24:56
*CreateBy:GaoLing
*Email:zxgaoling@gamil.com/1404919041@qq.com
*CopyRight:whatever
****************************************/


#include <iostream>
using namespace std;

void ShowArray(int Start[],int N)
{
  for (int i = 0; i < N; i++) {
    cout<<Start[i]<<" ";
  }
  cout<<endl;
}

//////////////////////////////
//find the peace subarray start
//from Start point
//return i (where peace happened + 1)
////////////////////////////////
int SearchPeace(int Start[])
{
  int tmp=Start[0];
  int i=0;
  //may cause problem
  while(!tmp&&i<=100)
  {
    tmp+=Start[i];
    i++;
  }

  return i;
  

}

////////////////////////////////
//find Max from Start+0 to Start+N-1
//return the max value
////////////////////////////////
int FindMax(int Start[],int N)
{
  int tmp=Start[0];
  int maxnum=0;
  for (int i = 0; i < N; i++) {
    if (tmp<Start[i]) {
      tmp=Start[i];
      maxnum=i;
    }
  }

  return maxnum;
}


int FindLeastMove(int Start[], int N)
{
  //int step=0;
  FindMax(Start,SearchPeace(Start));
  return 0;

}

int MakeItAvg(int Start[],int avg,int N)
{
  int cha=Start[0]-avg;
  while (cha) {
    
  }

  return 0;

}

///////////////////////////////////////////
//int array Start 
//the element above in Start N
//avg
///////////////////////////////////
int MoPing(int Start[],int N,int avg)
{
  int step=0;
  for (int i = 0; i < N-1; i++) {
    if (Start[i]!=avg) {
      Start[i+1]+=Start[i]-avg;
      Start[i]=avg;
      step++;
    }
  }

  return step;
}

int main()
{
  int N;
  int A[100]={0};
//  int B[100]={0};
  int sum=0;
  int avg=0;

  cin>>N;
  for (int i = 0; i < N; i++) {
    cin>>A[i];
    sum+=A[i];
  }

  avg=sum/N;

  cout<<MoPing(A,N,avg);










  return 0;
}
