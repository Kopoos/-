#include<cstdio>
int main()
{
    int N,M[100010];
    scanf("%d",&N);
    int i,j,flag=0;
    int hashtable[100010]={0};
    for(i=0;i<N;i++)
    {
        scanf("%d",&M[i]);
        hashtable[M[i]]++;
    }
    for(i=0;i<N;i++)
    {
        if(hashtable[M[i]]==1){
            printf("%d",M[i]);
            flag=1;
            break;
        }
    }
    if(flag==0)printf("None");
    return 0;
}
