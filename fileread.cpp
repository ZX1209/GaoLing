#include<iostream>
#include<fstream>
#include<stdio.h>

using namespace std;

int main()
{
  ifstream fin("./test.txt",ios::in);

  char a;
  while(fin.get(a))
  {
    cout<<a;

  }

  if(fin.eof()) cout<<"EOF reached";
  else cout<<"reading error";
  fin.close();


  return 0;
}
