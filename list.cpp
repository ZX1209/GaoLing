/****************************************
*Filename:list.c
*CreateTime:2017/10/2 Mon 15:41:3
*CreateBy:GaoLing
*Email:zxgaoling@gamil.com/1404919041@qq.com
*CopyRight:whatever
****************************************/


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

union all
{
  int i;
  long l;
  float f;
  double d;
  char c;
};

struct allnode
{
  union all super;
  struct allnode* next;
};

struct node
{
  int element;
  struct node* next;
};

typedef struct node* list;

////////////////////
//create a node whit X and 
//put it after the P 
////////////////////
int insert(list P, int X)
{
  list temp = (list)malloc(sizeof(struct node));
  if (temp==NULL)
  {
    perror("malloc");
    return -1;
  }

  temp->element=X;
  temp->next=P->next;
  P->next=temp;
  return 1;

}

///////////////////
//init a header with 
//666 and NULL
//////////////////
list init(int X=666)
{
  list temp = (list)malloc(sizeof(struct node));
  if (temp==NULL) 
  {
    perror("malloc");
  }


  temp->element=X;
  temp->next=NULL;
  return temp;
}

/////////////////////////////////
//find from P(ignore P->element)
//return where X is or NUll for wrong
////////////////////////////
list find(list P, int X)
{
  list temp = P->next;
  while(temp!=NULL)
  {
    if (temp->element==X) 
    {
      return temp;
      
    }
    temp=temp->next;
  }
  return NULL;

}

///////////////////
//delete list from L
//end until UNLL is
///////////////////
void deletelist(list L)
{
  list temp;
  temp=L->next;
  while(temp!=NULL)
  {
      free(L);
      L=temp;
      temp=temp->next;
  }
  free(L);
}

//////////////////////
//just show list from L to NULL
///////////////////////////
void showlist(list L)
{
  while(L!=NULL)
  {
    printf("%d->",L->element);
    L=L->next;
  }
  printf("NULL;");
}

int storelist(list L)
{
  FILE* fd;
  fd = fopen("liststoretest.txt","a");
  if(fd==NULL)
  {
    perror("fopen file name\n");
    return -1;
  }

  while(L!=NULL)
  {
    fprintf(fd,"%d ",L->element);
    L=L->next;
  }
  printf("list stored!\n");

  fclose(fd);
  return 1;
  
}

int readlist(list L,const char* path="liststoretest.txt") 
{ 
  FILE* fd;
  int tempelement;
  fd = fopen(path,"r");
  if(fd==NULL)
  {
    perror("fopen path\n");
    return -1;
  }

  while (!feof(fd)) 
  {
    fscanf(fd,"%d ",&tempelement);
    insert(L,tempelement);

  }


  ////////////////
  //do close it !!
  /////////////////
  fclose(fd);
  return 1;
  



}


int main(void)
{
  list header;
  header=init();
  for(int i=0;i<100;i++)
  {
   insert(header,i);
  }

  showlist(header);
  storelist(header);
  deletelist(header);
  header=init(0);
  readlist(header);
  printf("\n\n\n");
  showlist(header);
  int test=remove("liststoretest.txt");
  if (test==-1) 
  {
    perror("remove\n");
  }


  

  return 0;
}
