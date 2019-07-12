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
    printf("继续登记请按0，返回主界面请按1\n");
    scanf("%d",&opera);
    while(!(opera==1 || opera==0))
    {
        printf("请输入正确的数字\n");
        scanf("%d",&opera);
    }
    switch(opera){
    case 0: check_in(); break;
    case 1: welcome();  break;
    }
/*
    switch(op){
    case 1:{
        printf("继续请按0，返回主界面请按2\n");
        scanf("%d",&opera);
        getchar();
        while(opera!=2 || opera!=0 ){
            printf("请输入正确的指令.\n");
            scanf("%d",&opera);
            getchar();
        }
        if(opera == 2){
            welcome();
        }else break;
    }1.酒店编号 2.房间等级 3.房间价格 4.住客姓名 5.住客年龄 6.住客性别 7.附加服务费用 8.总费用 9.日租方式 10.预计入住时间  11.
    case 2:{
        printf("继续请按0，返回请按1，返回主界面请按2\n");
        scanf("%d",&opera);
        getchar();
        while(opera!=2 || opera!=0 ){
            printf("请输入正确的指令.\n");
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

//三个函数分别是选择房型、房间编号和入住方式
int static select_type(){
    int type;
    system("cls");
    printf("***********************************\n");
    printf("*---------------------------------*\n");
    printf("*|                               |*\n");
    printf("*|            房间类型           |*\n");
    printf("*|                               |*\n");
    printf("*|          1.标准单人房         |*\n");
    printf("*|          2.标准双人房         |*\n");
    printf("*|          3.大床房             |*\n");
    printf("*|          4.豪华房             |*\n");
    printf("*|                               |*\n");
    printf("*|                               |*\n");
    printf("*---------------------------------*\n");
    printf("***********************************\n");
    printf("请选择房间类型（1~4）：\n");
    scanf("%d",&type);
    getchar();
    while(type<1 || type>4)
    {
        printf("请输入正确的数值(1-4)：\n");
        scanf("%d",&type);
        getchar();
    }
    return type;
}

 static int select_num(int level){
    int num,i;
    int available[10];
    printf("目前可入住的房间：");
    for(i = 0; i<10; i++){
        if(rooms[level-1][i].condition == 1)    continue;
        else{
            printf("%-5d",rooms[level-1][i].num);
            available[i] = rooms[level-1][i].num;
        }
    }
    putchar(10);
    printf("请选择房间号：");
    scanf("%d",&num);
    getchar();
    while(!Is_In_Arr(available,10,num)){
        printf("请选择正确的房间号：");
        scanf("%d",&num);
        getchar();
    }
    return num;
}

int static select_way(){
    int way;
    printf("请选择入住方式: 1.日租房  2.钟点房\n");
    scanf("%d",&way);
    getchar();
    while(!(way == 1 || way == 2)){
        printf("请输入正确的数值(1-2)：\n");
        scanf("%d",&way);
        getchar();
    }
    return way;
}

//进行是否退房的确认
static void confirm(int num){
    int op,i,j;
    i = num/100-1;
    j = num-(i+1)*100-1;
    printf("%d号房间，是否确认入住？ 确认请按1，重新登记请按2，返回主菜单请按0。\n",num,rooms[i][j].name);
    scanf("%d",&op);
    getchar();
    while(op>2 || op<0)
    {
        printf("请输入正确数字。\n");
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
//将信息登录进系统
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
    printf("请输入入住人姓名：");
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
            printf("该用户为VIP用户，每次入住将会增加VIP点数，此次的入住将会增加2分。\n");
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
        printf("该用户还不是vip用户，酒店提供vip注册功能。\n");
    }
    for(j=0;j<vipnumber;j++)
    {
        fprintf(fp,"%s %s %d\n",change->ID,change->name,change->vip);
        change=change->next;
    }
    fclose(fp);
    //vipsearch(name);
    stpcpy(userdata.user,name);
    printf("请输入住户身份证号:");
    scanf("%s",ID);
    stpcpy(userdata.ID,ID);
    printf("请输入住户性别:");
    scanf("%s",sex);
    stpcpy(userdata.sex,sex);
    printf("请输入住户年龄:");
    scanf("%d",&age);
    userdata.age=age;
    //userdata.user=name;<-
    printf("请输入入住时间(单位：天/小时)：\n");
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
    type = select_type();//所选房间类型
    num = select_num(type);//所选房间号
    way = select_way();//入住方式
    confirm(num);
    input(type,num,way);
    //userdata.roomnumber=num;
    //fp=fopen("B:\\my codeQWQ\\Debug\\My_Hotel 7.9 16.18\\OperateData.txt","w");
    Timeget();
    if((fp=fopen("OperateData.txt","a"))==NULL)
    {
        printf("文件打开失败\n");
        exit(0);
    }
    fprintf(fp,"%d年%d月%d日\t礼拜%s\t%d时:%d分:%d秒\t住户:%s,年龄:%d,%s登记入住%d房间,预计入住:%d天/时,身份证号为:%s。\n",(p->tm_year),(p->tm_mon), p->tm_mday,wday[p->tm_wday], p->tm_hour, p->tm_min, p->tm_sec,userdata.user,userdata.age,userdata.sex,userdata.roomnumber,userdata.time,userdata.ID);//无法写入文件
    fclose(fp);
    IfBack(4);
}
