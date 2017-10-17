#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
  //just the number to chanrater
  char Mcode[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
  //n<=100
  char num[10]={'0'};
  int plussign=1;
  int n;
  int m;
  int cout=0;//count number bit
  cin>>n>>m;

  if (n<0) {
    n=-n;
    plussign=-1;
  }
  else if(m>16||m<=0||n>100){
    printf("out of range!");
    return 0;
  }

  while(n)
  {
    num[cout]=Mcode[n%m];
    n=n/m;
    cout++;

  }

  if (plussign==-1){
    num[++cout]='-';
    
  }

  while(cout+1)
  {
    printf("%c",num[cout]);
    cout--;
  }

  return 0;
}
