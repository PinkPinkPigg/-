#define LEN 20
#include <ctype.h>
#include <string.h>

//输入账号密码的函数
void inAcc(char *acc, char* pass){
    char c;
    int i=0;
    printf("请输入20位以内的账号名：\n");
    gets(acc);
    printf("请输入20位以内的密码：\n");
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
    printf("请输入您的账号密码。\n");
    inAcc(ac,pa);

    while(strcmp(acc,"jxufe") || strcmp(pass,"jxufe")){
        printf("账号或者密码错误，请重新输入。\n");
        memset(ac,0,sizeof(char)*LEN);  //清空原数组
        memset(pa,0,sizeof(char)*LEN);
        inAcc(ac,pa);
    }
    printf("登录成功！\n");
    printf("-----------------------------\n");
    putchar('\n');
}
