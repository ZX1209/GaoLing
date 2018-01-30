#include<iostream>
#include<string>
#include<sstream>
using namespace std;


int signcampare(char a, char b)
{
	int aa=0;
	int bb=0;
	
	switch(a)
	{
		case '+':
			aa=1;
			break;
		case '-':
			aa=1; 
			break;
		case '*':
			aa=2; 
			break;
		case '/':
			aa=2;
			break;
		case '(':
			aa=3;
			break;
		case ')':
			aa=3;
			break;
	}
	
	switch(b)
	{
		case '+':
			bb=1;
			break;
		case '-':
			bb=1; 
			break;
		case '*':
			bb=2; 
			break;
		case '/':
			bb=2;
			break;
		case '(':
			bb=3;
			break;
		case ')':
			bb=3;
			break;
	}
	
	
	return aa>bb;
	
	
}



//模板函数：将string类型变量转换为常用的数值类型（此方法具有普遍适用性）  
template <class Type>
Type stringtoType(const string& str)
{
	istringstream iss(str);
	Type num;
	iss >> num;
	return num;
}

template<typename T> string tostring(const T& t) {
	ostringstream oss;  //创建一个格式化输出流
	oss << t;             //把值传递如流中
	return oss.str();
}



int isNum(char c)
{
	if(c>='0'&&c<='9')
	return 1;
	
	
	return 0;
}

class Cell
{
	public:
		Cell()
		{
			d=0.0;
			c='\0';
		}
	double d;
	char c;
};

struct StackCell
{
	Cell C;
	StackCell* next;
};


class Stack
{
	public:
		Stack()
		{
			top=NULL;
		}
		
		Cell pop()
		{
			Cell tmpCell=top->C;;
			StackCell* tmp=top;
			top=top->next;
			delete tmp;
			return tmpCell;	
		}
		
		Cell TOP()
		{
			return top->C;
		}
		
		void push(Cell c)
		{
			StackCell* tmp=new StackCell;
			tmp->C=c;
			tmp->next=top;
			top=tmp; 
		}
		
	    void push(double dd)
		{
			StackCell* tmp=new StackCell;
			tmp->C.d=dd;
			tmp->next=top;
			top=tmp; 
		}
		
	    void push(char cc)
		{
			StackCell* tmp=new StackCell;
			tmp->C.c=cc;
			tmp->next=top;
			top=tmp; 
		}
		
		int isEmpty()
		{
			return top==NULL; 
		} 
		
		int clear()
		{
			while(top!=NULL)
			{
				StackCell* tmp=top;
				top=top->next;
				delete tmp;
			}
		} 
		
		
		
		StackCell* top;
};



class CalCuCore
{
	public:
		CalCuCore()
		{ 
		/*
			cout<<"need a express!"<<endl;
			~CalCuCore();		
		*/	
		}
		
		CalCuCore(string zhong)
		{
			result = 0;
			zhongtohou(zhong);
			CoreProcess();
			

		}
		
		
		void zhongtohou(string zhong)
		{
			string::iterator tmp_str_it = zhong.begin();
			
			while(tmp_str_it<zhong.end())
			{
				
				///////////////////////////////////////
				//应该用栈了
				///////////////////////////////////////// 
				if(isNum(*tmp_str_it)||*tmp_str_it=='.')
				{
					hou+=*tmp_str_it;
					
				}
				else
				{
					hou+=';';
					
					if(stack.isEmpty())
					{
						stack.push(*tmp_str_it);
					}
					else
					{
			
						switch(*tmp_str_it)
						{
							case ')':
								      
								while((stack.TOP().c!='(')&&!stack.isEmpty())
								{
									hou+=stack.pop().c;
									hou+=';';
								}
								
								if(!stack.isEmpty()&&(stack.TOP().c=='('))
								{
									stack.pop(); 	
								}
								
							
							break;
							
							case '(':
								stack.push('(');
							
							break;
							
							case '*':  
							while(!stack.isEmpty()&&!signcampare('*',stack.TOP().c)&&stack.TOP().c!='(')
							{
								hou+=stack.pop().c;
								hou+=';';
								
							}
							stack.push('*');
							
							break;
							
							case '/':
							while(!stack.isEmpty()&&!signcampare('/',stack.TOP().c)&&stack.TOP().c!='(')
							{
								hou+=stack.pop().c;
								hou+=';';
								
							}
							stack.push('/');
							
							break;	
							
							case '-': 
							while(!stack.isEmpty()&&!signcampare('-',stack.TOP().c)&&stack.TOP().c!='(')
							{
								hou+=stack.pop().c;
								hou+=';';
								
							}
							stack.push('-');
							break;
							
							case '+': 
							//栈顶元素大于'+'的优先级 
							while(!stack.isEmpty()&&!signcampare('+',stack.TOP().c)&&stack.TOP().c!='(')
							{
								hou+=stack.pop().c;
								hou+=';';
								
							}
							stack.push('+');
	                    
							break;
								
							
	                    }
					 }
				}
				
				tmp_str_it++;
			}
			hou+=';';
			
			while(!stack.isEmpty())
			{
				hou+=stack.pop().c;
				hou+=';';
				
			}	
			
		}
		
		void CoreProcess()
		{
			string tmp;
			double tmpd=0.0;
			string::iterator tmp_str_it = hou.begin();
			
			while(tmp_str_it<hou.end())
			{
					if(isNum(*tmp_str_it)||*tmp_str_it=='.')
					{
						tmp+=*tmp_str_it;
						
					}
					else
					{
						switch(*tmp_str_it)
						{
							case ';':
								if(tmp.empty())
								{
									break;	
								}
								else
								{
									stack.push(stringtoType<double>(tmp));
									tmp.clear();
							    }
							    
							    
								break;
								
								
							case '+':
								//cout<<"----------------"<<stack.TOP().d<<"-------------"<<endl;
								tmpd=stack.pop().d;
								//cout<<"----------------"<<stack.TOP().d<<"-------------"<<endl;
								tmpd+=stack.pop().d;
								//cout<<"----------------"<<tmpd<<"-------------"<<endl;
								stack.push(tmpd);
								break;
							
							case '-':
								tmpd=stack.pop().d;
								tmpd-=stack.pop().d;
								stack.push(tmpd);
								break;
								
								
							case '*':
								tmpd=stack.pop().d;
								tmpd*=stack.pop().d;
								stack.push(tmpd);
								break;
								
							case '/':
								tmpd=stack.pop().d;
								if(tmpd==0.0)
								{
									return;
								}
								tmpd=stack.pop().d/tmpd;
								stack.push(tmpd);
								break;
							
															
							default:
								
								break;		
						}
						
						
					}
					
				tmp_str_it++;
					
			}
			
			result=stack.TOP().d;
			stack.clear();
		}
			
		
		void show()
		{
			cout<<hou<<endl;
			cout<<result<<endl;
		}
		void clear()
		{
			
		}
		
		
		Stack stack;
		string hou; 
		double result;

		
};






int main()
{    
	while(1)
	{
		string in;
		cin>>in;
		
		CalCuCore test(in);
		
		test.show();
		in.clear(); 
		test.clear();
		
	}
	
	


 return 0; 
} 
