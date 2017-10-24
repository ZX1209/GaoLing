/****************************************
*Filename:HannoTower.cpp
*CreateTime:2017/10/21 Sat 22:36:21
*CreateBy:GaoLing
*Email:zxgaoling@gamil.com/1404919041@qq.com
*CopyRight:whatever
****************************************/


#include <iostream>
using namespace std;

void HannoTower(int n, int disk, char A, char B, char C)
{
  if (n==1) {
    cout<<disk<<" from "<<A<<" to "<<C<<endl;
  }
  else {
  HannoTower(n-1,disk-1,A,C,B);
  HannoTower(1,disk,A,B,C);
  HannoTower(n-1,disk-1,B,A,C);
  }
}


int HannoStep(int n)
{
  if (n==2) {
    return 3;
  }
  else {
    return 1+2*HannoStep(n-1);
  }
}

int FastHannoStep(int n)
{
  int stdstep=1;
  for (int i = 1; i < n; i++) {
    stdstep=2*stdstep+1;
  }
  return stdstep;
}


int main()
{
  int n;
  cin>>n;

  cout<<FastHannoStep(n)<<endl;

  HannoTower(n, n,'A','B','C');

  return 0;
}
