#include<cstdio>
#include<cstring>
const int maxn=1010;
char str1[maxn];
char str2[maxn];
int main()
{
    gets(str1);
    gets(str2);
    int len1=strlen(str1);
    int len2=strlen(str2);
    int flag1=0;
    int miss=0;
    int i=0,j=0;
    int hashtable[128]={0};      //设置俩个hash一个计数一个判断是否有这种珠子
    bool hash[128]={false};
    for(i=0;i<len1;i++)          //读入珠子的数量，注意复杂性不能用N*M的形式
    {
        hashtable[str1[i]]++;
        hash[str1[i]]=true;
    }
    for(j=0;j<len2;j++)           
    {
       if(hash[str1[j]]=true) {     //用减号来消除，存在俩种珠子缺少的情况
           hashtable[str2[j]]--;
           if(hashtable[str2[j]]<0){
               miss++;
               flag1=1;
            }
       }
       else {flag1 =1;miss++;}
    }
    if(flag1==1)printf("No %d",miss);
    else printf("Yes %d",len1-len2);
    return 0;
}
