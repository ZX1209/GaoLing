#include<iostream>
#include<list>

using namespace std;


list<int> list_weigths;
int pay=0;

list<int>::iterator Find_least()
{
	int int_min_tmp_val;
	int gatherweither=0;
	list<int>::iterator list_tmp_pos;
	list<int>::iterator list_min_pos;
	for(list_min_pos=list_tmp_pos=(++list_weigths.begin()),int_min_tmp_val=gatherweither=*list_tmp_pos+*(--list_tmp_pos),++list_tmp_pos;list_tmp_pos!=list_weigths.end();list_tmp_pos++)
	{
		gatherweither=*list_tmp_pos+*(--list_tmp_pos);
		list_tmp_pos++;
		if(int_min_tmp_val>gatherweither)
		{
			int_min_tmp_val=gatherweither;
			
			list_min_pos=list_tmp_pos;
		}
		
	}
	
	return  list_min_pos;
}

void merge(list<int>::iterator pos)
{
	int val;
	val=*(pos)+*(--pos);
	pay+=val;
	list_weigths.insert(pos,val);
	list_weigths.erase(pos++);
	list_weigths.erase(pos++);
}


int main()
{
	//////////////////////////////////
	//get the data in a list list_weigths
	///////////////////////////////////
	int n;
	int int_tmp;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>int_tmp;
		list_weigths.push_back(int_tmp);
	}

    ///////////////////////////////////////
    //greedy find the leatest and merge it
    //really i don't know what it will happened!!!!!
	////////////////////////////////////// 
	while(list_weigths.size()>1)
	{
		merge(Find_least());
	}
	
	//////////////////////
	//print the answer
	///////////////////////
	cout<<pay;
	getchar();
	
	return 0;
	
	
}
