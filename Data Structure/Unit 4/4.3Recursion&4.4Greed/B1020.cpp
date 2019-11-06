#include<cstdio>
#include<algorithm>
using namespace std;
struct mooncake
{
    double store;       //库存量
    double sell;        //总售价
    double price;       //单价
}stu[1010];

bool cmp(mooncake a,mooncake b)
{
    return a.price>b.price;
}

int main()
{   
    int N;
    double D;        //N代表月饼的种类，D代表市场的最大需求
    double max=0;
    scanf("%d %lf",&N,&D);
    for(int i=0;i<N;i++)
    {
        scanf("%lf",&stu[i].store);
    }
    for(int i=0;i<N;i++)
    {
        scanf("%lf",&stu[i].sell);
        stu[i].price=stu[i].sell/stu[i].store;      //计算单价
    }
    sort(stu,stu+N,cmp);
    for(int i=0;i<N;i++)
    {
        if(stu[i].store>=D)
        {
            max+=D*stu[i].price;
             
            break;
        }
        else {
            max+=stu[i].store*stu[i].price;
            D-=stu[i].store;

        }
    }
   printf("%.2f",max);      //这个要放在函数的外面，防止出现总需求大与存贮的情况，没有输出
    return 0;
}