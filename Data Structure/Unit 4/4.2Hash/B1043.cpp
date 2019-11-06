#include<cstdio>
#include<cstring>
int hashtable[10]={0};
int main()
{
    char str[10010];
    char test[10]="PATest";
    int sum=0;
    gets(str);
    int len1=strlen(str);
    int len2=strlen(test);
    for(int i=0;i<len1;i++)
    {
        for(int j=0;j<6;j++)
        {
            if(str[i]==test[j]){
            hashtable[j]++;
            sum++;
            }
        }
    }
    while(sum>0){
        for(int i=0;i<6;i++)
        {
            if(hashtable[i]>0)
            {
            hashtable[i]--;
            printf("%c",test[i]);
            }
        }
    }
    return 0;
}

