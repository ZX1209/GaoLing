#ifndef _HEADER_H_
#define _HEADER_H_
  //std header file
  #include <stdio.h>
  #include <stdlib.h>
  #include <iostream>



  //marco define
  #define TYPE int
  



  //typedefine

  typedef struct Node* list;





  //function define
  void Swap(TYPE *a, TYPE *b);
  void ListInit(list header);
  void ListAdd(list );
  list ListFind(TYPE X, list L);
  int IsLast(list L);




  //struct
  struct Node
  {
    TYPE element;
    Node* next;
  };



#endif
