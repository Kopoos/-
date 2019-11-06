#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=26*26*26*10+9;
vector <int> a[maxn];

int hash_id(char name[])
{
    int id=0;
    for(int i=0;i<3;i++)
    {
        id=id*26+(name[i]-'A');
    }
    id=id*10+(name[3]-'0');
    return id;
}


int main()
{
    int N,K;        //N为总学生数，K为课程的数目
    int course_id=0,stu_num=0;
    char name[5];
    int id=0;
    scanf("%d %d",&N,&K);
    for(int i=0;i<K;i++)
    {
        scanf("%d %d",&course_id,&stu_num);
        for(int j=0;j<stu_num;j++)
        {
            scanf("%s",name);
            id=hash_id(name);
            a[id].push_back(course_id);
        }
    }
    for(int i=0;i<N;i++)
    {
      scanf("%s",name);
      id=hash_id(name);
      sort(a[id].begin(),a[id].end());
      printf("%s %d",name,a[id].size());
      for(int j=0;j<a[id].size();j++)
      {
          printf(" %d",a[id][j]);
      }
      printf("\n");
    }
    return 0;
    
}