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
        printf("文件打开失败\n");
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
    printf("请输入会员姓名或身份证号码进行查询:\n");
    scanf("%s",target);
    number=fopen("number.txt","r");
    fscanf(number,"%d",&vipnumber);
    fclose(number);
    for(i=0;i<vipnumber;i++)
    {
        if(strcmp(target,head->name)==0||strcmp(target,head->ID)==0)
        {
            printf("会员信息：\n");
            printf("姓名:");
            printf("%s\n",head->name);
            stpcpy(userdata.user,head->name);
            printf("身份证号:");
            printf("%s\n",head->ID);
            stpcpy(userdata.ID,head->ID);
            printf("vip点数:");
            printf("%d\n",head->vip);
            if(head->vip>=5)
            {
                printf("该会员积分可换取礼品，是否要通过会员积分换取礼品?(1 OR 0) 1兑换，0退出\n");
                scanf("%d",&choice);
                while(!(choice==1 || choice==0))
                {
                    printf("请选择正确选项:\n");
                    scanf("%d",&choice);
                }
                if(choice==1)
                {
                    system("cls");
                    printf("***********************************************\n");
                    printf("*---------------------------------------------*\n");
                    printf("*|                                           |*\n");
                    printf("*|                   礼品                    |*\n");
                    printf("*|                                           |*\n");
                    printf("*|             1.代金券80元  5分             |*\n");
                    printf("*|             2.早or中or晚餐券 2分          |*\n");
                    printf("*|             3.精美酒店形象公仔  2分       |*\n");
                    printf("*|             4.日用品礼包  1分             |*\n");
                    printf("*|             5.返回上一级菜单              |*\n");
                    printf("*|                                           |*\n");
                    printf("*|                                           |*\n");
                    printf("*---------------------------------------------*\n");
                    printf("***********************************************\n");
                    printf("请输入需要兑换的礼品代号:(1-4)\n");
                    scanf("%d",&choice);
                    while(!(choice==1 || choice==2|| choice==3|| choice==4))
                    {
                        printf("请选择正确选项:\n");
                        scanf("%d",&choice);
                    }
                    // /*
                    userdata.vipchoice=choice;
                    switch(choice)
                    {
                        case 1:
                            printf("恭喜你已成功兑换:代金券80元\n");
                            head->vip-=5;
                            userdata.vippoint=head->vip;
                            break;
                        case 2:
                            printf("恭喜你已成功兑换:早or中or晚餐券\n");
                            head->vip-=2;
                            userdata.vippoint=head->vip;
                            break;
                        case 3:
                            printf("恭喜你已成功兑换:精美酒店形象公仔\n");
                            head->vip-=2;
                            userdata.vippoint=head->vip;
                            break;
                        case 4:
                            printf("恭喜你已成功兑换:日用品礼包\n");
                            head->vip-=1;
                            userdata.vippoint=head->vip;
                            break;
                    }
                    Timeget();
                    if((invip=fopen("OperateData.txt","a"))==NULL)
                    {
                        printf("文件打开失败\n");
                        exit(0);
                    }
                    fprintf(invip,"%d年%d月%d日\t礼拜%s\t%d时:%d分:%d秒\t身份证号码为:%s的vip用户:%s,兑换了礼品%d,目前的VIP积分为:%d。\n",(p->tm_year),(p->tm_mon), p->tm_mday,wday[p->tm_wday], p->tm_hour, p->tm_min, p->tm_sec,userdata.ID,userdata.user,userdata.vipchoice,userdata.vippoint);
                    fclose(invip);
                }
                else
                {
                    break;
                }
            }
            else
            {
                printf("该会员的积分尚不足换取礼品，会员积分可通过住房时长换取\n");
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
        printf("查无此人!\n");
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
    printf("查询结束,是否重新查询(1)或返回主界面(0)或返回上一步(2):\n");
    scanf("%d",&choice);
    while(!(choice==1 || choice==0|| choice==2))
    {
        printf("请输入正确的数字\n");
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
        printf("文件打开失败\n");
        exit(0);
    }
    printf("请输入需要修改的vip用户的姓名或身份证号码\n");
    scanf("%s",target);
    number=fopen("number.txt","r");
    fscanf(number,"%d",&vipnumber);
    fclose(number);
    for(i=0;i<vipnumber;i++)
    {
        if(strcmp(target,head->name)==0||strcmp(target,head->ID)==0)
        {
            printf("会员信息：\n");
            printf("姓名:");
            printf("%s\n",head->name);
            stpcpy(userdata.user,head->name);
            printf("身份证号:");
            printf("%s\n",head->ID);
            stpcpy(userdata.ID,head->ID);
            printf("vip点数:");
            printf("%d\n",head->vip);
            printf("请选择需要修改的信息(1-3):1.身份证号\t2.姓名\t3.VIP点数\n");
            scanf("%d",&choice);
            while(!(choice==2 || choice==1|| choice==3))
            {
                printf("请选择正确选项:\n");
            }
            switch(choice)
            {
                case 1:
                    printf("请输入更改后的身份证号:\n");
                    scanf("%s",now_ID);
                    stpcpy(head->ID,now_ID);
                    printf("更改后的信息为:\n身份证号:%s\n姓名:%s\n",head->ID,head->name);
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
                        printf("文件打开失败\n");
                        exit(0);
                    }
                    fprintf(invip,"%d年%d月%d日\t礼拜%s\t%d时:%d分:%d秒\tvip用户:%s更改了身份证信息：%s\n",(p->tm_year),(p->tm_mon), p->tm_mday,wday[p->tm_wday], p->tm_hour, p->tm_min, p->tm_sec,head->name,head->ID);
                    fclose(invip);
                    printf("继续更改(1)或返回上一步(2)?(1-2):\n");
                    scanf("%d",&choice);
                    while((!choice==2 || choice==1))
                    {
                        printf("请选择正确选项:\n");
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
                    printf("请输入更改后的姓名:\n");
                    scanf("%s",now_name);
                    stpcpy(head->name,now_name);
                    printf("更改后的信息为:\n身份证号:%s\n姓名:%s\n",head->ID,head->name);
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
                        printf("文件打开失败\n");
                        exit(0);
                    }
                    fprintf(invip,"%d年%d月%d日\t礼拜%s\t%d时:%d分:%d秒\t身份证为%s的vip用户更改了姓名信息：%s\n",(p->tm_year),(p->tm_mon), p->tm_mday,wday[p->tm_wday], p->tm_hour, p->tm_min, p->tm_sec,head->ID,head->name);
                    fclose(invip);
                    printf("继续更改(1)或返回上一步(2)?(1-2):\n");
                    scanf("%d",&choice);
                    while(!(choice==2 || choice==1))
                    {
                        printf("请选择正确选项:\n");
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
                    printf("请输入更改后的vip点数:\n");
                    scanf("%d",&now_vip);
                    head->vip=now_vip;
                    printf("更改后的信息为:\n身份证号:%s\n姓名:%s\nvip点数:%d\n",head->ID,head->name,head->vip);
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
                        printf("文件打开失败\n");
                        exit(0);
                    }
                    fprintf(invip,"%d年%d月%d日\t礼拜%s\t%d时:%d分:%d秒\tvip用户:%s更改了vip点数信息:：%d\n",(p->tm_year),(p->tm_mon), p->tm_mday,wday[p->tm_wday], p->tm_hour, p->tm_min, p->tm_sec,head->name,head->vip);
                    fclose(invip);
                    printf("继续更改(1)或返回上一步(2)?(1-2):\n");
                    scanf("%d",&choice);
                    while(!(choice==2 || choice==1))
                    {
                        printf("请选择正确选项:\n");
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
        printf("查无此人!\n");
    }
    for(;change->next!=NULL;)
    {
        fprintf(fp,"%s %s %d\n",change->ID,change->name,change->vip);
        change=change->next;
    }
    fclose(fp);
    printf("查询结束,是否重新查询(1)或返回主界面(0)或者返回上一步(2):\n");
    scanf("%d",&choice);
    while(!(choice==1 || choice==0))
    {
        printf("请输入正确的数字\n");
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
        printf("文件打开失败\n");
        exit(0);
    }
    vipnumber+=1;
    number=fopen("number.txt","w");
    fprintf(number,"%d",vipnumber);
    fclose(number);
    printf("请输入新用户身份证：\n");
    scanf("%s",new_ID);
    printf("请输入新用户姓名:\n");
    scanf("%s",new_name);
    fprintf(fp,"%s %s %d\n",new_ID,new_name,new_point);
    fclose(fp);
    Timeget();
    if((op=fopen("OperateData.txt","a"))==NULL)
    {
        printf("文件打开失败\n");
        exit(0);
    }
    fprintf(op,"%d年%d月%d日\t礼拜%s\t%d时:%d分:%d秒\t新vip用户创建:%s,身份证为:%s\n",(p->tm_year),(p->tm_mon), p->tm_mday,wday[p->tm_wday], p->tm_hour, p->tm_min, p->tm_sec,new_name,new_ID);
    fclose(op);
    printf("创建成功!继续创建或返回上一步?(1-2)\n");
    while((!scanf("%d",&choice)&&(choice==2 || choice==1)))
    {
        printf("请选择正确选项:\n");
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
    printf("*|        1.会员信息查找及奖品兑换       |*\n");
    printf("*|        2.会员信息修改                 |*\n");
    printf("*|        3.创建会员账户                 |*\n");
    printf("*|        4.返回主菜单                   |*\n");
    printf("*|                                       |*\n");
    printf("*|                                       |*\n");
    printf("*-----------------------------------------*\n");
    printf("*******************************************\n");
    printf("请选择服务(1-4):\n");
    scanf("%d",&choice);
    while(!(choice==2 || choice==1||choice==3||choice==4))
    {
        printf("请选择正确选项:\n");
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
            printf("该用户为VIP用户，每次入住将会增加VIP点数，此次的入住将会增加2分。\n");
            head->vip+=2;
        }
        else
        {
            head=head->next;
        }
    }
    if(i==vipnumber)
    {
        printf("该用户还不是vip用户，酒店提供vip注册功能。\n");
    }
    for(j=0;j<vipnumber;j++)
    {
        fprintf(fp,"%s %s %d\n",change->ID,change->name,change->vip);
        change=change->next;
    }
    fclose(fp);
}
*/
