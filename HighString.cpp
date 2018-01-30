#include<iostream>
#include<string>
#include<sstream> 

using namespace std;

int ctoi(char c)
{
	return c - '0';
}


//模板函数：将string类型变量转换为常用的数值类型（此方法具有普遍适用性）  
template <class Type>  
Type stringToNum(const string& str)  
{  
    istringstream iss(str);  
    Type num;  
    iss >> num;  
    return num;      
}  
  
  
//ostringstream对象用来进行格式化的输出，常用于将各种类型转换为string类型
//ostringstream只支持<<操作符
template<typename T> string toString(const T& t){
    ostringstream oss;  //创建一个格式化输出流
    oss<<t;             //把值传递如流中
    return oss.str();   
}

////////////////////////////////////////////////////////////
//first string always the biggest one
///////////////////////////////////////////////////////////
string StringPlus(string firststr, string secondstr, bool i)
{
	if (i)
	{
		//从后往前		
		//end() 指向 最后一个'\0'
		string::iterator tmp_str_it1 = firststr.end()-1;
		string::iterator tmp_str_it2 = secondstr.end()-1;

		while (tmp_str_it2 >= secondstr.begin())
		{
			int tmpplus = ctoi(*tmp_str_it1)+ ctoi(*tmp_str_it2);
			if (tmpplus >= 10)
			{

				if (tmp_str_it1 == firststr.begin())
				{
					firststr.insert(tmp_str_it1,tmpplus-10+'0');
				}
				tmpplus -=10;
			}

			*tmp_str_it1 = tmpplus + '0';

			tmp_str_it1--;
			tmp_str_it2--;

		}
	}
	else
	{
		//从前往后		
		//begin() 指向 第一个元素
		string::iterator tmp_str_it1 = firststr.begin() ;
		string::iterator tmp_str_it2 = secondstr.begin();

		while (tmp_str_it2 < secondstr.end())
		{
			int tmpplus = ctoi(*tmp_str_it1) + ctoi(*tmp_str_it2);
			if (tmpplus >= 10)
			{

				if (tmp_str_it1 == firststr.begin())
				{
					firststr.insert(tmp_str_it1, tmpplus - 10 + '0');
				}
				tmpplus -= 10;
			}

			*tmp_str_it1 = tmpplus + '0';

			tmp_str_it1++;
			tmp_str_it2++;

		}
	}

	return firststr;

}

class HighString
{
public:
	HighString()
	{
		Istring = "0";
		Dstring = "0";
	}


	/////////////////////////////
	//instr is something like "12.123"
	//"number.number"
	//'.'only Appear one or zero times
	////////////////////////////
	HighString(string instr)
	{
		HighString();
		int a=0;
		if ((a=instr.find('.')) != string::npos);
		{
			Dstring = instr.substr(0, a);
		}

		Istring = instr.substr(a+1);
	}

	HighString(string istr,string dstr)
	{
		Istring=istr;
		Dstring=dstr;
	}

	HighString operator+(HighString otherHs)
	{


	}

	void Convert()
	{

	}



	string Istring;
	string Dstring;
};


int main()
{
	string tmp;
	double dd=123.435432;
	string tryd("0.1");
	double d=stringToNum<double>(tryd);
	cout<<d<<endl;
	cout<<toString(dd)<<endl; 
	tmp=toString(dd);
	cout<<tmp<<endl;
	return 0;
}
