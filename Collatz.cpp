#include <iostream>
using namespace std;

int IsEven(int N)
{
  return !(N&0x1);
}

//依卡兹拉猜想的归律，返回传入数’折‘半至1所需的次数
int CallatzTimes(int N)
{
    static int count = 0;


    if(N>=0)
    {
       if(N==1)
       {
         int tcount=count;
          count=0;
          return tcount;
       }
       else 
       {
            if(IsEven(N))
            {
                count++;
                CallatzTimes(N/2);
            }
            else
            {
                count++;
                /////////////////////////////
                //some says it is 3*n+1 while
                //others says it is (3*n+1)/2
                //how strange!
                //CallatzTimes((3*N+1)/2);
                CallatzTimes(3*N+1);
            } 
        }
 
    }
    else 
    {
      count=0;
      return -1;
    }
}


int main()
{
  int T;
  cin>>T;
  int in[T]={0};

  for(int i=0;i<T;i++)
    cin>>in[i];

  for (int i = 0; i < T; i++) {
    cout<<CallatzTimes(in[i])<<endl;
  }


  return 0;
}
