/****************************************
*Filename:tree.pp
*CreateTime:2017/10/4 Wed 19:59:11
*CreateBy:GaoLing
*Email:zxgaoling@gamil.com/1404919041@qq.com
*CopyRight:whatever
****************************************/


#include "tree_header.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>

#define NULLe(x,y) if((x)==NULL)perror(y);

using namespace std;






struct treenode
{
  int element;
  treenode* left;
  treenode* right;

};

typedef treenode* ptot;

void treeadd(ptot *T,int X)
{
  if (*T==NULL)
  {
    *T=createtreenode(X);
  }
  else if ((*T)->element>X) 
  {
    treeadd(&((*T)->left),X);

  }
  else 
  {
    treeadd(&((*T)->right),X);
  }

}


ptot treenodeadd(ptot T,int X)
{
  if (T==NULL) 
  {
    return createtreenode(X);
  }
  else if (T) {
    
  }
}

//////////////////////////
//malloc a treenode space 
//and init element default is 0
/////////////////////////
ptot createtreenode(int X=0)
{
  ptot temp;
  temp = (ptot)malloc(sizeof(treenode));
  NULLe(temp,"createtreenode");

  temp->element=X;
  return temp;

}


int showtree(ptot T)
{
  if (T==NULL)
  {
    printf("end\n");
    return 0;
  }

  printf("%d\n",T->element);

  showtree(T->left);
  showtree(T->right);

  return 0;

  
}


SearchTree MakeEmpty(SearchTree T)
{
  if (T!=NULL) 
  {
    MakeEmpty(T->left);
    MakeEmpty(T->right);
    free(T);
  }
  return NULL;
}

Position Find(ElementType X,SearchTree T)
{
  if (T==NULL) return NULL;

  if (X<T->element) return Find(X,T->left);
  else if(X>T->element) return Find(X,T->right);
  else return T;
}

Position FindMin(SearchTree T)
{
  if (T==NULL) 
  {
    return NULL;
  }
  else if (T->left==NULL)
  {
    return T;
  } else 
  {
    return FindMin(T->left);
  }
}

Position FindMax(SearchTree T)
{
  if(T!=NULL)
  {
    while (T->right!=NULL)
    {
      T=T->right;
    }
  }

  return T;
}

SearchTree Insert(ElementType X,SearchTree T)
{
  if (T==NULL)
  {
    T=(Position)malloc(sizeof(struct TreeNode));
    if (T==NULL) 
    {
      perror("insert\n");
    }
    else 
    {
      T->element=X;
      T->left=T->right=NULL;
    }
  }
  else if (X<T->element) 
  {
    T->left=Insert(X,T->left);
  } 
  else if(X>=T->element)
  {
    T->right=Insert(X,T->right);
  }
  

  return T;
}

SearchTree Delete(ElementType X, SearchTree T)
{
  Position TempCell;

  if (T==NULL)
  {
    perror("Delete\n");
  }
  else if(X<T->element)
  {
    T->left=Delete(X,T->left);
  }
  else if(X>T->element)
  {
    T->right=Delete(X,T->right);
  }
  else if(T->left&&T->right)
  {
    TempCell=FindMin(T->right);
    T->element = TempCell->element;
    T->right= Delete(T->element,T->right);
  }
  else 
  {
    TempCell=T;
    if (T->left==NULL)
    {
      T=T->right;
    }
    else if(T->right==NULL)
    {
      T=T->left;
    }
    free(TempCell);
    
  }

  return T;


}

int ShowTree(SearchTree T,int D=0)
{
  if (T==NULL) 
  {
    return 0;

  }
  else 
  {
    for (int i = 0; i < D; i++) 
    {
      printf("\t|");
    }
    printf("%d----~\n",T->element);
  }

  ShowTree(T->left,D+1);
  ShowTree(T->right,D+1);

  return 0;
}

SearchTree CreateTree(ElementType X)
{
  SearchTree Temp;
  Temp=(SearchTree)malloc(sizeof(TreeNode));
  NULLe(Temp,"CreateTree");


  Temp->element=X;
  Temp->left=Temp->right=NULL;
  return Temp;
}


int main(void)
{
  SearchTree explore = CreateTree(50);
  srand(1);
  for (int i = 0; i < 100; i++) 
  {
    Insert(rand()%100,explore);
  }

  ShowTree(explore);

  MakeEmpty(explore);
  

  return 0;
}
