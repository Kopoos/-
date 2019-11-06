#include<cstdio>
#include<algorithm>
using namespace std;
struct mooncake{
    double store;       //表示这种月饼的库存量
    double sell;        //表示这种月饼的总售价
    double price;       //表示这种月饼的单价
}cake[1010];
bool cmp(mooncake a,mooncake b)
{
    return a.price>b.price;
}
int main()
{
    int N,D;
    scanf("%d %d",&N,&D);       //N是月饼的种类，D是表示市场的最大需求
    int i=0;
    for(i=0;i<N;i++)
    {
        scanf("%lf",&cake[i].store);        //读入库存量
    }
    for(i=0;i<N;i++)
    {
        scanf("%lf",&cake[i].sell);         //读入总售价
        cake[i].price=cake[i].sell/cake[i].store;       //求出平均价格
    }
    sort(cake,cake+N,cmp);      //从大到小进行排序
    double profit=0;
    for(i=0;i<N;i++)
    {
        if(cake[i].store<=D){
            D-=cake[i].store;
            profit+=cake[i].sell;
        }
        else{
            profit+=D*cake[i].price;
            break;
        }
    }
    printf("%.2f\n",profit);
    return 0;
}
