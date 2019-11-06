#include<cstdio>

#include<vector>
#include<algorithm>
using namespace std;    
const int M=26*26*26*10;        //注意大小
vector<int>hashtable[M];      //双层数组存储课程信息
int hashFunc(char S[])
{
    int id=0;
    for(int i=0;i<3;i++)
    {
        id=id*26+(S[i]-'A');
    }
    return id=id*10+(S[3]-'0');
}

int main()
{
    int N,K;        //N为总人数，K为课程总个数
    scanf("%d %d",&N,&K);
    int num,Ki;     //单个课程的编号和人数
    char name[5];        //存储姓名的数组


    int id;

    for(int i=0;i<K;i++)
    {
        scanf("%d %d",&num,&Ki);
        for(int j=0;j<Ki;j++)
       {
           scanf("%s",name);
           id=hashFunc(name);
           hashtable[id].push_back(num);
       }
    }
    for(int i=0;i<N;i++)
    {
        scanf("%s",name);
        id=hashFunc(name);
        sort(hashtable[id].begin(),hashtable[id].end() );        //从小到大排序
        printf("%s %d",name,hashtable[id].size() );
        for(int j=0;j<hashtable[id].size();j++)
       {
           printf(" %d",hashtable[id][j]);
       }
        printf("\n");
    }
   return 0;
}