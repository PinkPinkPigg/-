#define LEN 20
#include <ctype.h>
#include <string.h>

//�����˺�����ĺ���
void inAcc(char *acc, char* pass){
    char c;
    int i=0;
    printf("������20λ���ڵ��˺�����\n");
    gets(acc);
    printf("������20λ���ڵ����룺\n");
    while((c=getch())!='\r'){
        if(i<LEN && isprint(c)){
            *(pass+(i++)) = c;
            putchar('*');
        }
        else if(i>0 && c=='\b'){
            putchar('\b');
            putchar(' ');
            putchar('\b');
            *(pass+(--i)) = 0;
        }
    }
    putchar(10);

/*
    putchar('\n');
    puts(acc);
    puts(pass);
*/
}


void login(){
    char acc[LEN],pass[LEN] = "";
    int i;
    char c;
    char *ac = acc,*pa = pass;
    printf("�����������˺����롣\n");
    inAcc(ac,pa);

    while(strcmp(acc,"jxufe") || strcmp(pass,"jxufe")){
        printf("�˺Ż�������������������롣\n");
        memset(ac,0,sizeof(char)*LEN);  //���ԭ����
        memset(pa,0,sizeof(char)*LEN);
        inAcc(ac,pa);
    }
    printf("��¼�ɹ���\n");
    printf("-----------------------------\n");
    putchar('\n');
}
