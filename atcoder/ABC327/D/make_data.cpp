#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
const int maxn=2e5+5;
int brand(){
    return (rand()<<16)+(rand()<<1)+(rand()&1);
}

struct node{
    int x,y;
}ans[maxn];
int a[maxn],b[maxn];
int main(){
    freopen("D.in","w",stdout);
    srand(GetTickCount());
    int N=10,M=2e5;
    printf("%d %d\n",N,M);
    for(int i=1;i<=N;i++){
        if(rand()&1) a[++a[0]]=i;
        else b[++b[0]]=i;
    }
    for(int i=1;i<=M;i++){
        int x=brand()%a[0]+1,y=brand()%b[0]+1;
        if(rand()&1)
            ans[i].x=a[x],ans[i].y=b[y];
        else 
            ans[i].y=a[x],ans[i].x=b[y];
    }
    // ans[N].x=a[1],ans[N].y=a[2];
    for(int i=1;i<=M;i++)
        printf("%d ",ans[i].x);
    printf("\n");
    for(int i=1;i<=M;i++)
        printf("%d ",ans[i].y);
    return 0;
}