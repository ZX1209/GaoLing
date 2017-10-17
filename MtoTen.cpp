#include <iostream>
#include <stdio.h>

using namespace std;

int CharToInt(char C)
{
  if (C>=48&&C<=58) {
    return C-'0';
  }
  else if(C>=56&&C<=90)
  {
    return 10+(C-'A');
  }
  return -1;
}

int main()
{
  //char Mcode[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
  char instr[10]={'\0'};
  int m;
  int outnum=0;
  int i=0;
  cin>>instr>>m;
  if (m<=16&&m>=0) {
    while (instr[i]!='\0') {
      outnum = outnum*m+(CharToInt(instr[i++])); 
    }
  } else {
    cout<<"out of range!";
  }

  cout<<outnum;



  return 0;
}
