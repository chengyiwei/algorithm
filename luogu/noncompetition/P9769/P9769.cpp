#include<bits/stdc++.h>
using namespace std;
const int maxn=5e6+5;
int X,Y,M,N,a[maxn],F[maxn];
//F[i] 表示前数字为 i 的时候需要的最小次数
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
int Q[maxn],hed,til;
int main(){
    // freopen("P9769.in","r",stdin);
    // freopen("P9769.out","w",stdout);
    X=0;Y=read();N=read();M=read();
    for(int i=1;i<=M;i++)
        a[i]=read();
    memset(F,63,sizeof F);
    F[X]=0;Q[++til]=0;
    for(int i=X+1;i<=Y;i++){
        for(int j=1;j<=M;j++)if(i%a[j]==0){
            F[i]=min(F[i],F[i/a[j]]+1);
        }
        
        while(hed<=til&&Q[hed]<i-N)
            hed++;
        if(hed<=til)
            F[i]=min(F[i],F[Q[hed]]+1);
        while(hed<=til&&F[i]<=F[Q[til]])
            til--;
        Q[++til]=i;
    }
    printf("%d\n",F[Y]);
    return 0;
}