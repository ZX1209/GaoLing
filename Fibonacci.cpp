#include <iostream>
using namespace std;

int main()
{
  int n;
  int f1=1,f2=1,f3=1;
  cin>>n;
  if (n<2||n>40) {
    cout<<1;
    return 0;
  }


  for (int i = 3; i <= n ; i++) {
    f3=f2+f1;
    f1=f2;
    f2=f3;
  }
  cout<<f3;


  return 0;
}
