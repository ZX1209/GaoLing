#include<string>
#include<iostream> 
#include<cmath>
#include<sstream>

using namespace std;


////////////////////////////////////
//ģ�庯������string���ͱ���ת��Ϊ���õ���ֵ���ͣ��˷��������ձ������ԣ� 
///////////////////////////////////
template <class Type>
Type stringtoType(const string& str)
{
	istringstream iss(str);
	Type num;
	iss >> num;
	return num;
}


double stringtodouble(const string& str)
{
	istringstream iss(str);
	double num;
	iss >> num;
	return num;
}

/////////////////////////////////////////////////
//ģ�庯������������������ת�����ַ���
////////////////////////////////////////////////
template<typename T> string tostring(const T& t)
{
	ostringstream oss;  //����һ����ʽ�������
	oss << t;             //��ֵ����������
	return oss.str();
}


int main()
{
	string tmp_str;
	while(1)
	{
		cin>>tmp_str;
		tmp_str+=tostring(sin(stringtodouble(tmp_str))).c_str();
		cout<<tmp_str<<endl;
		
	}
	
	
	
	
	return 0;
}
