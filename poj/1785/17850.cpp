/*

笛卡尔树
    二叉堆+二叉排序树

*/
#include<iostream>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int maxn=0x7fffffff;

struct node
{
    char s[100];
    int l,r,fa,idx;
    friend bool operator<(const node& a,const node& b){
        return strcmp(a.s,b.s)<0;
    }
}p[50005];

void myinsert(int n)
{
    for(int i=1;i<=n;i++){
        int j=i-1;
        while(p[j].idx<p[i].idx)
            j=p[j].fa;
        p[i].l=p[j].r;
        p[p[i].l].fa=i;
        p[j].r=i;
        p[i].fa=j;
    }
}

void dfs(int x)
{
    if(x==0)
        return ;
    printf("(");
    dfs(p[x].l);
    printf("%s/%d",p[x].s,p[x].idx);
    dfs(p[x].r);
    printf(")");
}

int main()
{
    freopen("1785.in","r",stdin);
    freopen("17850.out","w",stdout);
    int n;
    while(scanf("%d",&n),n){
        for(int i=1;i<=n;i++){
            scanf(" %[^/]/%d",p[i].s,&p[i].idx);
            p[i].l=p[i].r=p[i].fa=0;
        }
        p[0].l=p[0].r=p[0].fa=0;
        p[0].idx=maxn;
        sort(p+1,p+1+n);
        myinsert(n);
        dfs(p[0].r);
        puts("");
    }
    return 0;
}
