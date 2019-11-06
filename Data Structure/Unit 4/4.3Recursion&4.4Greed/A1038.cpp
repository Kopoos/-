#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>

using namespace std;
const int maxn=10010;
string str[maxn];

bool cmp(string a ,string b)
{
    return a+b<b+a;     //核心算法，a+b组合与b+a组合进行对比，大的放在前面
}

int main()
{
    int n;
    cin >>n;
    for (int i=0;i<n;i++)
    {
        cin>>str[i];
    }
    sort(str,str+n,cmp);        //排序
    string ans;         //结果字符串
    for(int i=0;i<n;i++)
    {
        ans+=str[i];        //将排序后的数字串进行拼接
    }
    while(ans.size()!=0&&ans[0]=='0')
    {
        ans.erase(ans.begin());     //去除前导0
    }
    if(ans.size()==0)cout <<0;      //去除前导0后为空，输出0
    else cout<<ans;         //否则输出结果
    return 0;
}