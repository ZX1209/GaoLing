#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define XMAX 100
#define YMAX 100

void print();
void waitit();


int main()
{
  setbuf(stdout,NULL);
  while (1)
  {
    print();
    usleep(500); 



  }
  return 0;
}


void print()
{
  if(rand()%3)
    printf("|");
  else 
    printf("__");
}


void waitit()
{
  for (int i = 0; i < 999999; i++);
}
