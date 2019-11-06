#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct student{
    char registration_number[15];
    int score;
    int rank;
    int location_number;
    int local_rank;
}stu[30010];

bool cmp(student a,student b)
{
    if(a.score!=b.score)return a.score>b.score;
    else return strcmp(a.registration_number,b.registration_number)<0;
}

int main()
{
    int N;      //N代表测试地点的数目
    int K;      //K代表每个地点的测试人数
    int num=0;      //代表总人数
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%d",&K);
        for(int j=0;j<K;j++)
        {  
            scanf("%s %d",stu[num].registration_number,&stu[num].score);
            stu[num].location_number=i+1;
            num++;
        }
        sort(stu+num-K,stu+num,cmp);
        stu[num-K].local_rank=1;
        for(int i=1;i<=K;i++)       //项目内部排名
        {
            if(stu[num-K+i].score==stu[num-K+i-1].score)stu[num-K+i].local_rank=stu[num-K+i-1].local_rank;
            else{
                stu[num-K+i].local_rank=i+1;
            }
        }
    }
    printf("%d\n",num);
    sort(stu,stu+num,cmp);
    stu[0].rank=1;
    for(int i=1;i<=num;i++)
    {
        if(stu[i].score==stu[i-1].score)stu[i].rank=stu[i-1].rank;
        else{
            stu[i].rank=i+1;
        }
    }
    for(int i=0;i<num;i++){
        printf("%s %d %d %d\n",stu[i].registration_number,stu[i].rank,stu[i].location_number,stu[i].local_rank);
    }
    return 0;
}