#include<iostream>
#include<fstream>
using namespace std;

int main()
{
  fstream explore;
  long s,e;
  explore.open("explore.txt",ios::app);

  explore<<"\nou ou ou ou ou"<<endl;
  //s = explore.tellg();
  explore.seekg(0,ios::beg);

  s = explore.tellg();

  explore.seekg(0,ios::end);

  e = explore.tellg();

  cout<<"file out success? whatever"<<e-s<<endl;



  explore.close();

  return 0;
}
