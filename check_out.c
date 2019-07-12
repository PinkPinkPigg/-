#include "header.h"
#include <stdio.h>
#include <string.h>

extern Room rooms[4][10];
extern operatedata userdata;
extern char *wday[] ;
extern struct tt * p;
//��ʾ��ѡ���ִ���˷������ķ���
static int select_num(){
    int i,j,num,Found=0;
    char con;
    int fullrooms[40];
    system("cls");
    printf("��ִ���˷������ķ��䣺\n");
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
    if (Found == 1){//����
        printf("��ѡ�񷿼䣺");
        scanf("%d",&num);
        getchar();
        while(!Is_In_Arr(fullrooms,40,num)){
            printf("��������ȷ�ķ���ţ�\n");
            scanf("%d",&num);
            getchar();
        }
        return num;
    }//����
    else if (Found == 0)//����
    {
        printf("�޿��˷����䣡����������ء�\n");//����
        con = getch();//����
        welcome();//����
    }//����
    /*
    printf("��ѡ�񷿼䣺");
    scanf("%d",&num);
    getchar();
    while(!Is_In_Arr(fullrooms,40,num)){
        printf("��������ȷ�ķ���ţ�\n");
        scanf("%d",&num);
        getchar();
    }
    //userdata.outroomnumber=num;
    return num;
    }//����
    else if (Found == 0)//����
    {
        printf("�޿��˷����䣡����������ء�\n");//����
        con = getch();//����
        welcome();//����
    }//����
    */
    }

//���㷿��
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
static int calc(int num){//����
    int i,j,bill;//����
    i = num/100-1;//����
    j = num-(i+1)*100-1;//����
    switch (rooms[i][j].WoU){//����
    case 1: return rooms[i][j].price1*rooms[i][j].time;//����
    case 2: return rooms[i][j].price2*rooms[i][j].time;//����
    }//����
}//����

//�����Ƿ��˷���ȷ��
static void confirm(int num){
    int op,i,j;
    i = num/100-1;
    j = num-(i+1)*100-1;
    printf("%d�ŷ��䣬��ס��%s���Ƿ�ȷ���˷��� ȷ���밴1������ѡ���밴2���������˵��밴0��\n",num,rooms[i][j].name);
    scanf("%d",&op);
    getchar();
    while(op>2 || op<0){
        printf("��������ȷ���֡�\n");
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

//�޸�rooms�����ݣ���д���ĵ���
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

//�������˵����߼����˷�
static void IfBack(){
    int opera;
    printf("�����˷��밴0�������������밴1\n");
    scanf("%d",&opera);
    while(!(opera==1 || opera==0)){
        printf("��������ȷ������\n");
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
    rbill = calc(num);//����
    abill = bill-rbill;//����
    revise(num);
    printf("%d�ŷ����˷��ɹ����������Ϊ: %d ���ӷ������Ϊ: %d �ܼ��շ�: %d\n",num,rbill,abill,bill);//printf("%d�ŷ����˷��ɹ����ܼ��շ�%d��\n",num,bill);
    userdata.money=bill;
    userdata.outroomnumber=num;
    Timeget();
    //fp=fopen("B:\\my codeQWQ\\Debug\\My_Hotel 7.9 16.18\\OperateData.txt","w");
    if((fp=fopen("OperateData.txt","a"))==NULL)
    {
        printf("�ļ���ʧ��\n");
        exit(0);
    }
    fprintf(fp,"%d��%d��%d��\t���%s\t%dʱ:%d��:%d��\t ס��:%sΪ����:%d�����˷�,�շ�Ϊ:%d��(���и��ӷ����Ϊ:%d,�������Ϊ:%d)\n",(p->tm_year),(p->tm_mon), p->tm_mday,wday[p->tm_wday], p->tm_hour, p->tm_min, p->tm_sec,userdata.user,userdata.outroomnumber,userdata.money,abill,rbill);
    fclose(fp);
    IfBack();
}
