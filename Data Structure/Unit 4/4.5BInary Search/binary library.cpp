#include<stdio.h>
//A[]为严格递增的序列，left为二分下界，right为二分上界，x为欲查询的数
//二分区间为左闭右闭的[left,right],传入的初值为[0,n-1]
int binarySearch(int A[],int left,int right,int x){
    int mid;        //mid为left与right的中点
    while(left<=right){     //如果left>right就没办法形成闭区间了
        mid=(left+right)/2;     //取中点
        if(A[mid]==x)return mid;        //找回x.返回下标
        else if(A[mid]>x){      //中间的数大于x
            right =mid-1;       //往左子区间[left,mid-1]查找
        }else{      //中间的数小于x
            left=mid+1;         //往右子区间[mid+1,right]查找
        }
    }
    return -1;      //查找失败，返回-1；
}

//进一步对问题进行探讨，如果递增序列A的元素可以重复，那么如何对给定的欲查询元素x,
//求出序列中第一个大于等于x的元素的位置L以及第一个大于x的位置R，
//这样元素x在序列中的存在区间就是左闭右开[L,R)

//第一个问题求出第一个大于等于x的元素的位置L
//A[]为递增序列，x为欲查询的数，函数返回第一个大于等于x的元素的位置
//二分法上下界为左闭右闭的[left,right],传入的初值为[0,n],取n就是假设它存在应该在的位置，就是比序列中所有的数都要大
int lower_bound(int A[],int left,int right,int x)
{
    int mid;        //mid为left与right的中点
    while(left<right){       //对于left与right来说，left==right就是找到唯一的位置
        mid=(left+right)/2;     //取中点
        if(A[mid]>=x){      //中间的数大于等于x
            right=mid;      //往左子区间[left,mid]查找
        }else{      //中间的数小于x
            left=mid+1;     //往右子树[mid+1,right]查找
        }
    }
    return left;        //返回夹出来的位置
}


//第二个问题求出第一个大于x的元素的位置L
//二分法上下界为左闭右闭的[left,right],传入的初值为[0,n]
int upper_bound(int A[],int left,int right,int x)
{
    int mid;        //mid为left与right的中点
    while(left<right){       //对于left与right来说，left==right就是找到唯一的位置
        mid=(left+right)/2;     //取中点
        if(A[mid]>x){      //中间的数大于x
            right=mid;      //往左子区间[left,mid]查找
        }else{      //中间的数小于x
            left=mid+1;     //往右子树[mid+1,right]查找
        }
    }
    return left;        //返回夹出来的位置
}


















int main()
{
    const int n=10;
    int A[n]={1,3,4,6,7,8,10,11,12,15};
    printf("%d %d\n",binarySearch(A,0,n-1,6),binarySearch(A,0,n-1,9));
    return 0;
}