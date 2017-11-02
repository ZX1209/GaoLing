#include<iostream>
#include<set>
#include<queue>
#include<map> 
#include<algorithm>
#include<list>

using namespace std;

struct hf_node
{
	char ch;
	int val;
	hf_node* left;
	hf_node* right;
};

struct hf_node root={'\0',0,NULL,NULL};

struct hf_map
{
	char ch;
	char str[10];
};


	set<char> the_one;
    multiset<char> multiset_all_char;
    
    ////////////////////////////////
    //
    hf_node* studio[10]={NULL};
    
hf_node* add_hf_node(char ch,int val)
{
	hf_node* tmp;
	tmp=new hf_node;
	tmp->ch=ch;
	tmp->val=val;
	
	reutrn tmp;
	
}

hf_node* find_least_one()
{
	//int min=0;
	int minx=0;
	for(int i=1;i<10;i++)
	{
		if(studio[i]!=NULL)
		{
			minx=i;
		}
	}
	
	hf_node* tmp_p;
	for(int i=1;i<10;i++)
	{
		if(studio[i]!=NULL&&studio[i]->val<min)
		{
			//min=studio[i]->val;
			minx=i;
		}
		
	}
	tmp_p=studio[minx];
	studio[minx]=NULL;
	
	return tmp_p;
}

void in_studio(hf_node* in)
{
	for(int i=1;i<10;i++)
	{
		if(studio[i]==NULL)
		{
			studio[i]=in;
		}
	}
}

int hf_isempty()
{
	for(int i=1;i<10;i++)
	{
		if(studio[i]!=NULL) return 0; 
	}
	
	return 1;
}

bool hf_val_op(hf_node a,hf_node b)
{
	return a.val<b.val;
} 


int main()
{
	hf_node* tmp_hf_l;
	hf_node* tmp_hf_r;
	
	
	

	char char_tmp;
	while(cin>>char_tmp&&char_tmp!=';')
	{
		the_one.insert(char_tmp);
		multiset_all_char.insert(char_tmp);
	}
	
	set<char>::iterator set_pos;
	multiset<char>::iterator multiset_pos;
	
	int i=1;
	//init the all hf node vector
	//ignore the 
	for(set_pos=the_one.begin();set_pos!=the_one.end();set_pos++,i++)
	{
		studio[i]=add_hf_node(*set_pos,multiset_all_char.count(*set_pos));
		//studio[i].ch=*set_pos;
		//studio[i].val=multiset_all_char.count(*set_pos);
	}
	
	while(hf_isempty())
	{
		tmp_hf_l=find_least_one();
		tmp_hf_r=find_least_one();
		root.val=tmp_hf_l->val+tmp_hf_r->val;
		root.left=tmp_hf_l;
		root.right=tmp_hf_r;
		
		in_studio(root)
	}
	
	
	
	
	
	

	
	return 0;
} 
