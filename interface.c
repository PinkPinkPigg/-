#include <stdio.h>
#include <windows.h>
void sys_exit(){
    printf("----------------------------------------------\n");
    printf("��л����ʹ�ã�");
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
    printf("*|                 1->��ס�Ǽ�               |*\n");
    printf("*|                 2->�˷�����               |*\n");
    printf("*|                 3->ϵͳ����               |*\n");
    printf("*|                 4->��Ա����               |*\n");
    printf("*|                 5->�˳�ϵͳ               |*\n");
    printf("*|                 6->ʱ����ʾ               |*\n");
    printf("*|                                           |*\n");
    printf("*|                                           |*\n");
    printf("*---------------------------------------------*\n");
    printf("***********************************************\n");
    printf("��ѡ���Ӧ������1-6\n");
    scanf("%d",&operation);
    getchar();
    while(operation<1 || operation>6){
        printf("��������ȷ������(1-6)��\n");
        scanf("%d",&operation);
        getchar();
    }
    system("cls");  //��������
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
