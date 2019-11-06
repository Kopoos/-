#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=510;
const int INF=100000000;

struct station{
    double Pi;     //the unit gas price
    double Di;     //the distance between the station and Hangzhou
}st[maxn];

bool cmp(station a,station b)       //按距离从小到大进行排序
{
    return a.Di<b.Di;
}

int main()
{  
    double Cmax,D,Davg;
    int N;
    scanf("%lf %lf %lf %d",&Cmax,&D,&Davg,&N);      
    //读取邮箱的最大容量，杭州到目的城市的距离，消耗单位的油能跑的距离，加油站的数量
    for(int i=0;i<N;i++)
    {
        scanf("%lf %lf",&st[i].Pi,&st[i].Di);
    }
    st[N].Pi=0;     //设置终点的价格为0
    st[N].Di=D;     //设置终点距离为D
    sort(st,st+N,cmp);      //排序
    if(st[0].Di!=0){        //如果排序的第一个加油站的距离不是0，说明无法前进
        printf("The maximum travel distance = 0.00\n");
    }else{
        int now=0;          //当前所处的加油站编号
        double ans=0,nowtank=0,Max=Cmax*Davg;       //总花费、当前油量以及满油行驶距离
        while(now<N){       //从每次循环将选出第一个油价低于当前油价的加油站
            //如果没有低于当前价格的，则选出价格最低的那个
            int k=-1;                   //最低油价的编号
            double priceMin=INF;        //最低油价
            for(int i=now+1;i<=N&&st[i].Di-st[now].Di<=Max;i++){
                if(st[i].Pi<priceMin){      //如果比当前最低油价要低
                    priceMin=st[i].Pi;      //更新最低油价
                    k=i;
                    if(priceMin<st[now].Pi)
                    {
                        break;
                    }
                }
            }
            if(k==-1)break;     //满油状态下找不到加油站，退出循环输出结果
            //下面为能找到可到达的加油站k,计算转移花费
            //need 为从now到k需要的油量
            double need=(st[k].Di-st[now].Di)/Davg;
            if(priceMin<st[now].Pi){    //如果加油站当前的油价高于加油站k的油价
                //只需要买到到达k加油站的油
                if(nowtank<need){       //如果当前油量不足need
                    ans+=(need-nowtank)*st[now].Pi;     //补足need
                    nowtank=0;          //到达加油站k后邮箱的油量为0
                }else{      //如果当前油量超过need
                    nowtank-=need;      //直接到达加油站k
                }
            }else{     //如果加油站k的油价高于当前油价,则需要加满
                ans+=(Cmax-nowtank)*st[now].Pi;     //将油箱加满
                nowtank=Cmax-need;
            }
            now=k;      //到达加油站k,进入下一层循环
        }
        if(now==N){     //能到达终点
            printf("%.2f\n",ans);
        }else{          //不能到达终点
            printf("The maximum travel distance = %.2f\n",st[now].Di+Max);
        }
    }
    return 0;
}
