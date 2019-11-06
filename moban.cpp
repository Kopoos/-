#include<cstdio>
#include<vector>
using namespace std;
const int maxn=100;
//序列A中n个数选K个使得和为x,最大平方和为maxSumSqu
int n,k,x,maxSumSqu=-1,A[maxn];
//temp存放临时方案，ans存放平方和的最大的方案
vector<int>temp,ans;
//当前处理index号整数，当前已选整数个数为nowk
//当前已选的整数之和为sum,当前已选的整数平方和为sumSqu
void DFS(int index,int nowK,int sum,int sumSqu)
{
    if(nowK==k&&sum==x)
    {   //找到k个数的和为x
        if(sumSqu>maxSumSqu){   //如果比当前找到的更优
            maxSumSqu=sumSqu;       //更新最大平方和
            ans=temp;       //更新最优的方案
        }
        return;
    }
    //已处理完n个数，或者超过k个数，或者和超过x，返回
    if(index==n||nowK>k||sum>x)return;
    temp.push_back(A[index]);
    DFS(index+1,nowK+1,sum+A[index],sumSqu+A[index]*A[index]);
    temp.pop_back();
    //不选index号数
    DFS(index+1,nowK,sum,sumSqu);
}
