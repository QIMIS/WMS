#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
//结构声明
struct good              //出入库的结构体
{
    char *a;                            //出入库产品的名称
    int year,month,day,hour,minute;     //出入库产品的入库年月日时分
    int amount;                         //出入库产品的数量
    int price;                          //出入库产品的价格
    char *category;                     //出入库产品的种类
};

struct goood             //库存的结构体
{
    char *a;                            //库存中产品的名称
    int amount;                         //库存中产品的数量
};

struct categorying
{
    char *category;                     //分类中产品的分类名
    int amount;                         //该分类下产品的数量
};

//静态变量声明
int flagm;               //观察是否需要重新输入账户

good g[1000];            //用于存放商品入库信息

good go[1000];           //用于存放商品出库信息

goood goo[1000];         //用于存放商品库存信息

categorying k[1000];     //用于输出类库存

int flag1=0;             //此整型为目前g[1000]数组的最后一个有值的

int flag2=0;             //此整型为目前go[1000]数组的最后一个有值的

int flag3=0;             //此整型为目前goo[1000]数组的最后一个有值的

char *p;                 //管理员名称

int xx1=0,xx2=0;         //提醒功能

int flagr=0;             //观察是否有注册账户

int flagc=0;            //观测种类

//函数声明
void input();            //产品入库功能

void output();           //产品出库功能

void manage();           //库存管理功能

void searching1();       //按产品名称查询

void searching2();       //按入库时间查询

void managerlogin();     //管理员登陆

void managerregister();  //管理员注册

void manageprint();      //输出登录界面

void mainprint();        //输出主界面

void outputx();           //导出数据

void inputx();            //导入数据

int main()               //主函数
{
    int k1,k2,k3;
    printf("仓库管理系统启动中");
    Sleep(500);                                      //延时
    printf(".");
    Sleep(500);                                      //延时
    printf(".");
    Sleep(500);                                      //延时
    printf(".\n");
    system("cls");                                   //清屏
    while(1)
    {
sk:                                                  //用户登录界面的开始
        manageprint();
        scanf("%d",&k1);
        switch(k1)                                   //用户指令赋值给k1
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
    }                                                //用户登录界面结束，跳入主界面
exit1:
    system("cls");
    if(flagr==0)                                     //载入旧账号data文件里的信息
    {
        inputx();
    }
    while(1)                                         //主界面无限循环
    {
        int i,j,fll=0;                               //主界面打印之前计算库存和分类库存
        for(i=0 ; i<flag3 ; i++)                     //库存归零
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
        }                                                              //以上是计算库存，以下是计算分类库存
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
        }                                          //计算完毕
        mainprint();                               //主界面的打印
        scanf("%d",&k2);
        switch(k2)
        {
        case 1:
            input();
            printf("跳转中");
            Sleep(500);                            //延时
            printf(".");
            Sleep(500);                            //延时
            printf(".");
            Sleep(500);                            //延时
            printf(".\n");
            system("cls");                         //清屏
            break;
        case 2:
            output();
            printf("跳转中");
            Sleep(500);                            //延时
            printf(".");
            Sleep(500);                            //延时
            printf(".");
            Sleep(500);                            //延时
            printf(".\n");
            system("cls");                         //清屏
            break;
        case 3:
            manage();
            printf("跳转中");
            Sleep(500);                            //延时
            printf(".");
            Sleep(500);                            //延时
            printf(".");
            Sleep(500);                            //延时
            printf(".\n");
            system("cls");                         //清屏
            break;
        case 4:
            printf("查询功能目录\n");
            printf("1.按产品名称查询\n");
            printf("2.按入库时间查询\n");
            printf("请键入您的指令(1~2):");
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
            printf("跳转中");
            Sleep(500);                            //延时
            printf(".");
            Sleep(500);                            //延时
            printf(".");
            Sleep(500);                            //延时
            printf(".\n");
            system("cls");                         //清屏
            break;
        case 5:
            if(xx2==0)
            {
                printf("您没有可处理的站内信！\n");
            }
            else
            {
                printf("您有以下货物不满100，需要进货!\n");         //计算需要补货的货品
                for(i=0 ; i<flag3 ; i++)
                {
                    if(goo[i].amount<100)
                    {
                        printf("%-10s%-10d\n",goo[i].a,goo[i].amount);
                    }
                }
                printf("跳转请按y\n");
                while(1)
                {
                    if(getchar()=='y')
                    {
                        break;
                    }
                }
            }
            printf("跳转中");
            Sleep(500);                            //延时
            printf(".");
            Sleep(500);                            //延时
            printf(".");
            Sleep(500);                            //延时
            printf(".\n");
            system("cls");                         //清屏
            break;
        case 6:
            goto exitl;
        }
    }
exitl:
    outputx();
    return 0;
}

void managerlogin()    //管理员登陆
{
    flagm=0;
    int key1,key2;
    char o[50]="f:\\data\\";
    char u[50]=".txt";
    p=new char[12];
    getchar();
    printf("请您输入您的用户名:");
    gets(p);
    strcat(o,p);
    strcat(o,u);                                //拼接出用户账号密码保存路径
    FILE *fp;
    fp = fopen(o,"r");
    if(fp == 0)
    {
        printf("此账号为空账号！\n");
        flagm=1;
        printf("跳转中");
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
        printf("请输入您的密码:");
        scanf("%d",&key1);
        if(key1==key2)
        {
            break;
        }
        else
        {
            printf("密码不匹配！\n");
        }
    }
exit2:
    ;
}

void managerregister() //管理员注册
{
    int key1,key2;
    char o[50]="f:\\data\\";
    char u[50]=".txt";
    p=new char[12];
    printf("请输入您的用户名：(只能为数字和字母的组合)");
    getchar();
    gets(p);
    while(1)
    {
        printf("请输入您的密码:(当前只能为数字)");
        scanf("%d",&key1);
        printf("请确定您的密码:");
        scanf("%d",&key2);
        if(key1==key2)
        {
            break;
        }
        else
        {
            printf("两次密码不一致！请重新输入！\n");
        }
    }
    strcat(o,p);
    strcat(o,u);                                   //拼接出用户账号密码保存路径
    FILE *fp;
    fp = fopen(o,"w");
    if(fp==0)
    {
        printf("file error\n");
        exit(1);
    }
    fprintf(fp , "%d" , key1 );
    fclose(fp);
    printf("注册完成！\n");
    flagr=1;
    Sleep(10000);
    system("cls");
}

void manageprint()    //登陆界面输出
{
    printf("请登录您的管理员账户\n");
    printf("1.已有账户登陆系统\n");
    printf("2.我还没有账户，我需要注册\n");
    printf("3.退出程序\n");
    printf("请键入您的指令(1~3):");
}

void mainprint()      //主界面输出
{
    int i;
    for(i=0 ; i<flag3 ; i++)
    {
        if(goo[i].amount<100)
        {
            xx1++;
        }
    }
    printf("欢迎管理员%s                 您有%d条站内信！\n",p,xx1);
    xx2=xx1;
    xx1=0;
    printf("仓库管理系统(1.0初始版)\n");
    printf("=====================\n");
    printf("1.产品入库\n");
    printf("2.产品出库\n");
    printf("3.库存管理\n");
    printf("4.查询库存\n");
    printf("5.处理站内信\n");
    printf("6.保存并退出！\n");
    printf("请键入您的指令(1~6):");
}

void input()         //入库功能
{
    g[flag1].a=new char[10];
    printf("请您输入您要入库的物品的名称:");
    scanf("%s",g[flag1].a);
    printf("请您输入此物品的入库时间:(格式为xxxx(年)xx(月)xx(日)xx(时)xx(分))");
    scanf("%4d%2d%2d%2d%2d",&g[flag1].year,&g[flag1].month,&g[flag1].day,&g[flag1].hour,&g[flag1].minute);
    printf("请您输入此物品的入库数量:");
    scanf("%d",&g[flag1].amount);
    printf("请您输入此物品的入库价格:");
    scanf("%d",&g[flag1].price);
    printf("请您输入此物品的入库种类:");
    g[flag1].category=new char[10];
    scanf("%s",g[flag1].category);
    flag1++;
    printf("入库完成！");
    Sleep(10000);
}

void output()        //出库功能
{
    int i,fll=0,t;
    go[flag2].a=new char[10];
    while(1)
    {
        printf("请您输入您要出库的物品的名称:");
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
            printf("您的仓库中没有此货物！");
        }
        if(fll==1)
        {
            break;
        }
    }
    printf("请您输入此物品的出库时间:(格式为xxxx(年)xx(月)xx(日)xx(时)xx(分))");
    scanf("%4d%2d%2d%2d%2d",&go[flag2].year,&go[flag2].month,&go[flag2].day,&go[flag2].hour,&go[flag2].minute);
    while(1)
    {
        printf("请您输入此物品的出库数量:");
        scanf("%d",&go[flag2].amount);
        if(go[flag2].amount>goo[t].amount)
        {
            printf("仓库中没有那么多的此类货物！");
        }
        else
        {
            break;
        }
    }
    printf("请您输入此物品的出库价格:");
    scanf("%d",&go[flag2].price);
    printf("请您输入此物品的出库种类:");
    go[flag2].category=new char[10];
    scanf("%s",go[flag2].category);
    flag2++;
    printf("出库完成！");
}

void manage()       //库存管理
{
    int i;
    printf("商品有:\n");
    for(i=0 ; i<flag3 ; i++)
    {
        if(goo[i].amount!=0)
        {
            printf("%-10s",goo[i].a);
            printf("%-5d\n",goo[i].amount);
        }
    }
    printf("总计有:\n");
    for(i=0 ; i<flagc ; i++)
    {
        if(k[i].amount!=0)
        {
            printf("%-10s",k[i].category);
            printf("%-5d\n",k[i].amount);
        }
    }
    for(i=0 ; i<flag3 ; i++)
    printf("按y回到主页面");
    while(1)
    {
        if(getchar()=='y')
        {
            break;
        }
    }
}

void searching1()     //产品名称查询
{
    int i,flagtt=0;
    char *m;
    m=new char[15];
    while(1)
    {
        printf("请输入您要查找的产品名称:");
        scanf("%s",m);
        for(i=0 ; i<flag1 ; i++)
        {
            if(strcmp(m,g[i].a)==0)
            {
                flagtt=1;
                printf("入库记录:\n");
                printf("商品名称  商品数量  入库价格  商品种类   入库时间 \n");
                break;
            }
        }
        for(i=0 ; i<flag1 ; i++)
        {
            if(strcmp(m,g[i].a)==0)
            {
                printf("%-10s%-10d%-10d%-10s %d年%d月%d日%d时%d分\n",g[i].a,g[i].amount,g[i].price,g[i].category,g[i].year,g[i].month,g[i].day,g[i].hour,g[i].minute);
            }
        }
        for(i=0 ; i<flag2 ; i++)
        {
            if(strcmp(m,go[i].a)==0)
            {
                flagtt=1;
                printf("出库记录:\n");
                printf("商品名称  商品数量  出库价格  商品种类   出库时间 \n");
                break;
            }
        }
        for(i=0 ; i<flag2 ; i++)
        {
            if(strcmp(m,go[i].a)==0)
            {
                printf("%-10s%-10d%-10d%-10s %d年%d月%d日%d时%d分\n",go[i].a,go[i].amount,go[i].price,go[i].category,go[i].year,go[i].month,go[i].day,go[i].hour,go[i].minute);
            }
        }
        if(flagtt==0)
        {
            printf("不存在您输入的物品，是否重新输入？y/n\n");
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
    printf("按y回到主页面");
    while(1)
    {
        if(getchar()=='y')
        {
            break;
        }
    }
}

void searching2()     //产品入库时间查询
{
    int k,k1,k2,k3,k4,k5,i,flagxx=0;
    printf("请问您要精确到什么时间查询？\n");
    printf("1.年\n");
    printf("2.月\n");
    printf("3.日\n");
    printf("4.精确时间查询(需要准确输入年月日时分)\n");
    printf("请键入您的指令(1~4):");
    scanf("%d",&k);
    switch(k)
    {
    case 1:
        while(1)
        {
            printf("请输入您要查询的数据:");
            scanf("%d",&k1);
            for(i=0 ; i<flag1 ; i++)
            {
                if(g[i].year==k1)
                {
                    flagxx=1;
                    printf("入库记录:\n");
                    printf("商品名称  商品数量  入库价格  商品种类   入库时间 \n");
                    break;
                }
            }
            for(i=0 ; i<flag1 ; i++)
            {
                if(g[i].year==k1)
                {
                    printf("%-10s%-10d%-10d%-10s %d年%d月%d日%d时%d分\n",g[i].a,g[i].amount,g[i].price,g[i].category,g[i].year,g[i].month,g[i].day,g[i].hour,g[i].minute);
                }
            }
            for(i=0 ; i<flag2 ; i++)
            {
                if(go[i].year==k1)
                {
                    flagxx=1;
                    printf("出库记录:\n");
                    printf("商品名称  商品数量  出库价格  商品种类   出库时间 \n");
                    break;
                }
            }
            for(i=0 ; i<flag2 ; i++)
            {
                if(go[i].year==k1)
                {
                    printf("%-10s%-10d%-10d%-10s %d年%d月%d日%d时%d分\n",go[i].a,go[i].amount,go[i].price,go[i].category,go[i].year,go[i].month,go[i].day,go[i].hour,go[i].minute);
                }
            }
            if(flagxx==0)
            {
                printf("不存在您输入的物品，是否重新输入？y/n\n");
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
            printf("请输入您要查询的数据:");
            scanf("%4d%2d",&k1,&k2);
            for(i=0 ; i<flag1 ; i++)
            {
                if(g[i].month==k2&&g[i].year==k1)
                {
                    flagxx=1;
                    printf("入库记录:\n");
                    printf("商品名称  商品数量  入库价格  商品种类   入库时间 \n");
                    break;
                }
            }
            for(i=0 ; i<flag1 ; i++)
            {
                if(g[i].month==k2&&g[i].year==k1)
                {
                    printf("%-10s%-10d%-10d%-10s %d年%d月%d日%d时%d分\n",g[i].a,g[i].amount,g[i].price,g[i].category,g[i].year,g[i].month,g[i].day,g[i].hour,g[i].minute);
                }
            }
            for(i=0 ; i<flag2 ; i++)
            {
                if(go[i].month==k2&&go[i].year==k1)
                {
                    flagxx=1;
                    printf("出库记录:\n");
                    printf("商品名称  商品数量  出库价格  商品种类   出库时间 \n");
                    break;
                }
            }
            for(i=0 ; i<flag2 ; i++)
            {
                if(go[i].month==k2&&go[i].year==k1)
                {
                    printf("%-10s%-10d%-10d%-10s %d年%d月%d日%d时%d分\n",go[i].a,go[i].amount,go[i].price,go[i].category,go[i].year,go[i].month,go[i].day,go[i].hour,go[i].minute);
                }
            }
            if(flagxx==0)
            {
                printf("不存在您输入的物品，是否重新输入？y/n\n");
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
            printf("请输入您要查询的数据:");
            scanf("%4d%2d%2d",&k1,&k2,&k3);
            for(i=0 ; i<flag1 ; i++)
            {
                if(g[i].month==k2&&g[i].year==k1&&g[i].day==k3)
                {
                    flagxx=1;
                    printf("入库记录:\n");
                    printf("商品名称  商品数量  入库价格  商品种类   入库时间 \n");
                    break;
                }
            }
            for(i=0 ; i<flag1 ; i++)
            {
                if(g[i].month==k2&&g[i].year==k1&&g[i].day==k3)
                {
                    printf("%-10s%-10d%-10d%-10s %d年%d月%d日%d时%d分\n",g[i].a,g[i].amount,g[i].price,g[i].category,g[i].year,g[i].month,g[i].day,g[i].hour,g[i].minute);
                }
            }
            for(i=0 ; i<flag2 ; i++)
            {
                if(go[i].month==k2&&go[i].year==k1&&go[i].day==k3)
                {
                    flagxx=1;
                    printf("出库记录:\n");
                    printf("商品名称  商品数量  出库价格  商品种类   出库时间 \n");
                    break;
                }
            }
            for(i=0 ; i<flag2 ; i++)
            {
                if(go[i].month==k2&&go[i].year==k1&&go[i].day==k3)
                {
                    printf("%-10s%-10d%-10d%-10s %d年%d月%d日%d时%d分\n",go[i].a,go[i].amount,go[i].price,go[i].category,go[i].year,go[i].month,go[i].day,go[i].hour,go[i].minute);
                }
            }
            if(flagxx==0)
            {
                printf("不存在您输入的物品，是否重新输入？y/n\n");
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
            printf("请输入您要查询的数据:");
            scanf("%4d%2d%2d%2d%2d",&k1,&k2,&k3,&k4,&k5);
            for(i=0 ; i<flag1 ; i++)
            {
                if(g[i].year==k1&&g[i].month==k2&&g[i].day==k3&&g[i].hour==k4&&g[i].minute==k5)
                {
                    flagxx=1;
                    printf("入库记录:\n");
                    printf("商品名称  商品数量  入库价格  商品种类   入库时间 \n");
                    break;
                }
            }
            for(i=0 ; i<flag1 ; i++)
            {
                if(g[i].year==k1&&g[i].month==k2&&g[i].day==k3&&g[i].hour==k4&&g[i].minute==k5)
                {
                    printf("%-10s%-10d%-10d%-10s %d年%d月%d日%d时%d分\n",g[i].a,g[i].amount,g[i].price,g[i].category,g[i].year,g[i].month,g[i].day,g[i].hour,g[i].minute);
                    break;
                }
            }
            for(i=0 ; i<flag2 ; i++)
            {
                if(go[i].year==k1&&go[i].month==k2&&go[i].day==k3&&go[i].hour==k4&&go[i].minute==k5)
                {
                    flagxx=1;
                    printf("出库记录:\n");
                    printf("商品名称  商品数量  出库价格  商品种类   出库时间 \n");
                    break;
                }
            }
            for(i=0 ; i<flag2 ; i++)
            {
                if(go[i].year==k1&&go[i].month==k2&&go[i].day==k3&&go[i].hour==k4&&go[i].minute==k5)
                {
                    printf("%-10s%-10d%-10d%-10s %d年%d月%d日%d时%d分\n",go[i].a,go[i].amount,go[i].price,go[i].category,go[i].year,go[i].month,go[i].day,go[i].hour,go[i].minute);
                }
            }
            if(flagxx==0)
            {
                printf("不存在您输入的物品，是否重新输入？y/n\n");
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
    printf("按y回到主页面");
    while(1)
    {
        if(getchar()=='y')

        {
            break;
        }
    }
}

void outputx()   //将信息全部导出
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
        fprintf(fp,"%s\n",g[i].a);                    //导出入库信息
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
        fprintf(fp,"%s\n",go[i].a);                  //导出出库信息
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
    printf("导出完成！\n");
    Sleep(1000);
}

void inputx()   //将信息全部导入
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
        printf("身份已识别，文件已导入！\n");
    }
    if(!fp)
    {
        goto sss;
    }
    fscanf(fp,"%d\n",&t);
    for(i=0 ; i<t ; i++)
    {
        g[i].a=new char[10];                         //导入入库信息
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
        go[i].a=new char[10];                      //导入出库信息
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
