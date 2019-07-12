#include "header.h"
#include <stdio.h>


extern Room rooms[4][10];
void initial_rooms(){
    int i,j;
    FILE *f;
    if((f=fopen("config.dat","rb"))==NULL){
        printf("文件打开失败。\n");
        exit(0);
    }
    for(i=0;i<4;i++){
        for(j=0;j<10;j++)
        {
            fread(&rooms[i][j],sizeof(Room),1,f);
        }
        putchar(10);
    }
    fclose(f);
}


void getrooms(){
    int i,j;
    char con;
    FILE *f;
    if((f=fopen("config.dat","rb"))==NULL)
    {
        printf("文件打开失败\n");
        exit(0);
    }
    system("cls");
    printf("-----------------------------------酒店当前全部房间信息-----------------------------------\n");
    for(i=0;i<4;i++){
        for(j=0;j<10;j++)
        {
            fread(&rooms[i][j],sizeof(Room),1,f);
            printf("编号：%-5d类型：%-5d价格1：%-5d:价格2：%-5d入住方式：%-5d房间情况：%-5d入住人姓名：%-10s入住人身份证:%-10s性别:%-5s年龄:%-5d入住时间：%-5d\n\n附加服务次数：  健身房: %-5d电视付费频道: %-5dSPA: %-5d\n\n-----------------------------------\n",rooms[i][j].num,rooms[i][j].level,rooms[i][j].price1,rooms[i][j].price2,rooms[i][j].WoU,rooms[i][j].condition,rooms[i][j].name,rooms[i][j].ID,rooms[i][j].sex,rooms[i][j].age,rooms[i][j].time,rooms[i][j].addcount1,rooms[i][j].addcount2,rooms[i][j].addcount3);
         }
        putchar(10);
    }
    fclose(f);
    printf("按任意键继续!\n");
    con = getch();
}


void write_in(){
    FILE *f;
    int i,j;
    if((f = fopen("config.dat","wb"))==NULL){
        printf("二进制文本打开失败\n");
        exit(0);
    }
    for(i=0; i<4; i++){
        for(j=0; j<10; j++)  {
 //printf("%-5d %-5d %-5d %-5d %-5d %-5d\n",rooms[i][j].num,rooms[i][j].level,rooms[i][j].price1,rooms[i][j].price2,rooms[i][j].condition,rooms[i][j].time);
            if(fwrite(&rooms[i][j],sizeof(Room),1,f)!=1)
            {
                printf("信息录入失败");
                exit(0);
            }
        }
    }
    fclose(f);
}


int Is_In_Arr(int *arr,int len, int num){
    int i;
    for(i=0; i<len; i++){
        if(num == *(arr+i)) return 1;
    }
    return 0;
}
