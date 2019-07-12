#include <stdio.h>
#include <time.h>
#include<stdlib.h>
#include"header.h"


char *wday[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
struct tt * p;
void Timeget()//得到时间放入时间结构体tt；
{
    time_t timep;
    time(&timep);
    p = gmtime(&timep);
    p->tm_year+=1900;
    p->tm_mon+=1;
    p->tm_hour+=8;

        //printf("%d年%d月%d日\t", (1900+p->tm_year), (1+p->tm_mon), p->tm_mday);
        //printf("礼拜%s\t%d时:%d分:%d秒\n", wday[p->tm_wday], p->tm_hour+8, p->tm_min, p->tm_sec);
        //Sleep(50);
    }

void TimePrintf()
{
    char choice;
    while(1)
    {
        system("cls");
        Timeget();
        printf("目前时间为:");
        printf("%d年%d月%d日  ", (p->tm_year), (p->tm_mon), p->tm_mday);
        printf("礼拜%s\t%d时:%d分:%d秒\n", wday[p->tm_wday], p->tm_hour, p->tm_min, p->tm_sec);
        //Sleep(50);
    }
}

