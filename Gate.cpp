#include<iostream>
#include<string>
#include<list>
using namespace std;

/////////////////////////////////////
//a Gate
/////////////////////////////////////
class Gate
{
    public:
    Gate(string introudition)
    {
        brief=introudition;
        Gstate=0;
        total++;
    }
    string show_brief()
    {
        return brief;
    }
    void pass()
    {
    	Gstate=1;
    }
    string brief;
    static int total;
    int Gstate;
    
    private: 

};


class Big_Gate:public Gate
{
    public:
    Big_Gate(string introudition,string details):Gate(introudition) 
    {
    

        detail=details;


    }

    string detail;

}; 


class ReWard
{
	public:
		ReWard(string in)
		{
			reward=in;
			Rstate=0;
		}
		
		void finished()
		{
			Rstate=1;
		}
		
	string  reward;
	int Rstate;
	
};



/*
class Project
{
	public:
		Project(string little,string big)
		{
			
			
		}
		
		
	list<Gate> head;
	Big_Gate Boss;
	
	
	
	
};

*/

int Gate::total=0;



class ReWard_Gate:public Gate,public ReWard
{
	public:
		ReWard_Gate(string gatebrief,string rewardbrief):Gate::Gate(gatebrief),ReWard::ReWard(rewardbrief)
		{
			
			cout<<"finished"<<endl;
			
		} 
		
		string getgate()
		{
			return brief;
		}
		
		string getreward()
		{
			return reward;
		} 
	 
	
};


int main()
{
    Big_Gate explore("explore","this is a explore in the coop world");
    cout<<explore.total<<endl;


    cout<<explore.brief<<endl;
    cout<<explore.detail<<endl;
    
    
    ReWard_Gate exploreagain("pass the test","get the reward");
    cout<<exploreagain.getgate()<<endl;
    cout<<exploreagain.getreward()<<endl;
    
    


    return 0;
}
