// #include<cstdio>
// #include<string>
// using namespace std;

// int main()
// {
//     string str="abcd";
//     for(string::iterator it=str.begin();it!=str.end();it++){
//         printf("%c",*it);
//     }
// return 0;
// }

// #include<stdio.h>
// //A[]为严格递增序列，left为二分下界，right为二分上界，x为欲查询的数
// //二分区间为左闭右闭的[left,right],传入的初值为[0,n-1]
// int binarySearch(int A[],int left,int right,int x){
//     int mid;                            //mid为left和right的中点
//     while(left<=right){                 //闭区间
//         mid=(left+right)/2;             //取中点
//         if(A[mid]==x)return mid;        //找到x,返回下标
//         else if(A[mid]>x){              //中间的数大于x
//             right=mid-1;                //往左子区间[left,mid-1]查找   
//         }else{                          //中间的数小于x
//             left=mid+1;                 //往右子区间[mid+1,right]查找
//         }
//     }
//     return -1;      //查找失败，返回-1
// }



// int main()
// {
//     const int n=10;
//     int A[n]={1,3,4,6,7,8,10,11,12,15};
//     printf("%d %d\n",binarySearch(A,0,n-1,6),binarySearch(A,0,n-1,9));
//     return 0;
// }