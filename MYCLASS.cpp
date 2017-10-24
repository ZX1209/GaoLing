#include<iostream>
#include<cstring>
using namespace std;

class MYCLASS
{
  private:
    int min;
    int max;
    int data[200];
    int num;
    int di;
  public:
    MYCLASS(int i, int a)
    {
      min=i;
      max=a;
      num=0;
      memset(data,0,200);
      di=0;


      for (int i = min+1; i < max; i++) {
        if (!(i%3)) {
          data[di++]=i;
        }
      }

    }

    void print()
    {
      for (int i = 0; i < di; i++) {
        cout<<data[i]<<" ";
      }
      cout<<endl;
    }

    int process()
    {
      return di;

    }

};

int main()
{
  int min,max;
  cin>>min>>max;

  MYCLASS test(min,max);
  test.print();
  cout<<test.process();


  return 0;
}
