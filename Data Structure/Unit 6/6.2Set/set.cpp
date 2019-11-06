#include<cstdio>
#include<set>
using namespace std;
int main()
{
    set<int> st;
    st.insert(3);       //insertx(x)将x插入set中
    st.insert(5);
    st.insert(2);
    st.insert(3);
    //注意不支持it<st.end()的写法
    //处vector与string之外的STL容器都不支持*（it+i)的访问方式
    set<int>::iterator it=st.find(30);
    st.erase(it,st.end());      
    for(set<int>::iterator it=st.begin();it!=st.end();it++)
    {
        printf("%d",*it);
    }
    return 0;
}

//2  3 5