// #include<cstdio>
// #include<set>
// using namespace std;
// const int maxn=10010;
// set<int> vi[maxn];

// int main()
// {
//     int n;        //n为系列数的数目
//     scanf("%d",&n);
//     set<int>::iterator it;
//     set<int>::iterator is;
//     int num,M;
//     for(int i=1;i<=n;i++)
//     {
//         scanf("%d",&num);
//         for(int j=0;j<num;j++)
//         {
//             scanf("%d",&M);     //读入每个系列的数字
//             vi[i].insert(M);
//         }
//     }
//     int k;      //比较的个数
//     int p,q;        //分别为比较的系列数的数字
//     int ans=0;
//     scanf("%d",&k);
//     for(int i=0;i<k;i++)
//     {
//         scanf("%d %d",&p,&q);
//         for(it=vi[p].begin();it!=vi[p].end();it++)
//         {
//             for(is=vi[q].begin();is!=vi[q].end();is++)
//             {
//                 if(it == is)ans++;
//             }
//         }
        
//         printf("%.1f%%\n",ans*100.0/( vi[p].size()+vi[q].size() ) );

        
//     }
//     return 0;
// }
#include<cstdio>
#include<set>
using namespace std;
const int N=51;
set<int> st[N];     //N个集合
void compare(int x,int y)       //比较集合st[x]与集合st[y]
{
    int totalNum=st[y].size(),sameNum=0;        //不同数的个数，相同数目的个数
    //遍历集合st[x]
    for(set<int>::iterator it=st[x].begin();it!=st[x].end();it++){
        if(st[y].find(*it)!=st[y].end() ) sameNum++;        //在st[y]中能找到该元素
        else totalNum++;        //在st[y]中不能找到该元素
    }
    printf("%.1f%%\n",sameNum*100.0/totalNum);      //输出比率
}
int main()
{
    int n,k,q,v,st1,st2;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&k);     //集合个数
        for(int j=0;j<k;j++)
        {
            scanf("%d",&v);     //集合i中的元素个数        
            st[i].insert(v);        //将元素v加入集合st[i]中
        }
    }    
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        scanf("%d%d",&st1,&st2);        //欲对比的集合编号
        compare(st1,st2);               //比较俩个集合
    }
    return 0;
}