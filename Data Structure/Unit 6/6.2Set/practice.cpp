#include<cstdio>
#include<set>
using namespace std;
set<int> N_f[55];
set<int> N_s[2010];
int main()
{
    int N,M;      //N 集合的数目,M 为单个集合的数目
    int num;
    int num1,num2;
    int K;        //K为查询的个数
    scanf("%d",&N);
    for (int i=1;i<=N;i++)
    {
        scanf("%d",&M);     //读入集合内数字的个数
        for(int j=1;j<=M;j++)
        {
            scanf("%d",&num);
            N_f[i].insert(num);     //插入元素num                             老哥，别犯这样的错误了
        }
    }
    scanf("%d",&K);     //读入K的值
    int sum=0;        //计算总数
    int sum1=0;
    int p,q;
    set<int>::iterator it;
    for(int i=1;i<=K;i++)
    {
        scanf("%d %d",&num1,&num2);
        sum=N_f[num1].size()+N_f[num2].size();      //包括重复的总个数
        for(it=N_f[num1].begin();it!=N_f[num1].end();it++)
        {
            N_s[i].insert(*it);
        }
        for(it=N_f[num2].begin();it!=N_f[num2].end();it++)
        {
            N_s[i].insert(*it);
        }
        sum1=N_s[i].size();
        p=sum-sum1;q=sum1;
        printf("%.1f%%\n",p*100.0/q);
    }
    return 0;
}