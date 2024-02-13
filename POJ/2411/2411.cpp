#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long LL;
LL F[2][1<<11];
int main(){
    freopen("2411.in","r",stdin);
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF && n && m){
        if(n < m) swap(n,m);
        memset(F,0,sizeof(F));
        int now = 0, old = 1;
        F[now][(1<<m)-1] = 1;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                swap(now,old);
                memset(F[now],0,sizeof(F[now]));
                for(int k=0;k<(1<<m);k++){
                    if(k & 1<<(m-1))   // k的最高位为1，不放
                        F[now][(k<<1) & (~(1<<m))] += F[old][k];
                    if(i && !(k & 1<<(m-1)))  // k的最高位为0，竖着放
                        F[now][(k<<1)^1] += F[old][k];
                    if(j && (!(k&1)) && (k & 1<<(m-1)))  // k的最高位为1，且最低位为 0，横着放
                        F[now][((k<<1)|3) & (~(1<<m))] += F[old][k];
                }
            }
        printf("%lld\n",F[now][(1<<m)-1]);
    }
    return 0;
}