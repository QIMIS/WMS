#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
//�ṹ����
struct good              //�����Ľṹ��
{
    char *a;                            //������Ʒ������
    int year,month,day,hour,minute;     //������Ʒ�����������ʱ��
    int amount;                         //������Ʒ������
    int price;                          //������Ʒ�ļ۸�
    char *category;                     //������Ʒ������
};

struct goood             //���Ľṹ��
{
    char *a;                            //����в�Ʒ������
    int amount;                         //����в�Ʒ������
};

struct categorying
{
    char *category;                     //�����в�Ʒ�ķ�����
    int amount;                         //�÷����²�Ʒ������
};

//��̬��������
int flagm;               //�۲��Ƿ���Ҫ���������˻�

good g[1000];            //���ڴ����Ʒ�����Ϣ

good go[1000];           //���ڴ����Ʒ������Ϣ

goood goo[1000];         //���ڴ����Ʒ�����Ϣ

categorying k[1000];     //�����������

int flag1=0;             //������ΪĿǰg[1000]��������һ����ֵ��

int flag2=0;             //������ΪĿǰgo[1000]��������һ����ֵ��

int flag3=0;             //������ΪĿǰgoo[1000]��������һ����ֵ��

char *p;                 //����Ա����

int xx1=0,xx2=0;         //���ѹ���

int flagr=0;             //�۲��Ƿ���ע���˻�

int flagc=0;            //�۲�����

//��������
void input();            //��Ʒ��⹦��

void output();           //��Ʒ���⹦��

void manage();           //��������

void searching1();       //����Ʒ���Ʋ�ѯ

void searching2();       //�����ʱ���ѯ

void managerlogin();     //����Ա��½

void managerregister();  //����Աע��

void manageprint();      //�����¼����

void mainprint();        //���������

void outputx();           //��������

void inputx();            //��������

int main()               //������
{
    int k1,k2,k3;
    printf("�ֿ����ϵͳ������");
    Sleep(500);                                      //��ʱ
    printf(".");
    Sleep(500);                                      //��ʱ
    printf(".");
    Sleep(500);                                      //��ʱ
    printf(".\n");
    system("cls");                                   //����
    while(1)
    {
sk:                                                  //�û���¼����Ŀ�ʼ
        manageprint();
        scanf("%d",&k1);
        switch(k1)                                   //�û�ָ�ֵ��k1
        {
        case 1:
            managerlogin();
            if(flagm==1)
            {
                goto sk;
            }
            goto exit1;
        case 2:
            managerregister();
            break;
        case 3:
            goto exitl;
        }
    }                                                //�û���¼�������������������
exit1:
    system("cls");
    if(flagr==0)                                     //������˺�data�ļ������Ϣ
    {
        inputx();
    }
    while(1)                                         //����������ѭ��
    {
        int i,j,fll=0;                               //�������ӡ֮ǰ������ͷ�����
        for(i=0 ; i<flag3 ; i++)                     //������
        {
            goo[i].amount=0;
        }
        for(i=0 ; i<flag1 ; i++)
        {
            fll=0;
            for(j=0 ; j<flag3 ; j++)
            {
                if(strcmp(g[i].a,goo[j].a)==0)
                {
                    goo[j].amount+=g[i].amount;
                    fll=1;
                    break;
                }
            }
            if(fll==0)
            {
                goo[j].a=g[i].a;
                goo[j].amount=g[i].amount;
                flag3++;
            }
        }
        for(i=0 ; i<flag3 ; i++)
        {
            for(j=0 ; j<flag2 ; j++)
            {
                if(strcmp(goo[i].a,go[j].a)==0)
                {
                    goo[i].amount-=go[j].amount;
                }
            }
        }
        for(i=0 ; i<flag3 ; i++)
        {
            if(goo[i].amount==0)
            {
                if(i==flag3)
                {
                    flag3--;
                }
                else
                {
                    for(j=i ; j<flag3-1 ; j++)
                    {
                        goo[j].a=goo[j+1].a;
                        goo[j].amount=goo[j+1].amount;
                    }
                    flag3--;
                }
            }
        }                                                              //�����Ǽ����棬�����Ǽ��������
        for(i=0 ; i<flagc ; i++)
        {
            k[i].amount=0;
        }
        for(i=0 ; i<flag1 ; i++)
        {
            fll=0;
            for(j=0 ; j<flagc ; j++)
            {
                if(strcmp(g[i].category,k[j].category)==0)
                {
                    k[j].amount+=g[i].amount;
                    fll=1;
                    break;
                }
            }
            if(fll==0)
            {
                k[j].category=g[i].category;
                k[j].amount=g[i].amount;
                flagc++;
            }
        }
        for(i=0 ; i<flagc ; i++)
        {
            for(j=0 ; j<flag2 ; j++)
            {
                if(strcmp(k[i].category,go[j].category)==0)
                {
                    k[i].amount-=go[j].amount;
                }
            }
        }
        for(i=0 ; i<flagc ; i++)
        {
            if(k[i].amount==0)
            {
                if(i==flagc)
                {
                    flagc--;
                }
                else
                {
                    for(j=i ; j<flagc-1 ; j++)
                    {
                        k[j].category=k[j+1].category;
                        k[j].amount=k[j+1].amount;
                    }
                    flagc--;
                }
            }
        }                                          //�������
        mainprint();                               //������Ĵ�ӡ
        scanf("%d",&k2);
        switch(k2)
        {
        case 1:
            input();
            printf("��ת��");
            Sleep(500);                            //��ʱ
            printf(".");
            Sleep(500);                            //��ʱ
            printf(".");
            Sleep(500);                            //��ʱ
            printf(".\n");
            system("cls");                         //����
            break;
        case 2:
            output();
            printf("��ת��");
            Sleep(500);                            //��ʱ
            printf(".");
            Sleep(500);                            //��ʱ
            printf(".");
            Sleep(500);                            //��ʱ
            printf(".\n");
            system("cls");                         //����
            break;
        case 3:
            manage();
            printf("��ת��");
            Sleep(500);                            //��ʱ
            printf(".");
            Sleep(500);                            //��ʱ
            printf(".");
            Sleep(500);                            //��ʱ
            printf(".\n");
            system("cls");                         //����
            break;
        case 4:
            printf("��ѯ����Ŀ¼\n");
            printf("1.����Ʒ���Ʋ�ѯ\n");
            printf("2.�����ʱ���ѯ\n");
            printf("���������ָ��(1~2):");
            scanf("%d",&k3);
            switch(k3)
            {
            case 1:
                searching1();
                break;
            case 2:
                searching2();
                break;
            }
            printf("��ת��");
            Sleep(500);                            //��ʱ
            printf(".");
            Sleep(500);                            //��ʱ
            printf(".");
            Sleep(500);                            //��ʱ
            printf(".\n");
            system("cls");                         //����
            break;
        case 5:
            if(xx2==0)
            {
                printf("��û�пɴ����վ���ţ�\n");
            }
            else
            {
                printf("�������»��ﲻ��100����Ҫ����!\n");         //������Ҫ�����Ļ�Ʒ
                for(i=0 ; i<flag3 ; i++)
                {
                    if(goo[i].amount<100)
                    {
                        printf("%-10s%-10d\n",goo[i].a,goo[i].amount);
                    }
                }
                printf("��ת�밴y\n");
                while(1)
                {
                    if(getchar()=='y')
                    {
                        break;
                    }
                }
            }
            printf("��ת��");
            Sleep(500);                            //��ʱ
            printf(".");
            Sleep(500);                            //��ʱ
            printf(".");
            Sleep(500);                            //��ʱ
            printf(".\n");
            system("cls");                         //����
            break;
        case 6:
            goto exitl;
        }
    }
exitl:
    outputx();
    return 0;
}

void managerlogin()    //����Ա��½
{
    flagm=0;
    int key1,key2;
    char o[50]="f:\\data\\";
    char u[50]=".txt";
    p=new char[12];
    getchar();
    printf("�������������û���:");
    gets(p);
    strcat(o,p);
    strcat(o,u);                                //ƴ�ӳ��û��˺����뱣��·��
    FILE *fp;
    fp = fopen(o,"r");
    if(fp == 0)
    {
        printf("���˺�Ϊ���˺ţ�\n");
        flagm=1;
        printf("��ת��");
        Sleep(500);
        printf(".");
        Sleep(500);
        printf(".");
        Sleep(500);
        printf(".\n");
        system("cls");
        goto exit2;
    }
    fscanf(fp,"%d",&key2);
    fclose(fp);
    while(1)
    {
        printf("��������������:");
        scanf("%d",&key1);
        if(key1==key2)
        {
            break;
        }
        else
        {
            printf("���벻ƥ�䣡\n");
        }
    }
exit2:
    ;
}

void managerregister() //����Աע��
{
    int key1,key2;
    char o[50]="f:\\data\\";
    char u[50]=".txt";
    p=new char[12];
    printf("�����������û�����(ֻ��Ϊ���ֺ���ĸ�����)");
    getchar();
    gets(p);
    while(1)
    {
        printf("��������������:(��ǰֻ��Ϊ����)");
        scanf("%d",&key1);
        printf("��ȷ����������:");
        scanf("%d",&key2);
        if(key1==key2)
        {
            break;
        }
        else
        {
            printf("�������벻һ�£����������룡\n");
        }
    }
    strcat(o,p);
    strcat(o,u);                                   //ƴ�ӳ��û��˺����뱣��·��
    FILE *fp;
    fp = fopen(o,"w");
    if(fp==0)
    {
        printf("file error\n");
        exit(1);
    }
    fprintf(fp , "%d" , key1 );
    fclose(fp);
    printf("ע����ɣ�\n");
    flagr=1;
    Sleep(10000);
    system("cls");
}

void manageprint()    //��½�������
{
    printf("���¼���Ĺ���Ա�˻�\n");
    printf("1.�����˻���½ϵͳ\n");
    printf("2.�һ�û���˻�������Ҫע��\n");
    printf("3.�˳�����\n");
    printf("���������ָ��(1~3):");
}

void mainprint()      //���������
{
    int i;
    for(i=0 ; i<flag3 ; i++)
    {
        if(goo[i].amount<100)
        {
            xx1++;
        }
    }
    printf("��ӭ����Ա%s                 ����%d��վ���ţ�\n",p,xx1);
    xx2=xx1;
    xx1=0;
    printf("�ֿ����ϵͳ(1.0��ʼ��)\n");
    printf("=====================\n");
    printf("1.��Ʒ���\n");
    printf("2.��Ʒ����\n");
    printf("3.������\n");
    printf("4.��ѯ���\n");
    printf("5.����վ����\n");
    printf("6.���沢�˳���\n");
    printf("���������ָ��(1~6):");
}

void input()         //��⹦��
{
    g[flag1].a=new char[10];
    printf("����������Ҫ������Ʒ������:");
    scanf("%s",g[flag1].a);
    printf("�����������Ʒ�����ʱ��:(��ʽΪxxxx(��)xx(��)xx(��)xx(ʱ)xx(��))");
    scanf("%4d%2d%2d%2d%2d",&g[flag1].year,&g[flag1].month,&g[flag1].day,&g[flag1].hour,&g[flag1].minute);
    printf("�����������Ʒ���������:");
    scanf("%d",&g[flag1].amount);
    printf("�����������Ʒ�����۸�:");
    scanf("%d",&g[flag1].price);
    printf("�����������Ʒ���������:");
    g[flag1].category=new char[10];
    scanf("%s",g[flag1].category);
    flag1++;
    printf("�����ɣ�");
    Sleep(10000);
}

void output()        //���⹦��
{
    int i,fll=0,t;
    go[flag2].a=new char[10];
    while(1)
    {
        printf("����������Ҫ�������Ʒ������:");
        scanf("%s",go[flag2].a);
        for(i=0 ; i<flag3 ; i++)
        {
            if(strcmp(go[flag2].a,goo[i].a)==0)
            {
                fll=1;
                t=i;
            }
        }
        if(fll==0)
        {
            printf("���Ĳֿ���û�д˻��");
        }
        if(fll==1)
        {
            break;
        }
    }
    printf("�����������Ʒ�ĳ���ʱ��:(��ʽΪxxxx(��)xx(��)xx(��)xx(ʱ)xx(��))");
    scanf("%4d%2d%2d%2d%2d",&go[flag2].year,&go[flag2].month,&go[flag2].day,&go[flag2].hour,&go[flag2].minute);
    while(1)
    {
        printf("�����������Ʒ�ĳ�������:");
        scanf("%d",&go[flag2].amount);
        if(go[flag2].amount>goo[t].amount)
        {
            printf("�ֿ���û����ô��Ĵ�����");
        }
        else
        {
            break;
        }
    }
    printf("�����������Ʒ�ĳ���۸�:");
    scanf("%d",&go[flag2].price);
    printf("�����������Ʒ�ĳ�������:");
    go[flag2].category=new char[10];
    scanf("%s",go[flag2].category);
    flag2++;
    printf("������ɣ�");
}

void manage()       //������
{
    int i;
    printf("��Ʒ��:\n");
    for(i=0 ; i<flag3 ; i++)
    {
        if(goo[i].amount!=0)
        {
            printf("%-10s",goo[i].a);
            printf("%-5d\n",goo[i].amount);
        }
    }
    printf("�ܼ���:\n");
    for(i=0 ; i<flagc ; i++)
    {
        if(k[i].amount!=0)
        {
            printf("%-10s",k[i].category);
            printf("%-5d\n",k[i].amount);
        }
    }
    for(i=0 ; i<flag3 ; i++)
    printf("��y�ص���ҳ��");
    while(1)
    {
        if(getchar()=='y')
        {
            break;
        }
    }
}

void searching1()     //��Ʒ���Ʋ�ѯ
{
    int i,flagtt=0;
    char *m;
    m=new char[15];
    while(1)
    {
        printf("��������Ҫ���ҵĲ�Ʒ����:");
        scanf("%s",m);
        for(i=0 ; i<flag1 ; i++)
        {
            if(strcmp(m,g[i].a)==0)
            {
                flagtt=1;
                printf("����¼:\n");
                printf("��Ʒ����  ��Ʒ����  ���۸�  ��Ʒ����   ���ʱ�� \n");
                break;
            }
        }
        for(i=0 ; i<flag1 ; i++)
        {
            if(strcmp(m,g[i].a)==0)
            {
                printf("%-10s%-10d%-10d%-10s %d��%d��%d��%dʱ%d��\n",g[i].a,g[i].amount,g[i].price,g[i].category,g[i].year,g[i].month,g[i].day,g[i].hour,g[i].minute);
            }
        }
        for(i=0 ; i<flag2 ; i++)
        {
            if(strcmp(m,go[i].a)==0)
            {
                flagtt=1;
                printf("�����¼:\n");
                printf("��Ʒ����  ��Ʒ����  ����۸�  ��Ʒ����   ����ʱ�� \n");
                break;
            }
        }
        for(i=0 ; i<flag2 ; i++)
        {
            if(strcmp(m,go[i].a)==0)
            {
                printf("%-10s%-10d%-10d%-10s %d��%d��%d��%dʱ%d��\n",go[i].a,go[i].amount,go[i].price,go[i].category,go[i].year,go[i].month,go[i].day,go[i].hour,go[i].minute);
            }
        }
        if(flagtt==0)
        {
            printf("���������������Ʒ���Ƿ��������룿y/n\n");
            getchar();
            if(getchar()=='n')
            {
                break;
            }
            else if(getchar()=='y')
            {
                ;
            }
        }
        else
        {
            break;
        }
    }
    printf("��y�ص���ҳ��");
    while(1)
    {
        if(getchar()=='y')
        {
            break;
        }
    }
}

void searching2()     //��Ʒ���ʱ���ѯ
{
    int k,k1,k2,k3,k4,k5,i,flagxx=0;
    printf("������Ҫ��ȷ��ʲôʱ���ѯ��\n");
    printf("1.��\n");
    printf("2.��\n");
    printf("3.��\n");
    printf("4.��ȷʱ���ѯ(��Ҫ׼ȷ����������ʱ��)\n");
    printf("���������ָ��(1~4):");
    scanf("%d",&k);
    switch(k)
    {
    case 1:
        while(1)
        {
            printf("��������Ҫ��ѯ������:");
            scanf("%d",&k1);
            for(i=0 ; i<flag1 ; i++)
            {
                if(g[i].year==k1)
                {
                    flagxx=1;
                    printf("����¼:\n");
                    printf("��Ʒ����  ��Ʒ����  ���۸�  ��Ʒ����   ���ʱ�� \n");
                    break;
                }
            }
            for(i=0 ; i<flag1 ; i++)
            {
                if(g[i].year==k1)
                {
                    printf("%-10s%-10d%-10d%-10s %d��%d��%d��%dʱ%d��\n",g[i].a,g[i].amount,g[i].price,g[i].category,g[i].year,g[i].month,g[i].day,g[i].hour,g[i].minute);
                }
            }
            for(i=0 ; i<flag2 ; i++)
            {
                if(go[i].year==k1)
                {
                    flagxx=1;
                    printf("�����¼:\n");
                    printf("��Ʒ����  ��Ʒ����  ����۸�  ��Ʒ����   ����ʱ�� \n");
                    break;
                }
            }
            for(i=0 ; i<flag2 ; i++)
            {
                if(go[i].year==k1)
                {
                    printf("%-10s%-10d%-10d%-10s %d��%d��%d��%dʱ%d��\n",go[i].a,go[i].amount,go[i].price,go[i].category,go[i].year,go[i].month,go[i].day,go[i].hour,go[i].minute);
                }
            }
            if(flagxx==0)
            {
                printf("���������������Ʒ���Ƿ��������룿y/n\n");
                getchar();
                if(getchar()=='n')
                {
                    break;
                }
                else if(getchar()=='y')
                {
                    ;
                }
            }
            else
            {
                break;
            }
        }
        break;
    case 2:
        while(1)
        {
            printf("��������Ҫ��ѯ������:");
            scanf("%4d%2d",&k1,&k2);
            for(i=0 ; i<flag1 ; i++)
            {
                if(g[i].month==k2&&g[i].year==k1)
                {
                    flagxx=1;
                    printf("����¼:\n");
                    printf("��Ʒ����  ��Ʒ����  ���۸�  ��Ʒ����   ���ʱ�� \n");
                    break;
                }
            }
            for(i=0 ; i<flag1 ; i++)
            {
                if(g[i].month==k2&&g[i].year==k1)
                {
                    printf("%-10s%-10d%-10d%-10s %d��%d��%d��%dʱ%d��\n",g[i].a,g[i].amount,g[i].price,g[i].category,g[i].year,g[i].month,g[i].day,g[i].hour,g[i].minute);
                }
            }
            for(i=0 ; i<flag2 ; i++)
            {
                if(go[i].month==k2&&go[i].year==k1)
                {
                    flagxx=1;
                    printf("�����¼:\n");
                    printf("��Ʒ����  ��Ʒ����  ����۸�  ��Ʒ����   ����ʱ�� \n");
                    break;
                }
            }
            for(i=0 ; i<flag2 ; i++)
            {
                if(go[i].month==k2&&go[i].year==k1)
                {
                    printf("%-10s%-10d%-10d%-10s %d��%d��%d��%dʱ%d��\n",go[i].a,go[i].amount,go[i].price,go[i].category,go[i].year,go[i].month,go[i].day,go[i].hour,go[i].minute);
                }
            }
            if(flagxx==0)
            {
                printf("���������������Ʒ���Ƿ��������룿y/n\n");
                getchar();
                if(getchar()=='n')
                {
                    break;
                }
                else if(getchar()=='y')
                {
                    ;
                }
            }
            else
            {
                break;
            }
        }
        break;
    case 3:
        while(1)
        {
            printf("��������Ҫ��ѯ������:");
            scanf("%4d%2d%2d",&k1,&k2,&k3);
            for(i=0 ; i<flag1 ; i++)
            {
                if(g[i].month==k2&&g[i].year==k1&&g[i].day==k3)
                {
                    flagxx=1;
                    printf("����¼:\n");
                    printf("��Ʒ����  ��Ʒ����  ���۸�  ��Ʒ����   ���ʱ�� \n");
                    break;
                }
            }
            for(i=0 ; i<flag1 ; i++)
            {
                if(g[i].month==k2&&g[i].year==k1&&g[i].day==k3)
                {
                    printf("%-10s%-10d%-10d%-10s %d��%d��%d��%dʱ%d��\n",g[i].a,g[i].amount,g[i].price,g[i].category,g[i].year,g[i].month,g[i].day,g[i].hour,g[i].minute);
                }
            }
            for(i=0 ; i<flag2 ; i++)
            {
                if(go[i].month==k2&&go[i].year==k1&&go[i].day==k3)
                {
                    flagxx=1;
                    printf("�����¼:\n");
                    printf("��Ʒ����  ��Ʒ����  ����۸�  ��Ʒ����   ����ʱ�� \n");
                    break;
                }
            }
            for(i=0 ; i<flag2 ; i++)
            {
                if(go[i].month==k2&&go[i].year==k1&&go[i].day==k3)
                {
                    printf("%-10s%-10d%-10d%-10s %d��%d��%d��%dʱ%d��\n",go[i].a,go[i].amount,go[i].price,go[i].category,go[i].year,go[i].month,go[i].day,go[i].hour,go[i].minute);
                }
            }
            if(flagxx==0)
            {
                printf("���������������Ʒ���Ƿ��������룿y/n\n");
                getchar();
                if(getchar()=='n')
                {
                    break;
                }
                else if(getchar()=='y')
                {
                    ;
                }
            }
            else
            {
                break;
            }
        }
        break;
    case 4:
        while(1)
        {
            printf("��������Ҫ��ѯ������:");
            scanf("%4d%2d%2d%2d%2d",&k1,&k2,&k3,&k4,&k5);
            for(i=0 ; i<flag1 ; i++)
            {
                if(g[i].year==k1&&g[i].month==k2&&g[i].day==k3&&g[i].hour==k4&&g[i].minute==k5)
                {
                    flagxx=1;
                    printf("����¼:\n");
                    printf("��Ʒ����  ��Ʒ����  ���۸�  ��Ʒ����   ���ʱ�� \n");
                    break;
                }
            }
            for(i=0 ; i<flag1 ; i++)
            {
                if(g[i].year==k1&&g[i].month==k2&&g[i].day==k3&&g[i].hour==k4&&g[i].minute==k5)
                {
                    printf("%-10s%-10d%-10d%-10s %d��%d��%d��%dʱ%d��\n",g[i].a,g[i].amount,g[i].price,g[i].category,g[i].year,g[i].month,g[i].day,g[i].hour,g[i].minute);
                    break;
                }
            }
            for(i=0 ; i<flag2 ; i++)
            {
                if(go[i].year==k1&&go[i].month==k2&&go[i].day==k3&&go[i].hour==k4&&go[i].minute==k5)
                {
                    flagxx=1;
                    printf("�����¼:\n");
                    printf("��Ʒ����  ��Ʒ����  ����۸�  ��Ʒ����   ����ʱ�� \n");
                    break;
                }
            }
            for(i=0 ; i<flag2 ; i++)
            {
                if(go[i].year==k1&&go[i].month==k2&&go[i].day==k3&&go[i].hour==k4&&go[i].minute==k5)
                {
                    printf("%-10s%-10d%-10d%-10s %d��%d��%d��%dʱ%d��\n",go[i].a,go[i].amount,go[i].price,go[i].category,go[i].year,go[i].month,go[i].day,go[i].hour,go[i].minute);
                }
            }
            if(flagxx==0)
            {
                printf("���������������Ʒ���Ƿ��������룿y/n\n");
                getchar();
                if(getchar()=='n')
                {
                    break;
                }
                else if(getchar()=='y')
                {
                    ;
                }
            }
            else
            {
                break;
            }
        }
        break;
    }
    printf("��y�ص���ҳ��");
    while(1)
    {
        if(getchar()=='y')

        {
            break;
        }
    }
}

void outputx()   //����Ϣȫ������
{
    int i;
    char o[50]="f:\\data\\";
    char u[50]="data.txt";
    strcat(o,p);
    strcat(o,u);
    FILE *fp;
    fp = fopen(o,"w");
    if(fp==0)
    {
        printf("file error\n");
        exit(1);
    }
    fprintf(fp,"%d\n",flag1);
    for(i=0 ; i<flag1 ; i++)
    {
        fprintf(fp,"%s\n",g[i].a);                    //���������Ϣ
        fprintf(fp,"%d\n",g[i].amount);
        fprintf(fp,"%d\n",g[i].price);
        fprintf(fp,"%s\n",g[i].category);
        fprintf(fp,"%d\n",g[i].year);
        fprintf(fp,"%d\n",g[i].month);
        fprintf(fp,"%d\n",g[i].day);
        fprintf(fp,"%d\n",g[i].hour);
        fprintf(fp,"%d\n",g[i].minute);
    }
    fprintf(fp,"%d\n",flag2);
    for(i=0 ; i<flag2 ; i++)
    {
        fprintf(fp,"%s\n",go[i].a);                  //����������Ϣ
        fprintf(fp,"%d\n",go[i].amount);
        fprintf(fp,"%d\n",go[i].price);
        fprintf(fp,"%s\n",go[i].category);
        fprintf(fp,"%d\n",go[i].year);
        fprintf(fp,"%d\n",go[i].month);
        fprintf(fp,"%d\n",go[i].day);
        fprintf(fp,"%d\n",go[i].hour);
        fprintf(fp,"%d\n",go[i].minute);
    }
    fclose(fp);
    printf("������ɣ�\n");
    Sleep(1000);
}

void inputx()   //����Ϣȫ������
{
    int i=0,j,t;
    char o[50]="f:\\data\\";
    char u[50]="data.txt";
    strcat(o,p);
    strcat(o,u);
    FILE *fp;
    fp = fopen(o,"r");
    if(fp)
    {
        printf("�����ʶ���ļ��ѵ��룡\n");
    }
    if(!fp)
    {
        goto sss;
    }
    fscanf(fp,"%d\n",&t);
    for(i=0 ; i<t ; i++)
    {
        g[i].a=new char[10];                         //���������Ϣ
        fgets(g[i].a,10,fp);
        fscanf(fp,"%d\n",&g[i].amount);
        fscanf(fp,"%d\n",&g[i].price);
        g[i].category=new char[10];
        fgets(g[i].category,10,fp);
        fscanf(fp,"%d\n",&g[i].year);
        fscanf(fp,"%d\n",&g[i].month);
        fscanf(fp,"%d\n",&g[i].day);
        fscanf(fp,"%d\n",&g[i].hour);
        fscanf(fp,"%d\n",&g[i].minute);
        flag1++;
        for(j=0 ; j<10 ; j++)
        {
            if(!(g[i].a[j]<='z'&&g[i].a[j]>='a'))
            {
                g[i].a[j]='\0';
                break;
            }
        }
        for(j=0 ; j<10 ; j++)
        {
            if(!(g[i].category[j]<='z'&&g[i].category[j]>='a'))
            {
                g[i].category[j]='\0';
                break;
            }
        }
    }
    fscanf(fp,"%d\n",&t);
    for(i=0 ; i<t ; i++)
    {
        go[i].a=new char[10];                      //���������Ϣ
        fgets(go[i].a,10,fp);
        fscanf(fp,"%d\n",&go[i].amount);
        fscanf(fp,"%d\n",&go[i].price);
        go[i].category=new char[10];
        fgets(go[i].category,10,fp);
        fscanf(fp,"%d\n",&go[i].year);
        fscanf(fp,"%d\n",&go[i].month);
        fscanf(fp,"%d\n",&go[i].day);
        fscanf(fp,"%d\n",&go[i].hour);
        fscanf(fp,"%d\n",&go[i].minute);
        flag2++;
        for(j=0 ; j<10 ; j++)
        {
            if(!(go[i].a[j]<='z'&&go[i].a[j]>='a'))
            {
                go[i].a[j]='\0';
                break;
            }
        }
        for(j=0 ; j<10 ; j++)
        {
            if(!(go[i].category[j]<='z'&&go[i].category[j]>='a'))
            {
                go[i].category[j]='\0';
                break;
            }
        }
    }
    fclose(fp);
    sss:;
}
