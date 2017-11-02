#include<queue>
#include<set>
#include<iostream>
#include<string>
#include<map>

using namespace std; 

struct hf_node
{
	char ch;
	int val;
	hf_node* left;
	hf_node* right;
	bool operator<(const hf_node&a)const
	{
		return val>a.val;
	}
};

struct hf_map
{
	char ch;
	char str[10];
};

map<char,string,less<char> > code_map;

set<char> the_one;
multiset<char> multiset_all_char;

priority_queue<hf_node>  pd_process;

hf_node* create_new(hf_node& o)
{
	hf_node* tmp;
	tmp=new hf_node;
	tmp->ch=o.ch;
	tmp->val=o.val;
	tmp->left=o.left;
	tmp->right=o.right;
	
	return tmp;
	
}




void hui_shu(hf_node now,string chcode)
{
	if(now.ch!='\0')
	{
		code_map.insert(make_pair<char,string>(now.ch,chcode));	
	}
	else{
		hui_shu(*(now.left),chcode+"0");
		hui_shu(*(now.right),chcode+"1");
	}
}

int main()
{
	hf_node tmp;
	hf_node tmpl;
	hf_node tmpr;
	string str1;
	
	char char_tmp;
	while(cin>>char_tmp&&char_tmp!=';')
	{
		the_one.insert(char_tmp);
		multiset_all_char.insert(char_tmp);
	}
	
	set<char>::iterator set_pos;
	//multiset<char>::iterator multiset_pos;
	
	int i=1;
	//init the all hf node vector
	//ignore the 
	for(set_pos=the_one.begin();set_pos!=the_one.end();set_pos++,i++)
	{
		tmp.ch=*set_pos;
		tmp.val=multiset_all_char.count(*set_pos);
		pd_process.push(tmp);
		
		//studio[i].ch=*set_pos;
		//studio[i].val=multiset_all_char.count(*set_pos);
	}
	
	cout<<pd_process.top().val;
	
	while(pd_process.size()>1)
	{
		tmpl=pd_process.top();
		pd_process.pop();
		cout<<tmpl.val; 	
		tmpr=pd_process.top();
		pd_process.pop();
		
		tmp.ch='\0';
		tmp.val=tmpl.val+tmpr.val;
		tmp.left=create_new(tmpl);
		tmp.right=create_new(tmpr);
		
		pd_process.push(tmp);
	}
	
	
	
	//cout<<pd_process.top().val;
	
	hui_shu(pd_process.top(),str1);
	
	for(set_pos=the_one.begin();set_pos!=the_one.end();set_pos++,i++)
	{
		cout<<*set_pos<<" "<<code_map.find(*set_pos)->second;
		
		//studio[i].ch=*set_pos;
		//studio[i].val=multiset_all_char.count(*set_pos);
	}
	
	
	
	
	
	
	
	
	return 0;
	
}
