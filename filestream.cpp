#include<iostream>
#include<stdio.h>
#include<fstream>

using namespace std;

int main()
{
  ofstream of("./test.txt",ios::out);
  of<<"hehe"<<endl;
  of.close();

  ifstream inf("./test.txt",ios::in);
  char ou[40]={'\0'};
  inf>>ou;
  cout<<ou;
  return 0;
}
