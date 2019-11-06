// #include<cstdio>
// #include<stack>
// using namespace std;
// stack<int>st;       //建议堆栈

// int main()
// {
//     int M,N,K;      //M是栈的最大容量，N是入栈的长度，K是检查栈的数目
//     int length=0;
//     int i=0;
//     scanf("%d %d %d",&M,&N,&K);
//     bool flag_stack[K]={true};
//     int a[N],num[N]={0};
//     for(int i=0;i<K;i++)
//     {
//         for(int j=0;j<N;j++)
//         {
//             scanf("%d ",&num[j]);
//         }
//         for(int j=1;j<=N;j++)
//         {   if(j!=num[i]){
//                 st.push(num[i]);
//                 i++;
//                 length++;
//                 if(length>M)flag_stack[K]=false;
//             }

//         }

//     }
    
//     return 0;
// }
#include<cstdio>
#include<stack>
using namespace std;
const int maxn=1010;
int arr[maxn];      //保存题目给定的出栈序列
stack<int> st;      //定义栈st，用以存放int型元素
int main()
{
    int m,n,T;
    scanf("%d%d%d",&m,&n,&T);
    while(T--){
        //循环执行T次
        while(!st.empty()){
            //清空栈
            st.pop();
        }
        for(int i=1;i<=n;i++)       //读入数据
        {
            scanf("%d",&arr[i]);
        }
        int current=1;      //指向出栈序列中的待出栈元素
        bool flag=true;
        for(int i=1;i<=n;i++)
        {
            st.push(i);     //把i压入栈
            if(st.size()>m){
                //如果此时栈中元素的个数大于容量m,则序列非法
                flag=false;
                break;
            }
            //栈顶元素与出栈序列当前位置的元素相同时
            while(!st.empty()&&st.top()==arr[current]){
                st.pop();       //反复弹栈并令current++
                current++;
            }
        }
        if(st.empty()==true&&flag==true){
            printf("YES\n");        //栈空且flag==true时表明合法
        }else{
            printf("NO\n");
        }
    }
    return 0;
}