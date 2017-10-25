/****************************************
*Filename:3115Hight.cpp
*CreateTime:2017/10/24 Tue 19:8:47
*CreateBy:GaoLing
*Email:zxgaoling@gamil.com/1404919041@qq.com
*CopyRight:whatever
****************************************/


#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
using namespace std;


////////////////
//unsigned number only
//could be improve but forget it
////////////////////
class BigNum
{
	public:
		BigNum()
		{
			memset(data,0,sizeof(data));
			wei=0;
		}
		
		BigNum(char *Start)
		{
			memset(data,0,sizeof(data));
			//find the minest wei
			int N=501;
			long long tmpval=0;
			int weiloop=0;
			int swei=0;
			while(Start[--N]=='\0');
			
			for(int i=N;i>=0;i--)
			{
				
				tmpval+=(Start[i]-'0')*pow(10,weiloop);
				weiloop+=1;
				
				if(weiloop==8)
				{
					data[swei]=tmpval;
					swei++;
					tmpval=0;
					weiloop=0;
				}
			}
			
			data[swei]=tmpval;
			
			
			
			
		
			
			
			int i=63;
			while(data[--i]==0);
			wei=i;
			
			convert();
		}
		
		void convert()
		{
			for(int i=0;i<63;i++)
			{
				int tmp=data[i]/100000000;
				if(tmp)
				{
					data[i+1]+=tmp;
					data[i]=data[i]%100000000;
				}
			}
		}
		
		void show()
		{
			int i=63;
			while(data[--i]==0);
			
			while(i>=0)
			{
				cout<<data[i--];
			}
			cout<<endl;
		}
		
		void getone(int i)
		{
			if(data[i+1])
			{
				data[i+1]--;
				data[i]+=100000000;
				
			}
			else
			{
				//will   ..... 
				getone(i+1); 
			}
			
			
		} 
		 

		
		 
	//////////////////////////////
	//every ull store 8 bit number
	//represent form 0 to 99999999
	/////////////////////////////
	//it store from the low level
	//to the heighest level
	////////////////////////////
	//| 12| 123  | 23  | 432  | 234  |34  |
	//is 342344322312312
	//usually the low level is full(whit 8 bit)
	////////////////////////////////////
	unsigned long long	data[63];	
		
	int wei;
		
	private:

	
};

//asume that A is Bigger!!!!!
BigNum operator+(BigNum &A,BigNum &B)
{
	BigNum tmp;
	for(int i=0;i<=A.wei;i++)
	{
		tmp.data[i]=A.data[i]+B.data[i];
	} 
	tmp.wei=A.wei;
	
	tmp.convert();
	return tmp;
	
}

int operator>(BigNum &A,BigNum &B)
{
	if(A.wei>B.wei)
	{
		return 1;
	}
	else if(A.wei==B.wei)
	{
		int i=0;
		for(int i=A.wei;A.data[i]==B.data[i];i--)
		{
			if(i<0) return 0;
			
		}
		
		if(A.data[i]>B.data[i])
		{
			return 1;
		}
		else
		{
			return -1;
		}
	}
	else
	{
		return -1;
	}
}


//////////////////////////////////////
//A is biger than B
/////////////////////////////////////
BigNum operator-(BigNum &A,BigNum &B)
{
	BigNum tmp;
	long long tmpll=0;
	long long test;
	for(int i=0;i<63;i++)
	{                
	    tmpll=A.data[i]-B.data[i];
		if(tmpll>0)
		{
			tmp.data[i]=tmpll;
		}
		else
		{
			A.getone(i);
			tmp.data[i]=A.data[i]-B.data[i];
			
		}
	} 
	
	tmp.convert();
	return tmp;
	
}

void CharConvert(char* Start)
{
  for (int i = 500; i >0; i--) {
    int flag=(Start[i]-'0')/10;
    if (flag) {
      Start[i-1]+=flag;
      Start[i]=(Start[i]-'0')%10+'0';
    }
  }
}



void Convert(unsigned long long* Start)
{
  for (int i = 0; i < 208; i++) {
    int flag=Start[i]/999999999999999999;
    if (flag) {
      Start[i+1]+=flag;
      Start[i]=Start[i]-flag*999999999999999999;
    }
  }
}




int read(unsigned long long* Start)
{
  char ch;
  int flag=1;
  int bit=0;
  int wei=0;
  unsigned long long val=0;
  while ((ch=getchar())!='\n') {
    if (((ch-'0')>9)||((ch-'0')<0)) {if(ch='-') flag=-1;}
    else if((ch-'0'<=9)&&(ch-'0'>=0)) {
      bit++;
      val=val*10+(ch-'0');

      if (bit>=18) {
        bit=0;
        Start[wei++]=val;
        
      }
      
    }
  }

  return val*flag;
}





int main()
{
	char tmpa[501]={'\0'};
	char tmpb[501]={'\0'};
	scanf("%s %s",tmpa,tmpb);
	
	BigNum A(tmpa);
	BigNum B(tmpb); 
	A.show();
	B.show();
	if((A>B)==1)
	{
		(A+B).show();
	}
	else
	{
		(B+A).show();
	}
	

  return 0;
}

