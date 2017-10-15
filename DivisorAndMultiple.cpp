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

int GcdXunHuan(int L,int R)
{
  int temp;
  while((temp=L%R)!=0)
  {
    L=R;
    R=temp;
  }
  return R;
}

int MoreSubtractiveMethod(int A, int B,int N=0)
{
  if (A<B) {
    Swap(&A,&B);
  }

  if (A-B==B) {
    return N*2+B;
  }


  if (IsEven(A)&&IsEven(B)) {
    return MoreSubtractiveMethod(A,B,N+1);
  }
  else if(A-B>B){
    return MoreSubtractiveMethod(A-B,B,N);
  }
  else {
    return MoreSubtractiveMethod(B,A-B,N);
    
  }
}


int main()
{
  //get input x0 y0
  int x0,y0;
  int sum=0;
  int p;
  int minin;
  int maxin;

  cin>>x0>>y0;
  int limit=x0*y0;
  minin=x0>y0?y0:x0;
  maxin=x0>y0?x0:y0;

  for (p=minin;p<=maxin;p++)
  {
    if (limit%p==0&&GcdXunHuan(p,limit/p)==x0) sum++;
    
  }

  cout<<sum<<endl;


  

  return 0;
}
