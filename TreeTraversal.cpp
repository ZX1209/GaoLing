/****************************************
*Filename:TreeTraversal.cpp
*CreateTime:2017/10/21 Sat 21:51:10
*CreateBy:GaoLing
*Email:zxgaoling@gamil.com/1404919041@qq.com
*CopyRight:whatever
****************************************/


#include <iostream>
using namespace std;

//for convient
int Tree[17][2]={{0,0}};

void InorderTraversal(int i)
{
  if (Tree[i][0]==Tree[i][1]) {
    if (i!=0) cout<<i<<" ";
  }
  else {
    InorderTraversal(Tree[i][0]);
    cout<<i<<" ";
    InorderTraversal(Tree[i][1]);
  }


}

void PreorderTraversal(int i)
{
  if (Tree[i][0]==Tree[i][1]) {
     if (i!=0) cout<<i<<" "; 
  }
  else {
    cout<<i<<" "; 
    PreorderTraversal(Tree[i][0]);
    PreorderTraversal(Tree[i][1]);
  }

}

void PostorderTraversal(int i)
{
  if (Tree[i][0]==Tree[i][1]) {
     if (i!=0) cout<<i<<" "; 
  }
  else {
    PostorderTraversal(Tree[i][0]);
    PostorderTraversal(Tree[i][1]);
    cout<<i<<" "; 

  }
 

}

int main()
{
  //Tree start from 0 to 15 
  //i need to c

  int n;
  cin>>n;
  for (int i = 1; i <=n; i++) {
    cin>>Tree[i][0]>>Tree[i][1];
  }

  PreorderTraversal(1);cout<<endl;
  InorderTraversal(1);cout<<endl;
  PostorderTraversal(1);cout<<endl;


  return 0;
}
