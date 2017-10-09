#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>



int iseven(long N)
{
  return 1-N%2;
}



int main()
{
  setbuf(stdout,NULL);
  long temp=0;
  while(1)
  {
    sleep(1);
    srand(time(NULL));
    temp = rand();

    if (iseven(temp))
    {
      printf("\033[30;41m");
    }
    else 
    {
    printf("\033[30;42m");
    }


    printf("%ld",temp);
    printf("\033[0m ");


  }





  return 0;
}
