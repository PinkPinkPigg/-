#include <stdio.h>
#include <string.h>
#include "header.h"
extern Room rooms[4][10];
operatedata userdata;
extern char *wday[] ;
extern struct tt * p;
static void IfBack(int op)
{
    int opera;
    printf("�����Ǽ��밴0�������������밴1\n");
    scanf("%d",&opera);
    while(!(opera==1 || opera==0))
    {
        printf("��������ȷ������\n");
        scanf("%d",&opera);
    }
    switch(opera){
    case 0: check_in(); break;
    case 1: welcome();  break;
    }
/*
    switch(op){
    case 1:{
        printf("�����밴0�������������밴2\n");
        scanf("%d",&opera);
        getchar();
        while(opera!=2 || opera!=0 ){
            printf("��������ȷ��ָ��.\n");
            scanf("%d",&opera);
            getchar();
        }
        if(opera == 2){
            welcome();
        }else break;
    }1.�Ƶ��� 2.����ȼ� 3.����۸� 4.ס������ 5.ס������ 6.ס���Ա� 7.���ӷ������ 8.�ܷ��� 9.���ⷽʽ 10.Ԥ����סʱ��  11.
    case 2:{
        printf("�����밴0�������밴1�������������밴2\n");
        scanf("%d",&opera);
        getchar();
        while(opera!=2 || opera!=0 ){
            printf("��������ȷ��ָ��.\n");
            scanf("%d",&opera);
            getchar();
        }
        if(opera == 2){
            welcome();
        }else break;

    }
    }
*/
}

//���������ֱ���ѡ���͡������ź���ס��ʽ
int static select_type(){
    int type;
    system("cls");
    printf("***********************************\n");
    printf("*---------------------------------*\n");
    printf("*|                               |*\n");
    printf("*|            ��������           |*\n");
    printf("*|                               |*\n");
    printf("*|          1.��׼���˷�         |*\n");
    printf("*|          2.��׼˫�˷�         |*\n");
    printf("*|          3.�󴲷�             |*\n");
    printf("*|          4.������             |*\n");
    printf("*|                               |*\n");
    printf("*|                               |*\n");
    printf("*---------------------------------*\n");
    printf("***********************************\n");
    printf("��ѡ�񷿼����ͣ�1~4����\n");
    scanf("%d",&type);
    getchar();
    while(type<1 || type>4)
    {
        printf("��������ȷ����ֵ(1-4)��\n");
        scanf("%d",&type);
        getchar();
    }
    return type;
}

 static int select_num(int level){
    int num,i;
    int available[10];
    printf("Ŀǰ����ס�ķ��䣺");
    for(i = 0; i<10; i++){
        if(rooms[level-1][i].condition == 1)    continue;
        else{
            printf("%-5d",rooms[level-1][i].num);
            available[i] = rooms[level-1][i].num;
        }
    }
    putchar(10);
    printf("��ѡ�񷿼�ţ�");
    scanf("%d",&num);
    getchar();
    while(!Is_In_Arr(available,10,num)){
        printf("��ѡ����ȷ�ķ���ţ�");
        scanf("%d",&num);
        getchar();
    }
    return num;
}

int static select_way(){
    int way;
    printf("��ѡ����ס��ʽ: 1.���ⷿ  2.�ӵ㷿\n");
    scanf("%d",&way);
    getchar();
    while(!(way == 1 || way == 2)){
        printf("��������ȷ����ֵ(1-2)��\n");
        scanf("%d",&way);
        getchar();
    }
    return way;
}

//�����Ƿ��˷���ȷ��
static void confirm(int num){
    int op,i,j;
    i = num/100-1;
    j = num-(i+1)*100-1;
    printf("%d�ŷ��䣬�Ƿ�ȷ����ס�� ȷ���밴1�����µǼ��밴2���������˵��밴0��\n",num,rooms[i][j].name);
    scanf("%d",&op);
    getchar();
    while(op>2 || op<0)
    {
        printf("��������ȷ���֡�\n");
        scanf("%d",&op);
        getchar();
    }
    if(op==2)
    {
        check_in();
    }
    else if(op == 0)
    {
        welcome();
    }
    else
    {
        userdata.roomnumber=num;
    }
}
//����Ϣ��¼��ϵͳ
void static input(int type, int num, int way)
{
    char name[20];
    char sex[10];
    char ID[20];
    int age,vipnumber,number;
    unsigned int time;
    int i,j;
    FILE *fp;
    FILE *invip;
    people *head,*change;
    printf("��������ס��������");
    scanf("%s",name);
    number=fopen("number.txt","r");
    fscanf(number,"%d",&vipnumber);
    fclose(number);
    head=VipList();
    change=head;
    fp=fopen("vip.txt","w");
    change=head;
    for(i=0;i<vipnumber;i++)
    {
        if(strcmp(name,head->name)==0)
        {
            printf("���û�ΪVIP�û���ÿ����ס��������VIP�������˴ε���ס��������2�֡�\n");
            head->vip+=2;
            break;
        }
        else
        {
            head=head->next;
        }
    }
    if(i==vipnumber)
    {
        printf("���û�������vip�û����Ƶ��ṩvipע�Ṧ�ܡ�\n");
    }
    for(j=0;j<vipnumber;j++)
    {
        fprintf(fp,"%s %s %d\n",change->ID,change->name,change->vip);
        change=change->next;
    }
    fclose(fp);
    //vipsearch(name);
    stpcpy(userdata.user,name);
    printf("������ס�����֤��:");
    scanf("%s",ID);
    stpcpy(userdata.ID,ID);
    printf("������ס���Ա�:");
    scanf("%s",sex);
    stpcpy(userdata.sex,sex);
    printf("������ס������:");
    scanf("%d",&age);
    userdata.age=age;
    //userdata.user=name;<-
    printf("��������סʱ��(��λ����/Сʱ)��\n");
    scanf("%d",&time);
    userdata.time=time;
    getchar();
    strcpy(rooms[type-1][num-1-100*type].name,name);
    strcpy(rooms[type-1][num-1-100*type].sex,sex);
    strcpy(rooms[type-1][num-1-100*type].ID,ID);
    rooms[type-1][num-1-100*type].age = age;
    rooms[type-1][num-1-100*type].time = time;
    rooms[type-1][num-1-100*type].WoU = way;
    rooms[type-1][num-1-100*type].condition = 1;
    write_in();
}
void check_in(){
    int type,num,way,opera;
    FILE *fp;
    type = select_type();//��ѡ��������
    num = select_num(type);//��ѡ�����
    way = select_way();//��ס��ʽ
    confirm(num);
    input(type,num,way);
    //userdata.roomnumber=num;
    //fp=fopen("B:\\my codeQWQ\\Debug\\My_Hotel 7.9 16.18\\OperateData.txt","w");
    Timeget();
    if((fp=fopen("OperateData.txt","a"))==NULL)
    {
        printf("�ļ���ʧ��\n");
        exit(0);
    }
    fprintf(fp,"%d��%d��%d��\t���%s\t%dʱ:%d��:%d��\tס��:%s,����:%d,%s�Ǽ���ס%d����,Ԥ����ס:%d��/ʱ,���֤��Ϊ:%s��\n",(p->tm_year),(p->tm_mon), p->tm_mday,wday[p->tm_wday], p->tm_hour, p->tm_min, p->tm_sec,userdata.user,userdata.age,userdata.sex,userdata.roomnumber,userdata.time,userdata.ID);//�޷�д���ļ�
    fclose(fp);
    IfBack(4);
}
