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
    printf("请输入增加服务的房间号，或者按1返回：\n");
    scanf("%d",&op);
    if (op==1)   management();
    for (i=0;i<4;i++){
        for (j=0;j<10;j++){
            if(op==rooms[i][j].num){
                if(!rooms[i][j].condition){
                    printf("此房间无人居住！请重新核对！按任意键返回。\n");
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
                    printf("*|            1->健身房 70/次            |*\n");
                    printf("*|            2->电视付费频道 15/次      |*\n");
                    printf("*|            3->SPA 120/次              |*\n");
                    printf("*|            4->返回上一级菜单          |*\n");
                    printf("*|                                       |*\n");
                    printf("*|                                       |*\n");
                    printf("*-----------------------------------------*\n");
                    printf("*******************************************\n");
                    printf("请选择附加服务(1~3)，或按4返回上一级菜单:\n");
                    scanf("%d",&add);
                    while(!(add==1 || add==2 || add==3 || add==4)){
                        printf("请输入正确的数字。\n");
                        scanf("%d",&add);
                    }
                    switch(add){
                    case 1:rooms[i][j].addcount1+=1; break;
                    case 2:rooms[i][j].addcount2+=1; break;
                    case 3:rooms[i][j].addcount3+=1; break;
                    case 4:management(); break;
                    }
                    printf("添加成功！\n");
                    Timeget();
                    opdata=fopen("OperateData.txt","a");
                    fprintf(opdata,"%d年%d月%d日\t礼拜%s\t%d时:%d分:%d秒\t住户:%s,年龄:%d,性别:%s,身份证号为:%s在房间%d选择了附加服务:%d\n",(p->tm_year),(p->tm_mon), p->tm_mday,wday[p->tm_wday], p->tm_hour, p->tm_min, p->tm_sec,rooms[i][j].name,rooms[i][j].age,rooms[i][j].sex,rooms[i][j].ID,rooms[i][j].num,add);
                    fclose(opdata);
                    write_in();
                    Found=1;
                }
            }
        }
    }
    if(!Found){
        printf("没有这个房间，请按任意键返回。\n");
        con = getch();
        management();
    }
    printf("请按任意键返回。\n");
    con = getch();
    management();
}

//根据房间编号进行搜索，输出房间相关信息
static void search_by_num(){
    int i,j,num,op,Found=0;
    char con;
    printf("请输入查找的房间编号，或者按1返回：\n");
    scanf("%d",&op);
    getchar();
    if(op==1)   query();
    for(i=0; i<4; i++){
        for(j=0; j<10; j++){
            if(op == rooms[i][j].num){
                if(!rooms[i][j].condition){
                    printf("房间编号：%-5d房间状态：%d\n",rooms[i][j].num,rooms[i][j].condition);
                    Found = 1;
                }
                else{
                    printf("房间编号：%-5d入住人姓名：%-10s\n身份证号为:%-10s入住时间：%-5d\n",rooms[i][j].num,rooms[i][j].name,rooms[i][j].ID,rooms[i][j].time);
                    Found = 1;
                }
            }
        }
    }
    if(!Found){
        printf("没有这个房间，请按任意键返回。\n");
        con = getch();
        query();
    }
    printf("请按任意键返回。\n");
    con = getch();
    query();
}
static void search_by_name(){
    int i,j,op,Found=0;
    char name[20];
    char con;
    printf("请输入客户的姓名，或者按1返回：\n");
    scanf("%s",name);
    getchar();
    if(op==1)   query();
    for(i=0; i<4; i++){
        for(j=0; j<10; j++){
            if(strcmp(name,rooms[i][j].name)==0){
                printf("房间编号：%-5d入住人姓名：%-10s,性别:%-10s,年龄:%-5d,身份证号:%-10s,入住时间：%-5d\n",rooms[i][j].num,rooms[i][j].name,rooms[i][j].sex,rooms[i][j].age,rooms[i][j].ID,rooms[i][j].time);
                Found = 1;
            }
        }
    }
    if(!Found){
        printf("没有该客户，请按任意键返回。\n");
        con = getch();
        query();
    }
    printf("请按任意键返回。\n");
    con = getch();
    query();

}

//可以修改房间客户姓名的函数件
static void revise(){
    int i,j,time,op,Found=0;
    char con;
    int age;
    char sex[10];
    char name[20];
    char ID[20];
    printf("请输入想要修改的房间编号，或者按1返回：\n");
    scanf("%d",&op);
    getchar();
    if(op==1)   management();
    for(i=0; i<4; i++){
        for(j=0; j<10; j++){
            if(op == rooms[i][j].num){
                if(!rooms[i][j].condition){
                    printf("房间编号：%-5d房间状态：%d\n",rooms[i][j].num,rooms[i][j].condition);
                    printf("请输入客户信息并修改房间状态为不可预定：\n");
                    printf("请输入姓名:\n");
                    scanf("%s",name);
                    //printf("请输入入住时间：\n");
                   // scanf("%d",time);
                    strcpy(rooms[i][j].name,name);
                    printf("请输入身份证号:\n");
                    scanf("%s",ID);
                    strcpy(rooms[i][j].ID,ID);
                    printf("请输入性别:\n");
                    scanf("%s",sex);
                    strcpy(rooms[i][j].sex,sex);
                    printf("请输入年龄:\n");
                    scanf("%d",&age);
                    rooms[i][j].age=age;
                    printf("请输入修改后的入住时间：\n");
                    while(!scanf("%d",&time)){
                        getchar();
                        printf("请输入正确的数字。\n");
                    }
                    rooms[i][j].time = time;
                    rooms[i][j].condition = 1;
                    Found = 1;
                    Timeget();
                    opdata=fopen("OperateData.txt","a");
                    fprintf(opdata,"%d年%d月%d日\t礼拜%s\t%d时:%d分:%d秒\t%d号房间信息修改为:住户:%s,性别:%s,年龄:%d身份证号:%s\n",(p->tm_year),(p->tm_mon), p->tm_mday,wday[p->tm_wday], p->tm_hour, p->tm_min, p->tm_sec,rooms[i][j].num,rooms[i][j].name,rooms[i][j].sex,rooms[i][j].age,rooms[i][j].ID);
                    fclose(opdata);
                    write_in();
                }
                else{
                    printf("房间编号：%-5d入住人姓名：%-10s性别:%-10s年龄:%-5d身份证号:%-10s入住时间：%-5d\n",rooms[i][j].num,rooms[i][j].name,rooms[i][j].sex,rooms[i][j].age,rooms[i][j].ID,rooms[i][j].time);
                    printf("房间编号：%-5d房间状态：%d\n",rooms[i][j].num,rooms[i][j].condition);
                    printf("请输入修改后的客户姓名：\n");
                    scanf("%s",name);
                    strcpy(rooms[i][j].name,name);
                    printf("请输入修改后的客户身份证号：\n");
                    scanf("%s",ID);
                    strcpy(rooms[i][j].ID,ID);
                    printf("请输入修改后的客户年龄：\n");
                    scanf("%d",&age);
                    rooms[i][j].age=age;
                    printf("请输入修改后的客户性别：\n");
                    scanf("%s",sex);
                    strcpy(rooms[i][j].sex,sex);
                    printf("请输入修改后的入住时间：\n");
                    while(!scanf("%d",&time)){
                        getchar();
                        printf("请输入正确的数字。\n");
                    }
                    rooms[i][j].time = time;
                    Found = 1;
                    Timeget();
                    opdata=fopen("OperateData.txt","a");
                    fprintf(opdata,"%d年%d月%d日\t礼拜%s\t%d时:%d分:%d秒\t%d号房间信息修改为:住户:%s,性别:%s,年龄:%d\n身份证:%s\n",(p->tm_year),(p->tm_mon), p->tm_mday,wday[p->tm_wday], p->tm_hour, p->tm_min, p->tm_sec,rooms[i][j].num,rooms[i][j].name,rooms[i][j].sex,rooms[i][j].age,rooms[i][j].ID);
                    fclose(opdata);
                    write_in();
                }
            }
        }
    }
    if(!Found){
        printf("没有这个房间，请按任意键返回。\n");
        con = getch();
        management();
    }
    printf("修改成功，请按任意键返回。\n");
    con = getch();
    management();
}


static void del(){
    int i,j,op,Found=0;
    char blank[1] = "";
    char con;
    printf("请输入想要进行删除操作的房间编号，或者按1返回：\n");
    scanf("%d",&op);
    getchar();
    if(op==1)   management();
    for(i=0; i<4; i++){
        for(j=0; j<10; j++){
            if(op == rooms[i][j].num){
                if(!rooms[i][j].condition){
                    printf("该房间目前没有入住信息，无须删除。\n");
                    Found = 1;
                }
                else{
                    printf("房间编号：%-5d入住人姓名：%-10s性别:%-10s年龄:%-5d身份证:%-10s入住时间：%-5d\n",rooms[i][j].num,rooms[i][j].name,rooms[i][j].sex,rooms[i][j].age,rooms[i][j].ID,rooms[i][j].time);
                    printf("是否删除入住信息？  按1确认，按0返回。\n");
                    scanf("%d",&op);
                    while(!(op==1 || op==0)){
                        printf("请输入正确的数字。\n");
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
                        fprintf(opdata,"%d年%d月%d日\t礼拜%s\t%d时:%d分:%d秒\t%d号房间住户信息被删除\n",(p->tm_year),(p->tm_mon), p->tm_mday,wday[p->tm_wday], p->tm_hour, p->tm_min, p->tm_sec,rooms[i][j].num);
                        fclose(opdata);
                        printf("删除成功。\n");
                    }
                    else    management();
                    Found = 1;
                }
            }
        }
    }
    if(!Found){
        printf("没有这个房间，请按任意键返回。\n");
        con = getch();
        management();
    }
    printf("请按任意键返回。\n");
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
    printf("*|         1.显示全部房间信息。          |*\n");
    printf("*|         2.按照房间编号搜索。          |*\n");
    printf("*|         3.按照客户姓名搜索。          |*\n");
    printf("*|         4.返回上一级菜单。            |*\n");
    printf("*|                                       |*\n");
    printf("*|                                       |*\n");
    printf("*-----------------------------------------*\n");
    printf("*******************************************\n");
    scanf("%d",&op);
    getchar();
    while(op>4 || op<1){
        printf("请输入正确的数字。\n");
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
    printf("*|               1->住房信息查询             |*\n");
    printf("*|               2->住房信息修改             |*\n");
    printf("*|               3->住房信息删除             |*\n");
    printf("*|               4->客房附加服务             |*\n");
    printf("*|               5->返回主菜单               |*\n");
    printf("*|                                           |*\n");
    printf("*|                                           |*\n");
    printf("*---------------------------------------------*\n");
    printf("***********************************************\n");
    printf("请选择对应操作(1-5)\n");
    scanf("%d",&op);
    getchar();
    while(op<1 || op>5){
        printf("请输入正确的数字(1-5)：\n");
        scanf("%d",&op);
        getchar();
    }
    system("cls");  //清屏操作
    switch(op){
    case 1: query();    break;
    case 2: revise();   break;
    case 3: del();  break;
    case 4: additional_survise();  break;
    case 5: welcome();  break;
    }
}
