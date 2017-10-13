#include<iostream>
using namespace std;
//descripition:
////determine whether it is evne number
////return:
////0   odd
////1   even
int IsEven(int N)
{
  return !(N&0x1);
}

void Swap(int* L,int* R)
{
  int tmp = *L;
  *L=*R;
  *R=tmp;
}

int Gcd(int A,int B)
{
  if (A<B) {
    Swap(&A,&B);
  }

  int mod=A%B;
  if (mod==0) {
    return B;
  }
  else {
    return Gcd(B,mod);
  }
  
}


int MoreSubtractiveMethod(int A, int B,int N=0)
{
  if (A<B) {
    swap(&A,&B);
  }

  if (A-B=B) {
    return N*2+B;
  }


  if (IsEven(A)&&isEven(B)) {
    return MoreSubtractiveMethod(A,B,N+1);
  }
  else if(A-B>B){
    return MoreSubtractiveMethod(A,B,N)
  }
}


int main()
{
  //get input x0 y0
  int x0,y0;
  cin>>x0>>y0;

  cout<<Gcd(x0,y0)<<endl;


  

  return 0;
}
