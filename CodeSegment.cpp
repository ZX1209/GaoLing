//descripition:
//determine whether it is evne number
//return:
//0   odd
//1   even
int IsEven(int N)
{
  return !(N&0x1);
}

/*????????????????????????????????
float InvSqrt(float x)
{
	float xhalf = 0.5f*x;
	int i = *(int*)&amp;x; // get bits for floating VALUE
	i = 0x5f375a86- (i&gt;&gt;1); // gives initial guess y0
	x = *(float*)&amp;i; // convert bits BACK to float
	x = x*(1.5f-xhalf*x*x); // Newton step, repeating increases accuracy
	x = x*(1.5f-xhalf*x*x); // Newton step, repeating increases accuracy
	x = x*(1.5f-xhalf*x*x); // Newton step, repeating increases accuracy
 
	return x;
}
*/
//system sqrt();
float Sqrt(float X)
{

	return 1/Q_rsqrt(X);
}

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
    return y;
}


int IsPrimer(int N)
{
  int limit = (int)Sqrt(N);
  //range from 2 to n^(1/2)
  for (int i = 2; i < limit; i++) {
    if (N%i==0) return 0;
  }
  return 1;
}

///////////////////////////////////
//to read the argv   yes!!!!
////////////////////////////////////
#include <stdio.h>

int main(int argc,char * argv[])
{
	int i=0;
	//confirm every argv and it's next
	for(i=1;i<argc-1;i++)
	{
		//the argv is the std argv while the next not
		//so it is the correct one
		if(argv[i][0]=='-'&&argv[i][1]=='-'&&!(argv[i+1][0]=='-'&&argv[i+1][1]=='-'))
				printf("%s:%s\n",(argv[i]+2),argv[i+1]);

	}


	return 0;

}

