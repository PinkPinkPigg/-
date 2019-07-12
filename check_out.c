#include "header.h"
#include <stdio.h>
#include <string.h>

extern Room rooms[4][10];
extern operatedata userdata;
extern char *wday[] ;
extern struct tt * p;
//显示并选择可执行退房操作的房间
static int select_num(){
    int i,j,num,Found=0;
    char con;
    int fullrooms[40];
    system("cls");
    printf("可执行退房操作的房间：\n");
    for(i=0; i<4; i++){
        for(j=0; j<10; j++){
            if(rooms[i][j].condition == 1){
                printf("%-5d",rooms[i][j].num);
                fullrooms[i*10+j] = rooms[i][j].num;
                Found = 1;
            }
        }
        putchar(10);
    }
    if (Found == 1){//增加
        printf("请选择房间：");
        scanf("%d",&num);
        getchar();
        while(!Is_In_Arr(fullrooms,40,num)){
            printf("请输入正确的房间号：\n");
            scanf("%d",&num);
            getchar();
        }
        return num;
    }//增加
    else if (Found == 0)//增加
    {
        printf("无可退房房间！按任意键返回。\n");//增加
        con = getch();//增加
        welcome();//增加
    }//增加
    /*
    printf("请选择房间：");
    scanf("%d",&num);
    getchar();
    while(!Is_In_Arr(fullrooms,40,num)){
        printf("请输入正确的房间号：\n");
        scanf("%d",&num);
        getchar();
    }
    //userdata.outroomnumber=num;
    return num;
    }//增加
    else if (Found == 0)//增加
    {
        printf("无可退房房间！按任意键返回。\n");//增加
        con = getch();//增加
        welcome();//增加
    }//增加
    */
    }

//计算房费
static int cal(int num){
    int i,j,bill;
    i = num/100-1;
    j = num-(i+1)*100-1;
    switch (rooms[i][j].WoU){
    case 1:
        bill=rooms[i][j].price1*rooms[i][j].time+rooms[i][j].addcount1*70+rooms[i][j].addcount2*15+rooms[i][j].addcount3*120;
        //userdata.money=bill;
        return bill; //rooms[i][j].price1*rooms[i][j].time+rooms[i][j].addcount1*70+rooms[i][j].addcount2*15+rooms[i][j].addcount3*120;
    case 2:
        bill=rooms[i][j].price2*rooms[i][j].time+rooms[i][j].addcount1*70+rooms[i][j].addcount2*15+rooms[i][j].addcount3*120;
        //userdata.money=bill;
        return bill;//rooms[i][j].price2*rooms[i][j].time+rooms[i][j].addcount1*70+rooms[i][j].addcount2*15+rooms[i][j].addcount3*120;
    }
}
static int calc(int num){//增加
    int i,j,bill;//增加
    i = num/100-1;//增加
    j = num-(i+1)*100-1;//增加
    switch (rooms[i][j].WoU){//增加
    case 1: return rooms[i][j].price1*rooms[i][j].time;//增加
    case 2: return rooms[i][j].price2*rooms[i][j].time;//增加
    }//增加
}//增加

//进行是否退房的确认
static void confirm(int num){
    int op,i,j;
    i = num/100-1;
    j = num-(i+1)*100-1;
    printf("%d号房间，入住人%s，是否确认退房？ 确认请按1，重新选择请按2，返回主菜单请按0。\n",num,rooms[i][j].name);
    scanf("%d",&op);
    getchar();
    while(op>2 || op<0){
        printf("请输入正确数字。\n");
        scanf("%d",&op);
        getchar();
    }
    if(op==2){
        check_out();
    }else if(op == 0){
        welcome();
    }
    else
    {
        strcpy(userdata.user,rooms[i][j].name);
    }
}

//修改rooms的数据，并写入文档中
static void revise(int num){
    int i,j;
    char blank[1] = "";
    i = num/100-1;
    j = num-(i+1)*100-1;
    rooms[i][j].condition = 0;
    rooms[i][j].time = 0;
    rooms[i][j].WoU = 1;
    rooms[i][j].addcount1 = 0;
    rooms[i][j].addcount2 = 0;
    rooms[i][j].addcount3 = 0;
    strcpy(rooms[i][j].name,blank);
    write_in();
}

//返回主菜单或者继续退房
static void IfBack(){
    int opera;
    printf("继续退房请按0，返回主界面请按1\n");
    scanf("%d",&opera);
    while(!(opera==1 || opera==0)){
        printf("请输入正确的数字\n");
        scanf("%d",&opera);
    }
    switch(opera){
    case 0: check_out();
    case 1: welcome();
    }
}

void check_out()
{
    int num,bill,rbill,abill;
    FILE *fp;
    num = select_num();
    bill = cal(num);
    confirm(num);
    rbill = calc(num);//增加
    abill = bill-rbill;//增加
    revise(num);
    printf("%d号房间退房成功，房间费用为: %d 附加服务费用为: %d 总计收费: %d\n",num,rbill,abill,bill);//printf("%d号房间退房成功，总计收费%d：\n",num,bill);
    userdata.money=bill;
    userdata.outroomnumber=num;
    Timeget();
    //fp=fopen("B:\\my codeQWQ\\Debug\\My_Hotel 7.9 16.18\\OperateData.txt","w");
    if((fp=fopen("OperateData.txt","a"))==NULL)
    {
        printf("文件打开失败\n");
        exit(0);
    }
    fprintf(fp,"%d年%d月%d日\t礼拜%s\t%d时:%d分:%d秒\t 住户:%s为房间:%d办理退房,收费为:%d。(其中附加服务费为:%d,房间费用为:%d)\n",(p->tm_year),(p->tm_mon), p->tm_mday,wday[p->tm_wday], p->tm_hour, p->tm_min, p->tm_sec,userdata.user,userdata.outroomnumber,userdata.money,abill,rbill);
    fclose(fp);
    IfBack();
}
