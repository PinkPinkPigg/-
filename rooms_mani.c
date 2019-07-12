#include "header.h"
#include <stdio.h>


extern Room rooms[4][10];
void initial_rooms(){
    int i,j;
    FILE *f;
    if((f=fopen("config.dat","rb"))==NULL){
        printf("�ļ���ʧ�ܡ�\n");
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
        printf("�ļ���ʧ��\n");
        exit(0);
    }
    system("cls");
    printf("-----------------------------------�Ƶ굱ǰȫ��������Ϣ-----------------------------------\n");
    for(i=0;i<4;i++){
        for(j=0;j<10;j++)
        {
            fread(&rooms[i][j],sizeof(Room),1,f);
            printf("��ţ�%-5d���ͣ�%-5d�۸�1��%-5d:�۸�2��%-5d��ס��ʽ��%-5d���������%-5d��ס��������%-10s��ס�����֤:%-10s�Ա�:%-5s����:%-5d��סʱ�䣺%-5d\n\n���ӷ��������  ����: %-5d���Ӹ���Ƶ��: %-5dSPA: %-5d\n\n-----------------------------------\n",rooms[i][j].num,rooms[i][j].level,rooms[i][j].price1,rooms[i][j].price2,rooms[i][j].WoU,rooms[i][j].condition,rooms[i][j].name,rooms[i][j].ID,rooms[i][j].sex,rooms[i][j].age,rooms[i][j].time,rooms[i][j].addcount1,rooms[i][j].addcount2,rooms[i][j].addcount3);
         }
        putchar(10);
    }
    fclose(f);
    printf("�����������!\n");
    con = getch();
}


void write_in(){
    FILE *f;
    int i,j;
    if((f = fopen("config.dat","wb"))==NULL){
        printf("�������ı���ʧ��\n");
        exit(0);
    }
    for(i=0; i<4; i++){
        for(j=0; j<10; j++)  {
 //printf("%-5d %-5d %-5d %-5d %-5d %-5d\n",rooms[i][j].num,rooms[i][j].level,rooms[i][j].price1,rooms[i][j].price2,rooms[i][j].condition,rooms[i][j].time);
            if(fwrite(&rooms[i][j],sizeof(Room),1,f)!=1)
            {
                printf("��Ϣ¼��ʧ��");
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
