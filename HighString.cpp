#include<iostream>
#include<string>
#include<sstream> 

using namespace std;

int ctoi(char c)
{
	return c - '0';
}


//ģ�庯������string���ͱ���ת��Ϊ���õ���ֵ���ͣ��˷��������ձ������ԣ�  
template <class Type>  
Type stringToNum(const string& str)  
{  
    istringstream iss(str);  
    Type num;  
    iss >> num;  
    return num;      
}  
  
  
//ostringstream�����������и�ʽ��������������ڽ���������ת��Ϊstring����
//ostringstreamֻ֧��<<������
template<typename T> string toString(const T& t){
    ostringstream oss;  //����һ����ʽ�������
    oss<<t;             //��ֵ����������
    return oss.str();   
}

////////////////////////////////////////////////////////////
//first string always the biggest one
///////////////////////////////////////////////////////////
string StringPlus(string firststr, string secondstr, bool i)
{
	if (i)
	{
		//�Ӻ���ǰ		
		//end() ָ�� ���һ��'\0'
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
		//��ǰ����		
		//begin() ָ�� ��һ��Ԫ��
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
