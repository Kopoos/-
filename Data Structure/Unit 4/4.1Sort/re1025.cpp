#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

struct student{     //定义合适的学生信息结构体
    char registration_number[14];
    int final_rank;
    int score;
    int location_number;
    int local_rank;
}stu[30010];

bool cmp(student a,student b)
{
    if(a.score!=b.score) return a.score>b.score;
    else return strcmp(a.registration_number,b.registration_number)<0;
}

int main()
{
    int N,K,num=0;        //N和K分别为测试点数量，和单个地点的测试者数量,num为总考生人数
    int i,j;
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        scanf("%d",&K);
        for(j=0;j<K;j++)        //读入测试者的个人信息
        {
            scanf("%s %d",stu[num].registration_number,&stu[num].score);
            stu[num].location_number=i+1;
            num++;
        }
        sort(stu+num-K,stu+num,cmp);
        stu[num-K].local_rank=1;
        for(int k=1;k<K;k++)        //单个测试点进行排序
        {
            if(stu[num-K+k].score==stu[num-K+k-1].score)stu[num-K+k].local_rank=stu[num-K+k-1].local_rank;
            else stu[num-K+k].local_rank=num-K+k+1-(num-K);
        }
    }
    sort(stu,stu+num,cmp);
    stu[0].final_rank=1;
    for(int k=1;k<num;k++)        //单个测试点进行排序
    {
        if(stu[k].score==stu[k-1].score)stu[k].final_rank=stu[k-1].final_rank;
        else stu[k].final_rank=k+1;
    }
    printf("%d\n",num);
    for(int j=0;j<num;j++)
    {
        printf("%s %d %d %d\n",stu[j].registration_number,stu[j].final_rank,stu[j].location_number,stu[j].local_rank);
    }
    return 0;
}
