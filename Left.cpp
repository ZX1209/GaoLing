#include <iostream>
using namespace std;

int Rcout(int N)
{
  if (N==1) {
    return 1;
  }
  else if (N==2||N==3) {
    return 2;
  }
  else if(N==4||N==5){
    return 4;
  }
  else if(N==6||N==7){
    return 6;
  }

  int count=1;

  for (int i = 1; i <=N/2; i++) {
    count+=Rcout(i);
    cout<<count;
  }

  return count;

}



int main()
{
  int n;
  cin>>n;

  cout<<Rcout(n);



  return 0;
}
