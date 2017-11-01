#include<stdio.h>
#include<stdlib.h>

int main()
{
  FILE * explore;
  explore=fopen("explore.txt","a+");

  rewind(explore);
  fprintf(explore,"\nou ou ou ou");

  fclose(explore);

  return 0;
}
