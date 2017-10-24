/****************************************
*Filename:1214Line.cpp
*CreateTime:2017/10/23 Mon 18:51:59
*CreateBy:GaoLing
*Email:zxgaoling@gamil.com/1404919041@qq.com
*CopyRight:whatever
****************************************/


#include <iostream>
using namespace std;
///////////////////////////////
//show number [Start+0,Start+N-1]
void ShowArray(int Start[][2],int N)
{
  for (int i = 0; i < N; i++) {
    cout<<Start[i][0]<<" "<<Start[i][1]<<";";
  }
  cout<<endl;
}

////////////////////////////////////////
//find the duandian most resent p basicly p+1
///////////////////////////////////////////
int FindStart(int Start[][2],int P)
{
    for (int i = 0; i < 100; i++) {
      if (Start[i][0]==P) {
        return i;
      }
    }

  return 0;

}

int FindMinNext(int Start[][2],int Len[],int p,int Max)
{
  int tmp;
  int min;
  int minn;
  p++;

  while (!(tmp=FindStart(Start,p))) {
    p++;

    if (p>Max) {
      return 0;
    }
  }

  while (tmp=FindStart(Start,p)) {
    Start=Start+tmp;
    if (min>Len[tmp]) {
      min=Len[tmp];
      minn=tmp;
    }
  }

  return minn;
}

void Sort(int Start[][2],int N)
{
  int first,second;
  int minn;
  int min;
  for (int i = 0; i < N; i++) {
    int min=Start[i][0];
    int minn=i;
    for (int j = i; j < N; j++) {
      if (min>Start[j][0]) {
        min=Start[j][0];
        minn=j; 
      }
    }
    first=Start[minn][0];
    second=Start[minn][1];
    Start[minn][0]=Start[i][0];
    Start[minn][1]=Start[i][1];
    Start[i][0]=first;
    Start[i][1]=second;

  }

}

int main()
{
  int N;
  int Lines[100][2]={{0,0}};
  int s=0,e=0;
  int num[1999]={0};
  int len[100]={0};
  int min,max;
  int minn,maxn;
  int count=0;
  cin>>N;
  for (int i = 0; i < N; i++) {
    cin>>Lines[i][0]>>Lines[i][1];

    if (i==0) {
      max=min=Lines[i][0];
      minn=maxn=0;
    }

    if (Lines[i][0]>Lines[i][1]) {
      int tmp=Lines[i][0];
      Lines[i][0]=Lines[i][1];
      Lines[i][1]=tmp;
    }

    s=Lines[i][0]+1;
    e=Lines[i][1]-1;
    len[i]=e-s+1;

    //from s to e
    while (s<=e) {
      num[999+s++]++;
    }

    if (Lines[i][0]<min) {
      min=Lines[i][0];
      minn=i;
    }

    if (Lines[i][1]>max) {
      max=Lines[i][1];
      maxn=i;
    }
  }

  //ShowArray(Lines,N);
  Sort(Lines,N);
  //ShowArray(Lines,N);

  int left=Lines[N-1][0];
  count++;

  for (int i = N-1; i>=0; i--) {
    if (Lines[i][1]<=left) {

      left=Lines[i][0];
      count++;
      
    }
  }


  cout<<count;
  //wwhile(FindMinNext(Lines,i,max)!=maxn);








  return 0;
}
