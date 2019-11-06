// #include<cstdio>
// #include<cstring>
// const int maxn=40;
// bool hashtable[maxn]={false};

// int main()
// {
//     char alpha[80];     //为输入的字符
//     char alphb[80];     //为检测输出的字符
//     gets(alpha);
//     gets(alphb);
//     int lena=strlen(alpha);
//     int lenb=strlen(alphb);
//     int id=0;
//     for(int i=0;i<lena;i++)
//     {
//         if(alpha[i]>='a'&&alpha[i]<='z'){
//             id=id*26+(alpha[i]-'a');
//             hashtable[id]=true;
//         }
//         if(alpha[i]>='A'&&alpha[i]<='Z'){
//             id=id*26+(alpha[i]-'A');
//             hashtable[id]=true;
//         }
//     }



// }
#include<cstdio>
#include<cstring>
int main()
{
    char alpha[100];
    char alphb[100];
    bool hashtable[128]={false}; 
    int j=0;
    gets(alpha);
    gets(alphb);
    int lena=strlen(alpha);
    int lenb=strlen(alphb);
    for(int i=0;i<lena;i++)
    {
        for(j=0;j<lenb;j++)
        {
            if(alpha[i]<='z'&&alpha[i]>='a')alpha[i]-=32;
            if(alphb[j]<='z'&&alphb[j]>='a')alphb[j]-=32;
            if(alpha[i]==alphb[j])break;
        }
        if(j==lenb&&hashtable[alpha[i]]==false){
            printf("%c",alpha[i]);
            hashtable[alpha[i]]=true;
        }
    }
    return 0;
}
