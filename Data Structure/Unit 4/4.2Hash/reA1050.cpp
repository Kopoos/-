#include<cstdio>
#include<cstring> 
bool hashtable[128]={false};
int main()
{
    char str1[10010],str2[10010];
    gets[str1];
    gets[str2];
    int len1=strlen(str1);
    int len2=strlen(str2);
    for(int i=0;i<len2;i++)
    {
       hashtable[str2[i]]=true;
    }
    for(int i=0;i<len1;i++)
    {
        if(hashtable[str1[i]]==false)printf("%c",a[i]);
    }
}