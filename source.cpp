#include "header.h"


void Swap(TYPE *a, TYPE *b)
{
  TYPE temp = *a;
  *a=*b;
  *b=temp;
};

int IsLast(list L)
{
  return L->next==NULL;
}


//list serious
//find X in L
//if it there return the Node pointer to X(first)
//else return NULL for not found
list ListFind(TYPE X, list L)
{
  list P;

  
  while (L->next!=NULL)
  {
    if (L->element==X) 
    {
      return L;
      
    }
    L=L->next;
  }

  return NULL;
}


