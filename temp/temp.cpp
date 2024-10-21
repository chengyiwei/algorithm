//给定n个不同的正整数集合w=（w1，w2，…，wn）和一个正数W，要求找出w的子集s，使该子集中所有元素的和为W。

#include <stdio.h>
#include <iostream>
using namespace std;
#define MAXN 20                        //最多整数个数

int n,W;
int w[MAXN]={0};                //存放所有整数,不用下标0的元素
void dispasolution(int x[])            //输出一个解
{    int i;
    for (i=1;i<=n;i++)
        if (x[i]==1)
            printf("%d ",w[i]);
    printf("\n");
}
void dfs(int tw,int rw,int x[],int i);

int main()
{   cin>>n>>W;
    for(int i=1;i<=n;i++)
      cin>>w[i]; 
    int x[MAXN];                    //存放一个解向量
    int rw=0;
    for (int j=1;j<=n;j++)            //求所有整数和rw
        rw+=w[j];
    dfs(0,rw,x,1);                //i从1开始
    return 0;
}


void dfs(int tw,int rw,int x[],int i)
{    x[i]=1;                        //选第i个整数
    if (tw+w[i]==W)                //找到一个解
        dispasolution(x);
    else if (i<n)                    //未到叶结点
        if (tw+w[i]+w[i+1]<=W)        //左子树可能含解
            dfs(tw+w[i],rw-w[i],x,i+1);
    if (tw+rw-w[i]>=W)                //右子树可能含解
    {    x[i]=0;                    //不选第i个整数
        dfs(tw,rw-w[i],x,i+1);
    }
}