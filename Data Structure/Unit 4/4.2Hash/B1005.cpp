#include <cstdio>
#include <algorithm>
using namespace std;
bool cmp(int a, int b)
{
    return a > b; //从小到大排列
}
int main()
{
    int n, m, a[110];
    scanf("%d", &n);
    bool hashtable[10000] = {0}; //hashtable[x]==true表示x被覆盖
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        m = a[i];
        while (m != 1)
        {
            //对m进行3n+1猜想操作
            if (m % 2 == 1)
                m = (3 * m + 1) / 2;
            else
                m = m / 2;
            hashtable[m]=true;      //被覆盖的数的flag设置为true
        }
    }
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(hashtable[a[i]]==false){     //没被覆盖
            count++;
        }
    }
    sort(a,a+n,cmp);        //从大到小的顺序进行排列
    for(int i=0;i<n;i++){
        if(hashtable[a[i]]==false){
        printf("%d",a[i]);
        count--;
        if(count>0)printf(" ");     //控制输出格式
        }
    }   
    return 0;
}
