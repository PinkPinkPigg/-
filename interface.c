#include <stdio.h>
#include <windows.h>
void sys_exit(){
    printf("----------------------------------------------\n");
    printf("感谢您的使用！");
    exit(0);
}

void welcome(){
    int operation=0;
    Sleep(500);
    system("cls");
    printf("***********************************************\n");
    printf("*---------------------------------------------*\n");
    printf("*|                                           |*\n");
    printf("*|                                           |*\n");
    printf("*|                 1->入住登记               |*\n");
    printf("*|                 2->退房结算               |*\n");
    printf("*|                 3->系统管理               |*\n");
    printf("*|                 4->会员管理               |*\n");
    printf("*|                 5->退出系统               |*\n");
    printf("*|                 6->时间显示               |*\n");
    printf("*|                                           |*\n");
    printf("*|                                           |*\n");
    printf("*---------------------------------------------*\n");
    printf("***********************************************\n");
    printf("请选择对应操作：1-6\n");
    scanf("%d",&operation);
    getchar();
    while(operation<1 || operation>6){
        printf("请输入正确的数字(1-6)：\n");
        scanf("%d",&operation);
        getchar();
    }
    system("cls");  //清屏操作
    switch(operation){
    case 1:
        check_in();
        break;
    case 2:
        check_out();
        break;
    case 3:
        management();
        break;
    case 4:
         VipService();
        break;
    case 5:
        sys_exit();
    case 6:
        TimePrintf();
    }
}
