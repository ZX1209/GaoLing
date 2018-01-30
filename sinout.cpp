#include<string>
#include<iostream> 
#include<cmath>
#include<sstream>

using namespace std;


////////////////////////////////////
//模板函数：将string类型变量转换为常用的数值类型（此方法具有普遍适用性） 
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
//模板函数：将基本数据类型转换成字符串
////////////////////////////////////////////////
template<typename T> string tostring(const T& t)
{
	ostringstream oss;  //创建一个格式化输出流
	oss << t;             //把值传递如流中
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
