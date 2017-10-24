#include <iostream>
#include <stdio.h>

using namespace std;

class SUM
{
  public:
    SUM(int init[3][3],int x,int y)
    {
      int sum=0;
        for (int j = 0; j < y; j++) {
          sum+=init[0][j];
          sum+=init[x-1][j];
        }

        for (int i = 1; i < x-1; i++) {
          sum+=init[i][0];
          sum+=init[i][y-1];
        }


      for (int i = 0; i < x; i++) {
       for (int j = 0; j < y; j++) {
         cout<<init[i][j]<<" ";
       } 
       cout<<endl;
      }
      cout<<sum;
    }

};

int read()
{
  char ch;
  int flag=1;
  int val=0;
  while ((ch=getchar())!='\n') {
    if (((ch-'0')>9)||((ch-'0')<0)) {if(ch='-') flag=-1;}
    else if((ch-'0'<=9)&&(ch-'0'>=0)) {val=val*10+(ch-'0');}
  }

  return val*flag;
}

int main()
{
  int demo[3][3];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin>>demo[i][j];
    }
    
  }

  SUM test(demo,3,3);
  
  return 0;

}
