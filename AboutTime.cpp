#include<stdio.h> 
#include<time.h>
#include<stdlib.h>

time_t start_time;
time_t end_time;

char * start_time_str;
char * end_time_str;

clock_t clock_start_time;
clock_t clock_end_time; 

int random_value;


int main()
{
	//start time(s) and time(str) also clock time(ci?) 
	 start_time = time(NULL);
	 start_time_str=asctime(gmtime(&start_time));
	 clock_start_time=clock();
	 
	 //random value
	 srand(time(NULL));
	 random_value=rand();
	 
	 //write something
	 for(int i=0;i<9999;i++)
	 {
	 	for(int k=0;k<9999;k++)
	 	{
			  for(int j=0;j<9;j++);
	 	}
	 	
	 }
	 
	 
	 //App1();
	
	 
	 
	//end time(s) and time(str) also clock time(ci?) 
	 end_time = time(NULL); 
	 end_time_str=asctime(gmtime(&start_time));
	 clock_end_time=clock();
	 
	 //convert cpu time to (ms)
	 double cpu_time_used=1000.0*(clock_end_time-clock_start_time)/CLOCKS_PER_SEC;
	
	
	printf("%s\n%s",start_time_str,end_time_str);
	
	//printf("%ld\n%ld",start_time,end_time);
	
	printf("\ntime_used:%lfs",difftime(end_time,start_time));
	
	//printf("\n\n%lf\n%lf",clock_start_time,clock_end_time);
	printf("\ncpu_time_used:%f ms",cpu_time_used);
	
	
	system("dir");
	return 0;
}
