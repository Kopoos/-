#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100010;
int coupon[maxn],product[maxn];
int main()
{
    int n,m;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&coupon[i]);
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d",&product[i]);
    }
    sort(coupon,coupon+n);      //从小到大
    sort(product,product+m);        //从小到大排序
    int i=0,j,ans=0;
    while(i<n&&i<m&&coupon[i]<0&&product[i]<0)
    {
        ans+=coupon[i]*product[i];      //当前位置小于0,累加乘积
        i++;
    }
    i=n-1;
    j=m-1;
    while(i>=0&&j>=0&&coupon[i]>0&&product[j]>0)
    {
        ans+=coupon[i]*product[j];      //当前位置均大于0，累加乘积
        i--,j--;
    }
    printf("%d",ans);
    return 0;
}