/****************************************
*Filename:FirstReverse.cpp
*CreateTime:2017/10/19 Thu 18:36:48
*CreateBy:GaoLing
*Email:zxgaoling@gamil.com/1404919041@qq.com
*CopyRight:whatever
****************************************/


#include <iostream>
using namespace std;

int fresult[33]={0};


////////////////////////
//could be the one with on reverse?
////////////////////////////////////
int f(int X)
{
  if (X>0) {
    return 5;
  }
  else if(fresult[30+X]!=0)
  {
    return fresult[30+X];
  }
  else {
    return fresult[30+X]=f(X+1)+f(X+2)+1;
  }
}

int main()
{
  fresult[30]=5;
  fresult[31]=5;
  fresult[32]=5;
  int x;
  cin>>x;
  cout<<f(x);

  return 0;
}
