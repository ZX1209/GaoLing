#include <iostream>
using namespace std;


float Q_rsqrt( float number )
{
    long i;
    float x2, y;
    const float threehalfs = 1.5F;

    x2 = number * 0.5F;
    y = number;
    i = * ( long * ) &y; // evil floating point bit level hacking
    i = 0x5f3759df - ( i >> 1 ); // what the fuck?
    y = * ( float * ) &i;
    y = y * ( threehalfs - ( x2 * y * y ) ); // 1st iteration
    // y = y * ( threehalfs - ( x2 * y * y ) ); // 2nd iteration, this can be removed

    #ifndef Q3_VM
    #ifdef __linux__
         //assert( !isnan(y) ); // bk010122 - FPE?
    #endif
    #endif
    //check Q_rsqrt 
    //cout<<"Q_rsqrt"<<y<<endl;
    return y;

}


float Sqrt(float X)
{

  //check
  //cout<<"Ssqrt"<<1/Q_rsqrt(X)<<endl;
  return 1/Q_rsqrt(X);
}


int IsPrimer(int N)
{
  float limit =Sqrt(N);
  //cheak limit
  //cout<<limit;
  //range from 2 to n^(1/2)
  for (int i = 2; i < limit; i++) {
    if (N%i==0) return 0;
  }
  return 1;
}




int main()
{

  int in;
  cin>>in;
  if (IsPrimer(in)) {
    cout<<"\\t";
    
  }
  else {
    cout<<"\\n";
  }
  return 0;
}
