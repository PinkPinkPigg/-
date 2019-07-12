#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct
{
    int num;
    int level;  //����ȼ�
    int price1,price2;
    char sex[10];
    char ID[20];
    int age;
    int condition;  //���䵱ǰ��ס�����1Ϊ����Ԥ����0Ϊ��Ԥ��
    char name[20];
    int WoU;
    int addcount1,addcount2,addcount3;//���ӷ������ addprice1Ϊ������ 70/�Σ�addprice2Ϊ���Ӹ���Ƶ�� 15��addprice3ΪSPA 120/��
    unsigned int time;  //Ԥ����סʱ��
} Room;
typedef struct data
{
    char name[20];
    char ID[20];
    int vip;
    struct data *next;
}people;
typedef struct operate
{
    char user[20];
    char sex[10];
    int age;
    int time;
    int roomnumber;
    int outroomnumber;
    int money;
    int vipchoice;
    int vippoint;
    char ID[20];
}operatedata;
     struct tt
    {
        int tm_sec;
        int tm_min;
        int tm_hour;
        int tm_mday;
        int tm_mon;
        int tm_year;
        int tm_wday;
        int tm_yday;
        int tm_isdst;
    };
void hotel();
void login();
void management();
void check_in();
void check_out();
int cacul();
void Find();
void TimePrintf();
void Timeget();
void change1();
void vipcreat();
void VipService();
void welcome();

#endif // HEADER_H_INCLUDED
