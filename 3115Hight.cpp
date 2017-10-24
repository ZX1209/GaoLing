/****************************************
*Filename:3115Hight.cpp
*CreateTime:2017/10/24 Tue 19:8:47
*CreateBy:GaoLing
*Email:zxgaoling@gamil.com/1404919041@qq.com
*CopyRight:whatever
****************************************/


#include <iostream>
#include <stdio.h>
using namespace std;

void CharConvert(char* Start)
{
  for (int i = 500; i >0; i--) {
    int flag=(Start[i]-'0')/10;
    if (flag) {
      Start[i-1]+=flag;
      Start[i]=(Start[i]-'0')%10+'0';
    }
  }
}



void Convert(unsigned long long* Start)
{
  for (int i = 0; i < 208; i++) {
    int flag=Start[i]/999999999999999999;
    if (flag) {
      Start[i+1]+=flag;
      Start[i]=Start[i]-flag*999999999999999999;
    }
  }
}




int read(unsigned long long* Start)
{
  char ch;
  int flag=1;
  int bit=0;
  int wei=0;
  unsigned long long val=0;
  while ((ch=getchar())!='\n') {
    if (((ch-'0')>9)||((ch-'0')<0)) {if(ch='-') flag=-1;}
    else if((ch-'0'<=9)&&(ch-'0'>=0)) {
      bit++;
      val=val*10+(ch-'0');

      if (bit>=18) {
        bit=0;
        Start[wei++]=val;
        
      }
      
    }
  }

  return val*flag;
}





int main()
{
  char A[501]={'\0'};
  char B[501]={'\0'};
  int a=500,b=500;
  int i=0;
  scanf("%s %s",A,B);
  
  while (A[a]=='\0') {
    a--;
  }

  while (B[b]=='\0') {
    b--;
  }
  int flag=a>b?1:0;

  while (a>=0&&b>=0) {
    int first=A[a--]-'0';
    int second=B[b--]-'0';

    if (first+second>9) {
      if (flag) {
        A[a]++;
        A[a+1]=first+second-10+'0';
      }
      else {
        B[b]++;
        B[b+1]=first+second-10+'0';
      }
    }
    else {
      if (flag) {
      A[a+1]=first+second+'0';
      }
      else {
      B[b+1]=first+second+'0';
      }

    }

  }

  CharConvert(A);
  CharConvert(B);

  


  if (flag) {
    while (A[i]!='\0') {
      cout<<A[i];
      i++;
    }
    
    cout<<endl;
  }
  else {
     while (B[i]!='\0') {
      cout<<B[i];
      i++;
    }
    
    cout<<endl;
  }


  return 0;
}
