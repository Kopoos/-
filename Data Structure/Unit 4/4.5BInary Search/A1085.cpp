#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100010;
int n,p,a[maxn];        //n为给的数组个数，p为给定的参数，

//binarySearch函数在[i+1,n-1]
int binarysearch(int i,long long x)
{
    int mid;        //mid为left与right的中点
    //if(a[n-1]<x) return n;      //所有数都小于x，返回n
    int left=i+1,right=n;     //[left,right]->[i+1,n]为取值范围
    while(left<right){       //对于left与right来说，left==right就是找到唯一的位置
        mid=(left+right)/2;     //取中点
        if(a[mid]>x){      //中间的数大于x
            right=mid;      //往左子区间[left,mid]查找
        }else{      //中间的数小于x
            left=mid+1;     //往右子树[mid+1,right]查找
        }
    }
    return left;        //返回夹出来的位置

}

int main()
{
    scanf("%d%d",&n,&p);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);        //递增排序
    int ans=1;          //最大长度，初值为1(表示至少有一个数)
    for(int i=0;i<n;i++)
    {
        //在a[i+1]~a[n-1]中查找第一个超过a[i]*p的数，返回其位置给j
        int j=binarysearch(i,(long long)a[i]*p);
        ans=max(ans,j-i);       //更新最大长度
    }
    printf("%d\n",ans);     //输出最大的结果
    return 0;
}