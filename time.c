#include <stdio.h>
#include <time.h>
#include<stdlib.h>
#include"header.h"


char *wday[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
struct tt * p;
void Timeget()//�õ�ʱ�����ʱ��ṹ��tt��
{
    time_t timep;
    time(&timep);
    p = gmtime(&timep);
    p->tm_year+=1900;
    p->tm_mon+=1;
    p->tm_hour+=8;

        //printf("%d��%d��%d��\t", (1900+p->tm_year), (1+p->tm_mon), p->tm_mday);
        //printf("���%s\t%dʱ:%d��:%d��\n", wday[p->tm_wday], p->tm_hour+8, p->tm_min, p->tm_sec);
        //Sleep(50);
    }

void TimePrintf()
{
    char choice;
    while(1)
    {
        system("cls");
        Timeget();
        printf("Ŀǰʱ��Ϊ:");
        printf("%d��%d��%d��  ", (p->tm_year), (p->tm_mon), p->tm_mday);
        printf("���%s\t%dʱ:%d��:%d��\n", wday[p->tm_wday], p->tm_hour, p->tm_min, p->tm_sec);
        //Sleep(50);
    }
}

