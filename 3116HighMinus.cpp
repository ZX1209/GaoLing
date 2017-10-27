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
#include <iomanip>
using namespace std;

////////////////////////////////////////////
//likes the normal number
//1234 means 1*1+2*10+3*100+4*10000
//the big number use base like this
//[1234,123,1]  means 1234*1+123*100000000+1*100000000*100000000
//when it comes to the plus action
//123+400 means (1+0)*1+(2+0)*10+(1+4)*100
//so like the bignum
//[1,2]+[23,4]  means (1+23)*1+(2+4)*100000000 
//so as minux and mutilplication
////////////////////////////////////////////




#define MAX_NUMBER_DIGITAL 500
#define DIGITAL_PER_UNIT 8
#define MAX_UNIT_NUM MAX_NUMBER_DIGITAL/DIGITAL_PER_UNIT+1 

long long spow(int i)
{
	long long L=1;
	while(i--) L=L*100000000;
	return L;
}


////////////////
//unsigned number only
//could be improve but forget it
////////////////////
class BigNum
{
	public:
		void reset()
		{
			memset(data,0,sizeof(data));
			wei=0;
			
		}
		BigNum()
		{
			memset(data,0,sizeof(data));
			wei=0;
		}
		
		BigNum(BigNum& other)
		{
			wei=other.wei;
			for(int  i=0;i<MAX_UNIT_NUM;i++)
			{
				data[i]=other.data[i];
			}
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
			
			
			
			
		
			
			

			
			convert();
		}
		
		void convert()
		{
			for(int i=0;i<MAX_UNIT_NUM;i++)
			{
				long long tmp=data[i]/100000000;
				if(tmp)
				{
					data[i+1]+=tmp;
					data[i]=data[i]%100000000;
				}
			}
			
			int i=MAX_UNIT_NUM;
			while(data[--i]==0);
			wei=i;
		}
		
		void show()
		{
			int i=MAX_UNIT_NUM;
			while(data[--i]==0);
			
			cout<<data[i--];
			
			while(i>=0)
			{
				cout<<setfill('0')<<setw(8)<<data[i--];
			}
			cout<<endl;
		}
		
		void getone(int i)
		{
			if(data[i+1]>0)
			{
				data[i+1]-=1;
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
	unsigned long long	data[MAX_UNIT_NUM];	
		
	int wei;
		
	private:

	
};

//asume that A is Bigger!!!!!
BigNum operator+(BigNum &A,BigNum &B)
{
	int limit=A.wei>B.wei?A.wei:B.wei;
	BigNum tmp;
	for(int i=0;i<=limit;i++)
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

//A is bigger then B
BigNum operator*(BigNum &A,BigNum &B)
{
	BigNum FuckA;
	BigNum FuckB;
	for(int i=0;i<=A.wei;i++)
	{
		for(int j=0;j<=B.wei;j++)
		{
			FuckB.data[i+j]=A.data[i]*B.data[j];
			
		}
		
		FuckB.convert();
		FuckA=FuckB+FuckA;
		FuckA.convert();
		FuckB.reset();
		
	} 
	
	return FuckA;
	
	
}




//////////////////////////////////////
//A is biger than B
/////////////////////////////////////
BigNum operator-(BigNum &A,BigNum &B)
{
	BigNum tmp;
	long long tmpll=0;
	long long test;
	for(int i=0;i<=A.wei;i++)
	{                
	    tmpll=A.data[i]-B.data[i];
		if(tmpll>=0)
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
	///////////////////////////////////////
	//FRO -{500 DIGITAL} TO {500 DIGITAL}
	////////////////////////////////////////
	char tmpa[MAX_NUMBER_DIGITAL+1]={'\0'};
	char tmpb[MAX_NUMBER_DIGITAL+1]={'\0'};
	scanf("%s %s",tmpa,tmpb);
	
	BigNum A(tmpa);
	BigNum B(tmpb); 
	//A.show();
	//B.show();
	if((A>B)>=0)
	{
		(A*B).show();
	}
	else 
	{
		//cout<<"-";
		(B*A).show();
	}
	

  return 0;
}

