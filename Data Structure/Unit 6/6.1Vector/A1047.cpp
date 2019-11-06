#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=40010;       //最大学生数
const int maxc=2510;        //最大课程数

char name[maxn][5];     //有maxn个学生，存放他们的姓名
vector<int>course[maxc];        //course[i]存放第i门课的所有学生的编号
bool cmp(int a,int b){
    return strcmp(name[a],name[b])<0;       //按姓名的大小从小到大进行排序
}
int main()
{
    int n,k,c,courseID;
    scanf("%d%d",&n,&k);        //学生人数及课程数
    for(int i=0;i<n;i++)
    {
        scanf("%s %d",name[i],&c);      //学生姓名以及选课数
        for(int j=0;j<c;j++)
        {
            scanf("%d",&courseID);     //选择的课程编号
            course[courseID].push_back(i);      //将学生i加入第courseID门课中
        }
    }
    for(int i=1;i<=k;i++)
    {
        printf("%d %d\n",i,course[i].size());       //第i门课的学生数
        sort(course[i].begin(),course[i].end(),cmp);        //对第i门课的学生进行排序
        for(int j=0;j<course[i].size();j++){
            printf("%s\n",name[course[i][j]]);        //输出学生的姓名
        }
    }
    return 0;
}

