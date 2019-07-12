#include "header.h"
#include <stdio.h>
#include <string.h>
operatedata userdata;
extern char *wday[] ;
extern struct tt * p;
extern Room rooms[4][10];
static void query();
static void revise();
FILE *opdata;
static void additional_survise(){
    int op,i,j,Found=0,add;
    char con;
    printf("���������ӷ���ķ���ţ����߰�1���أ�\n");
    scanf("%d",&op);
    if (op==1)   management();
    for (i=0;i<4;i++){
        for (j=0;j<10;j++){
            if(op==rooms[i][j].num){
                if(!rooms[i][j].condition){
                    printf("�˷������˾�ס�������º˶ԣ�����������ء�\n");
                    Found=1;
                    con = getch();
                    management;
                }
                else{
                    system("cls");
                    printf("*******************************************\n");
                    printf("*-----------------------------------------*\n");
                    printf("*|                                       |*\n");
                    printf("*|                                       |*\n");
                    printf("*|            1->���� 70/��            |*\n");
                    printf("*|            2->���Ӹ���Ƶ�� 15/��      |*\n");
                    printf("*|            3->SPA 120/��              |*\n");
                    printf("*|            4->������һ���˵�          |*\n");
                    printf("*|                                       |*\n");
                    printf("*|                                       |*\n");
                    printf("*-----------------------------------------*\n");
                    printf("*******************************************\n");
                    printf("��ѡ�񸽼ӷ���(1~3)����4������һ���˵�:\n");
                    scanf("%d",&add);
                    while(!(add==1 || add==2 || add==3 || add==4)){
                        printf("��������ȷ�����֡�\n");
                        scanf("%d",&add);
                    }
                    switch(add){
                    case 1:rooms[i][j].addcount1+=1; break;
                    case 2:rooms[i][j].addcount2+=1; break;
                    case 3:rooms[i][j].addcount3+=1; break;
                    case 4:management(); break;
                    }
                    printf("��ӳɹ���\n");
                    Timeget();
                    opdata=fopen("OperateData.txt","a");
                    fprintf(opdata,"%d��%d��%d��\t���%s\t%dʱ:%d��:%d��\tס��:%s,����:%d,�Ա�:%s,���֤��Ϊ:%s�ڷ���%dѡ���˸��ӷ���:%d\n",(p->tm_year),(p->tm_mon), p->tm_mday,wday[p->tm_wday], p->tm_hour, p->tm_min, p->tm_sec,rooms[i][j].name,rooms[i][j].age,rooms[i][j].sex,rooms[i][j].ID,rooms[i][j].num,add);
                    fclose(opdata);
                    write_in();
                    Found=1;
                }
            }
        }
    }
    if(!Found){
        printf("û��������䣬�밴��������ء�\n");
        con = getch();
        management();
    }
    printf("�밴��������ء�\n");
    con = getch();
    management();
}

//���ݷ����Ž���������������������Ϣ
static void search_by_num(){
    int i,j,num,op,Found=0;
    char con;
    printf("��������ҵķ����ţ����߰�1���أ�\n");
    scanf("%d",&op);
    getchar();
    if(op==1)   query();
    for(i=0; i<4; i++){
        for(j=0; j<10; j++){
            if(op == rooms[i][j].num){
                if(!rooms[i][j].condition){
                    printf("�����ţ�%-5d����״̬��%d\n",rooms[i][j].num,rooms[i][j].condition);
                    Found = 1;
                }
                else{
                    printf("�����ţ�%-5d��ס��������%-10s\n���֤��Ϊ:%-10s��סʱ�䣺%-5d\n",rooms[i][j].num,rooms[i][j].name,rooms[i][j].ID,rooms[i][j].time);
                    Found = 1;
                }
            }
        }
    }
    if(!Found){
        printf("û��������䣬�밴��������ء�\n");
        con = getch();
        query();
    }
    printf("�밴��������ء�\n");
    con = getch();
    query();
}
static void search_by_name(){
    int i,j,op,Found=0;
    char name[20];
    char con;
    printf("������ͻ������������߰�1���أ�\n");
    scanf("%s",name);
    getchar();
    if(op==1)   query();
    for(i=0; i<4; i++){
        for(j=0; j<10; j++){
            if(strcmp(name,rooms[i][j].name)==0){
                printf("�����ţ�%-5d��ס��������%-10s,�Ա�:%-10s,����:%-5d,���֤��:%-10s,��סʱ�䣺%-5d\n",rooms[i][j].num,rooms[i][j].name,rooms[i][j].sex,rooms[i][j].age,rooms[i][j].ID,rooms[i][j].time);
                Found = 1;
            }
        }
    }
    if(!Found){
        printf("û�иÿͻ����밴��������ء�\n");
        con = getch();
        query();
    }
    printf("�밴��������ء�\n");
    con = getch();
    query();

}

//�����޸ķ���ͻ������ĺ�����
static void revise(){
    int i,j,time,op,Found=0;
    char con;
    int age;
    char sex[10];
    char name[20];
    char ID[20];
    printf("��������Ҫ�޸ĵķ����ţ����߰�1���أ�\n");
    scanf("%d",&op);
    getchar();
    if(op==1)   management();
    for(i=0; i<4; i++){
        for(j=0; j<10; j++){
            if(op == rooms[i][j].num){
                if(!rooms[i][j].condition){
                    printf("�����ţ�%-5d����״̬��%d\n",rooms[i][j].num,rooms[i][j].condition);
                    printf("������ͻ���Ϣ���޸ķ���״̬Ϊ����Ԥ����\n");
                    printf("����������:\n");
                    scanf("%s",name);
                    //printf("��������סʱ�䣺\n");
                   // scanf("%d",time);
                    strcpy(rooms[i][j].name,name);
                    printf("���������֤��:\n");
                    scanf("%s",ID);
                    strcpy(rooms[i][j].ID,ID);
                    printf("�������Ա�:\n");
                    scanf("%s",sex);
                    strcpy(rooms[i][j].sex,sex);
                    printf("����������:\n");
                    scanf("%d",&age);
                    rooms[i][j].age=age;
                    printf("�������޸ĺ����סʱ�䣺\n");
                    while(!scanf("%d",&time)){
                        getchar();
                        printf("��������ȷ�����֡�\n");
                    }
                    rooms[i][j].time = time;
                    rooms[i][j].condition = 1;
                    Found = 1;
                    Timeget();
                    opdata=fopen("OperateData.txt","a");
                    fprintf(opdata,"%d��%d��%d��\t���%s\t%dʱ:%d��:%d��\t%d�ŷ�����Ϣ�޸�Ϊ:ס��:%s,�Ա�:%s,����:%d���֤��:%s\n",(p->tm_year),(p->tm_mon), p->tm_mday,wday[p->tm_wday], p->tm_hour, p->tm_min, p->tm_sec,rooms[i][j].num,rooms[i][j].name,rooms[i][j].sex,rooms[i][j].age,rooms[i][j].ID);
                    fclose(opdata);
                    write_in();
                }
                else{
                    printf("�����ţ�%-5d��ס��������%-10s�Ա�:%-10s����:%-5d���֤��:%-10s��סʱ�䣺%-5d\n",rooms[i][j].num,rooms[i][j].name,rooms[i][j].sex,rooms[i][j].age,rooms[i][j].ID,rooms[i][j].time);
                    printf("�����ţ�%-5d����״̬��%d\n",rooms[i][j].num,rooms[i][j].condition);
                    printf("�������޸ĺ�Ŀͻ�������\n");
                    scanf("%s",name);
                    strcpy(rooms[i][j].name,name);
                    printf("�������޸ĺ�Ŀͻ����֤�ţ�\n");
                    scanf("%s",ID);
                    strcpy(rooms[i][j].ID,ID);
                    printf("�������޸ĺ�Ŀͻ����䣺\n");
                    scanf("%d",&age);
                    rooms[i][j].age=age;
                    printf("�������޸ĺ�Ŀͻ��Ա�\n");
                    scanf("%s",sex);
                    strcpy(rooms[i][j].sex,sex);
                    printf("�������޸ĺ����סʱ�䣺\n");
                    while(!scanf("%d",&time)){
                        getchar();
                        printf("��������ȷ�����֡�\n");
                    }
                    rooms[i][j].time = time;
                    Found = 1;
                    Timeget();
                    opdata=fopen("OperateData.txt","a");
                    fprintf(opdata,"%d��%d��%d��\t���%s\t%dʱ:%d��:%d��\t%d�ŷ�����Ϣ�޸�Ϊ:ס��:%s,�Ա�:%s,����:%d\n���֤:%s\n",(p->tm_year),(p->tm_mon), p->tm_mday,wday[p->tm_wday], p->tm_hour, p->tm_min, p->tm_sec,rooms[i][j].num,rooms[i][j].name,rooms[i][j].sex,rooms[i][j].age,rooms[i][j].ID);
                    fclose(opdata);
                    write_in();
                }
            }
        }
    }
    if(!Found){
        printf("û��������䣬�밴��������ء�\n");
        con = getch();
        management();
    }
    printf("�޸ĳɹ����밴��������ء�\n");
    con = getch();
    management();
}


static void del(){
    int i,j,op,Found=0;
    char blank[1] = "";
    char con;
    printf("��������Ҫ����ɾ�������ķ����ţ����߰�1���أ�\n");
    scanf("%d",&op);
    getchar();
    if(op==1)   management();
    for(i=0; i<4; i++){
        for(j=0; j<10; j++){
            if(op == rooms[i][j].num){
                if(!rooms[i][j].condition){
                    printf("�÷���Ŀǰû����ס��Ϣ������ɾ����\n");
                    Found = 1;
                }
                else{
                    printf("�����ţ�%-5d��ס��������%-10s�Ա�:%-10s����:%-5d���֤:%-10s��סʱ�䣺%-5d\n",rooms[i][j].num,rooms[i][j].name,rooms[i][j].sex,rooms[i][j].age,rooms[i][j].ID,rooms[i][j].time);
                    printf("�Ƿ�ɾ����ס��Ϣ��  ��1ȷ�ϣ���0���ء�\n");
                    scanf("%d",&op);
                    while(!(op==1 || op==0)){
                        printf("��������ȷ�����֡�\n");
                        management();
                    }
                    if(op == 1){
                        rooms[i][j].time = 0;
                        strcpy(rooms[i][j].sex,blank);
                        rooms[i][j].age=0;
                        rooms[i][j].condition = 0;
                        rooms[i][j].addcount1 = 0;
                        rooms[i][j].addcount2 = 0;
                        rooms[i][j].addcount3 = 0;
                        strcpy(rooms[i][j].name,blank);
                        strcpy(rooms[i][j].ID,blank);
                        write_in();
                        Timeget();
                        opdata=fopen("OperateData.txt","a");
                        fprintf(opdata,"%d��%d��%d��\t���%s\t%dʱ:%d��:%d��\t%d�ŷ���ס����Ϣ��ɾ��\n",(p->tm_year),(p->tm_mon), p->tm_mday,wday[p->tm_wday], p->tm_hour, p->tm_min, p->tm_sec,rooms[i][j].num);
                        fclose(opdata);
                        printf("ɾ���ɹ���\n");
                    }
                    else    management();
                    Found = 1;
                }
            }
        }
    }
    if(!Found){
        printf("û��������䣬�밴��������ء�\n");
        con = getch();
        management();
    }
    printf("�밴��������ء�\n");
    con = getch();
    management();
}


static void query(){
    int op;
    system("cls");
    printf("*******************************************\n");
    printf("*-----------------------------------------*\n");
    printf("*|                                       |*\n");
    printf("*|                                       |*\n");
    printf("*|         1.��ʾȫ��������Ϣ��          |*\n");
    printf("*|         2.���շ�����������          |*\n");
    printf("*|         3.���տͻ�����������          |*\n");
    printf("*|         4.������һ���˵���            |*\n");
    printf("*|                                       |*\n");
    printf("*|                                       |*\n");
    printf("*-----------------------------------------*\n");
    printf("*******************************************\n");
    scanf("%d",&op);
    getchar();
    while(op>4 || op<1){
        printf("��������ȷ�����֡�\n");
        scanf("%d",&op);
        getchar();
    }
    switch(op){
    case 1:{
        getrooms();
        query();
    }
    case 2: search_by_num();
    case 3: search_by_name();
    case 4: management();
    }
}

void management(){
    int op;
    system("cls");
    printf("***********************************************\n");
    printf("*---------------------------------------------*\n");
    printf("*|                                           |*\n");
    printf("*|                                           |*\n");
    printf("*|               1->ס����Ϣ��ѯ             |*\n");
    printf("*|               2->ס����Ϣ�޸�             |*\n");
    printf("*|               3->ס����Ϣɾ��             |*\n");
    printf("*|               4->�ͷ����ӷ���             |*\n");
    printf("*|               5->�������˵�               |*\n");
    printf("*|                                           |*\n");
    printf("*|                                           |*\n");
    printf("*---------------------------------------------*\n");
    printf("***********************************************\n");
    printf("��ѡ���Ӧ����(1-5)\n");
    scanf("%d",&op);
    getchar();
    while(op<1 || op>5){
        printf("��������ȷ������(1-5)��\n");
        scanf("%d",&op);
        getchar();
    }
    system("cls");  //��������
    switch(op){
    case 1: query();    break;
    case 2: revise();   break;
    case 3: del();  break;
    case 4: additional_survise();  break;
    case 5: welcome();  break;
    }
}
