#include<cstdio>
struct student{
    int team_N,member_N,grade;      //代表队伍编号，成员编号，分数；
}stu[10010];

int main()
{
    int N;      //为参赛队员总数
    int hashtable[10010]={0};
    int i=0;
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        scanf("%d-%d %d",&stu[i].team_N,&stu[i].member_N,&stu[i].grade);
        hashtable[stu[i].team_N]+=stu[i].grade;
    }
    int max=0,k=0;
    for(i=0;i<N;i++)
    {
        if(hashtable[stu[i].team_N]>max)
        {
            max=hashtable[stu[i].team_N];
            k=stu[i].team_N;
        }  
    }
    printf("%d %d\n",k,max);        //输出结果
    return 0;
}
