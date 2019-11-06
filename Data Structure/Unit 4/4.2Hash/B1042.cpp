#include<cstdio>
#include <cstring>
int main()
{
    char str[1010];
    int hashtable[30]={0};
    int max=0;
    gets(str);
    int len=strlen(str);
    for(int i=0;i<len;i++)
    {
        if(str[i]<='Z'&&str[i]>='A')hashtable[str[i]-'A']++;
        else if(str[i]<='z'&&str[i]>='a')hashtable[str[i]-'a']++;
    }
    for(int j=0;j<30;j++)
    {
        if(hashtable[j]>hashtable[max])max=j;
    }
    printf("%c %d",str[max],hashtable[max]);
    return 0;
}