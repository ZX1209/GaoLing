#include<stdio.h>
#include<time.h>
//need one argument: filename  or it just input the (null)
int main(int argc,char* argv[])
{
    char*wday[]={"Sun","Mon","Tue","Wed","Thu","Tri","Sat"};
    time_t timep;
    struct tm* p;
    time(&timep);
    p=localtime(&timep);


    printf("/****************************************\n");
    printf("*Filename:%s\n",argv[1]);
    printf("*CreateTime:%d/%d/%d ",(1900+p->tm_year),(1+p->tm_mon),(p->tm_mday));
    printf("%s %d:%d:%d\n",wday[p->tm_wday],p->tm_hour,p->tm_min,p->tm_sec);
    printf("*CreateBy:GaoLing\n*Email:zxgaoling@gamil.com/1404919041@qq.com\n");
    printf("*CopyRight:whatever\n");


    printf("****************************************/\n");

    printf("\n\n#include <iostream>\nusing namespace std;\n\n\n");
    printf("int main()\n{\n\n  return 0;\n}");
    
    return 0;
}
