#include "header.h"
#include <stdio.h>
#include<string.h>
#define N 6
operatedata userdata;
extern char *wday[] ;
extern struct tt * p;
FILE *number;
int vipnumber=N;
people * VipList()
{
    FILE *fp;
    int i;
    if((fp=fopen("vip.txt","r"))==NULL)
    {
        printf("�ļ���ʧ��\n");
        exit(0);
    }
    people * head,*node,*tail;
    head=(people *)malloc(sizeof(people));
    tail=head;
    number=fopen("number.txt","r");
    fscanf(number,"%d",&vipnumber);
    fclose(number);
    for(i=0;i<vipnumber;i++)
    {
        node=(people *)malloc(sizeof(people));
        fscanf(fp,"%s %s %d",node->ID,node->name,&node->vip);
        tail->next=node;
        tail=node;
    }
    tail->next=NULL;
    head=head->next;
    fclose(fp);
    return head;
}
void Find()
{
    FILE *fp;
    FILE *invip;
    int i,j;
    int choice;
    char choice2;
    char temp;
    char target[20];
    people *head,*change;
    head=VipList();
    fp=fopen("vip.txt","w");
    change=head;
    printf("�������Ա���������֤������в�ѯ:\n");
    scanf("%s",target);
    number=fopen("number.txt","r");
    fscanf(number,"%d",&vipnumber);
    fclose(number);
    for(i=0;i<vipnumber;i++)
    {
        if(strcmp(target,head->name)==0||strcmp(target,head->ID)==0)
        {
            printf("��Ա��Ϣ��\n");
            printf("����:");
            printf("%s\n",head->name);
            stpcpy(userdata.user,head->name);
            printf("���֤��:");
            printf("%s\n",head->ID);
            stpcpy(userdata.ID,head->ID);
            printf("vip����:");
            printf("%d\n",head->vip);
            if(head->vip>=5)
            {
                printf("�û�Ա���ֿɻ�ȡ��Ʒ���Ƿ�Ҫͨ����Ա���ֻ�ȡ��Ʒ?(1 OR 0) 1�һ���0�˳�\n");
                scanf("%d",&choice);
                while(!(choice==1 || choice==0))
                {
                    printf("��ѡ����ȷѡ��:\n");
                    scanf("%d",&choice);
                }
                if(choice==1)
                {
                    system("cls");
                    printf("***********************************************\n");
                    printf("*---------------------------------------------*\n");
                    printf("*|                                           |*\n");
                    printf("*|                   ��Ʒ                    |*\n");
                    printf("*|                                           |*\n");
                    printf("*|             1.����ȯ80Ԫ  5��             |*\n");
                    printf("*|             2.��or��or���ȯ 2��          |*\n");
                    printf("*|             3.�����Ƶ�������  2��       |*\n");
                    printf("*|             4.����Ʒ���  1��             |*\n");
                    printf("*|             5.������һ���˵�              |*\n");
                    printf("*|                                           |*\n");
                    printf("*|                                           |*\n");
                    printf("*---------------------------------------------*\n");
                    printf("***********************************************\n");
                    printf("��������Ҫ�һ�����Ʒ����:(1-4)\n");
                    scanf("%d",&choice);
                    while(!(choice==1 || choice==2|| choice==3|| choice==4))
                    {
                        printf("��ѡ����ȷѡ��:\n");
                        scanf("%d",&choice);
                    }
                    // /*
                    userdata.vipchoice=choice;
                    switch(choice)
                    {
                        case 1:
                            printf("��ϲ���ѳɹ��һ�:����ȯ80Ԫ\n");
                            head->vip-=5;
                            userdata.vippoint=head->vip;
                            break;
                        case 2:
                            printf("��ϲ���ѳɹ��һ�:��or��or���ȯ\n");
                            head->vip-=2;
                            userdata.vippoint=head->vip;
                            break;
                        case 3:
                            printf("��ϲ���ѳɹ��һ�:�����Ƶ�������\n");
                            head->vip-=2;
                            userdata.vippoint=head->vip;
                            break;
                        case 4:
                            printf("��ϲ���ѳɹ��һ�:����Ʒ���\n");
                            head->vip-=1;
                            userdata.vippoint=head->vip;
                            break;
                    }
                    Timeget();
                    if((invip=fopen("OperateData.txt","a"))==NULL)
                    {
                        printf("�ļ���ʧ��\n");
                        exit(0);
                    }
                    fprintf(invip,"%d��%d��%d��\t���%s\t%dʱ:%d��:%d��\t���֤����Ϊ:%s��vip�û�:%s,�һ�����Ʒ%d,Ŀǰ��VIP����Ϊ:%d��\n",(p->tm_year),(p->tm_mon), p->tm_mday,wday[p->tm_wday], p->tm_hour, p->tm_min, p->tm_sec,userdata.ID,userdata.user,userdata.vipchoice,userdata.vippoint);
                    fclose(invip);
                }
                else
                {
                    break;
                }
            }
            else
            {
                printf("�û�Ա�Ļ����в��㻻ȡ��Ʒ����Ա���ֿ�ͨ��ס��ʱ����ȡ\n");
            }
            break;
        }
        else
        {
            head=head->next;
        }
    }
    if(i==vipnumber)
    {
        printf("���޴���!\n");
    }
    number=fopen("number.txt","r");
    fscanf(number,"%d",&vipnumber);
    fclose(number);
    for(j=0;j<vipnumber;j++)
    {
        fprintf(fp,"%s %s %d\n",change->ID,change->name,change->vip);
        change=change->next;
    }
                    fclose(fp);
    printf("��ѯ����,�Ƿ����²�ѯ(1)�򷵻�������(0)�򷵻���һ��(2):\n");
    scanf("%d",&choice);
    while(!(choice==1 || choice==0|| choice==2))
    {
        printf("��������ȷ������\n");
        scanf("%d",&choice);
    }
    switch(choice)
    {
        case 1: Find();break;
        case 0: welcome();break;
        case 2: VipService();break;
    }
}
void change1()
{
    int choice;
    int i,j;
    FILE *fp;
    FILE *invip;
    people *head,*change;
    char target[20];
    char now_name[20];
    char now_ID[20];
    int now_vip;
    head=VipList();
    change=head;
    if((fp=fopen("vip.txt","w"))==NULL)
    {
        printf("�ļ���ʧ��\n");
        exit(0);
    }
    printf("��������Ҫ�޸ĵ�vip�û������������֤����\n");
    scanf("%s",target);
    number=fopen("number.txt","r");
    fscanf(number,"%d",&vipnumber);
    fclose(number);
    for(i=0;i<vipnumber;i++)
    {
        if(strcmp(target,head->name)==0||strcmp(target,head->ID)==0)
        {
            printf("��Ա��Ϣ��\n");
            printf("����:");
            printf("%s\n",head->name);
            stpcpy(userdata.user,head->name);
            printf("���֤��:");
            printf("%s\n",head->ID);
            stpcpy(userdata.ID,head->ID);
            printf("vip����:");
            printf("%d\n",head->vip);
            printf("��ѡ����Ҫ�޸ĵ���Ϣ(1-3):1.���֤��\t2.����\t3.VIP����\n");
            scanf("%d",&choice);
            while(!(choice==2 || choice==1|| choice==3))
            {
                printf("��ѡ����ȷѡ��:\n");
            }
            switch(choice)
            {
                case 1:
                    printf("��������ĺ�����֤��:\n");
                    scanf("%s",now_ID);
                    stpcpy(head->ID,now_ID);
                    printf("���ĺ����ϢΪ:\n���֤��:%s\n����:%s\n",head->ID,head->name);
                    number=fopen("number.txt","r");
                    fscanf(number,"%d",&vipnumber);
                    fclose(number);
                    for(j=0;j<vipnumber;j++)
                    {
                        fprintf(fp,"%s %s %d\n",change->ID,change->name,change->vip);
                        change=change->next;
                    }
                    fclose(fp);
                    Timeget();
                    if((invip=fopen("OperateData.txt","a"))==NULL)
                    {
                        printf("�ļ���ʧ��\n");
                        exit(0);
                    }
                    fprintf(invip,"%d��%d��%d��\t���%s\t%dʱ:%d��:%d��\tvip�û�:%s���������֤��Ϣ��%s\n",(p->tm_year),(p->tm_mon), p->tm_mday,wday[p->tm_wday], p->tm_hour, p->tm_min, p->tm_sec,head->name,head->ID);
                    fclose(invip);
                    printf("��������(1)�򷵻���һ��(2)?(1-2):\n");
                    scanf("%d",&choice);
                    while((!choice==2 || choice==1))
                    {
                        printf("��ѡ����ȷѡ��:\n");
                        scanf("%d",&choice);
                    }
                    switch (choice)
                    {
                        case 1:
                            change1();
                            break;
                        case 2:
                            VipService();
                            break;
                    }
                case 2:
                    printf("��������ĺ������:\n");
                    scanf("%s",now_name);
                    stpcpy(head->name,now_name);
                    printf("���ĺ����ϢΪ:\n���֤��:%s\n����:%s\n",head->ID,head->name);
                    number=fopen("number.txt","r");
                    fscanf(number,"%d",&vipnumber);
                    fclose(number);
                    for(j=0;j<vipnumber;j++)
                    {
                        fprintf(fp,"%s %s %d\n",change->ID,change->name,change->vip);
                        change=change->next;
                    }
                    fclose(fp);
                    Timeget();
                    if((invip=fopen("OperateData.txt","a"))==NULL)
                    {
                        printf("�ļ���ʧ��\n");
                        exit(0);
                    }
                    fprintf(invip,"%d��%d��%d��\t���%s\t%dʱ:%d��:%d��\t���֤Ϊ%s��vip�û�������������Ϣ��%s\n",(p->tm_year),(p->tm_mon), p->tm_mday,wday[p->tm_wday], p->tm_hour, p->tm_min, p->tm_sec,head->ID,head->name);
                    fclose(invip);
                    printf("��������(1)�򷵻���һ��(2)?(1-2):\n");
                    scanf("%d",&choice);
                    while(!(choice==2 || choice==1))
                    {
                        printf("��ѡ����ȷѡ��:\n");
                        scanf("%d",&choice);
                    }
                    switch (choice)
                    {
                        case 1:
                            change1();
                            break;
                        case 2:
                            VipService();
                            break;
                    }
                case 3:
                    printf("��������ĺ��vip����:\n");
                    scanf("%d",&now_vip);
                    head->vip=now_vip;
                    printf("���ĺ����ϢΪ:\n���֤��:%s\n����:%s\nvip����:%d\n",head->ID,head->name,head->vip);
                    number=fopen("number.txt","r");
                    fscanf(number,"%d",&vipnumber);
                    fclose(number);
                    for(j=0;j<vipnumber;j++)
                    {
                        fprintf(fp,"%s %s %d\n",change->ID,change->name,change->vip);
                        change=change->next;
                    }
                    fclose(fp);
                    Timeget();
                    if((invip=fopen("OperateData.txt","a"))==NULL)
                    {
                        printf("�ļ���ʧ��\n");
                        exit(0);
                    }
                    fprintf(invip,"%d��%d��%d��\t���%s\t%dʱ:%d��:%d��\tvip�û�:%s������vip������Ϣ:��%d\n",(p->tm_year),(p->tm_mon), p->tm_mday,wday[p->tm_wday], p->tm_hour, p->tm_min, p->tm_sec,head->name,head->vip);
                    fclose(invip);
                    printf("��������(1)�򷵻���һ��(2)?(1-2):\n");
                    scanf("%d",&choice);
                    while(!(choice==2 || choice==1))
                    {
                        printf("��ѡ����ȷѡ��:\n");
                        scanf("%d",&choice);
                    }
                    switch (choice)
                    {
                        case 1:
                            change1();
                            break;
                        case 2:
                            VipService();
                            break;
                    }
            }
        }
        else
        {
            head=head->next;
        }
    }
    if(i==vipnumber)
    {
        printf("���޴���!\n");
    }
    for(;change->next!=NULL;)
    {
        fprintf(fp,"%s %s %d\n",change->ID,change->name,change->vip);
        change=change->next;
    }
    fclose(fp);
    printf("��ѯ����,�Ƿ����²�ѯ(1)�򷵻�������(0)���߷�����һ��(2):\n");
    scanf("%d",&choice);
    while(!(choice==1 || choice==0))
    {
        printf("��������ȷ������\n");
        scanf("%d",&choice);
    }
    switch(choice)
    {
        case 1: Find();break;
        case 0: welcome();break;
    }
}
void vipcreat()
{
    FILE *fp;
    FILE *op;
    int choice;
    char new_ID[20];
    char new_name[20];
    int new_point=0;
    if((fp=fopen("vip.txt","a"))==NULL)
    {
        printf("�ļ���ʧ��\n");
        exit(0);
    }
    vipnumber+=1;
    number=fopen("number.txt","w");
    fprintf(number,"%d",vipnumber);
    fclose(number);
    printf("���������û����֤��\n");
    scanf("%s",new_ID);
    printf("���������û�����:\n");
    scanf("%s",new_name);
    fprintf(fp,"%s %s %d\n",new_ID,new_name,new_point);
    fclose(fp);
    Timeget();
    if((op=fopen("OperateData.txt","a"))==NULL)
    {
        printf("�ļ���ʧ��\n");
        exit(0);
    }
    fprintf(op,"%d��%d��%d��\t���%s\t%dʱ:%d��:%d��\t��vip�û�����:%s,���֤Ϊ:%s\n",(p->tm_year),(p->tm_mon), p->tm_mday,wday[p->tm_wday], p->tm_hour, p->tm_min, p->tm_sec,new_name,new_ID);
    fclose(op);
    printf("�����ɹ�!���������򷵻���һ��?(1-2)\n");
    while((!scanf("%d",&choice)&&(choice==2 || choice==1)))
    {
        printf("��ѡ����ȷѡ��:\n");
        scanf("%d",&choice);
    }
    switch (choice)
    {
        case 1:
            vipcreat();
            break;


        case 2:
            VipService();
            break;
    }
}
void VipService()
{
    int choice;
    system("cls");
    printf("*******************************************\n");
    printf("*-----------------------------------------*\n");
    printf("*|                                       |*\n");
    printf("*|                                       |*\n");
    printf("*|        1.��Ա��Ϣ���Ҽ���Ʒ�һ�       |*\n");
    printf("*|        2.��Ա��Ϣ�޸�                 |*\n");
    printf("*|        3.������Ա�˻�                 |*\n");
    printf("*|        4.�������˵�                   |*\n");
    printf("*|                                       |*\n");
    printf("*|                                       |*\n");
    printf("*-----------------------------------------*\n");
    printf("*******************************************\n");
    printf("��ѡ�����(1-4):\n");
    scanf("%d",&choice);
    while(!(choice==2 || choice==1||choice==3||choice==4))
    {
        printf("��ѡ����ȷѡ��:\n");
        scanf("%d",&choice);
    }
    switch(choice)
    {
        case 1:
            Find();
            break;
        case 2:
            change1();
            break;
        case 3:
            vipcreat();
            break;
        case 4:
            welcome();
            break;
    }
}
/*
void vipsearch(char *target )
{
    int i,j;
    FILE *fp;
    FILE *invip;
    people *head,*change;
    number=fopen("number.txt","r");
    fscanf(number,"%d",&vipnumber);
    fclose(number);
    head=VipList();
    change=head;
    fp=fopen("vip.txt","w");
    change=head;
    for(i=0;i<vipnumber;i++)
    {
        if(strcmp(target,head->ID)==0)
        {
            printf("���û�ΪVIP�û���ÿ����ס��������VIP�������˴ε���ס��������2�֡�\n");
            head->vip+=2;
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
}
*/
