#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
const int maxn=20;

void solve(){
    int N=read(),M=read(),K=read();
    int lst=K-(N-1)-(M-1);
    if(lst<0||(lst%4!=0&&lst%4!=2)) {printf("NO\n");return;}
    int L[maxn][maxn]={0},C[maxn][maxn]={0};
    int tim=0;
    for(int i=1;i<M;i++) 
        {L[1][i]=tim,tim^=1;}    
    for(int j=1;j<N;j++) 
        {C[j][M]=tim,tim^=1;}
    L[N][M-1]=tim,tim^=1;
    C[N-1][M-1]=tim,tim^=1;
    L[N-1][M-1]=tim,tim^=1;

    tim=0;
    C[1][1]=tim,tim^=1;
    L[2][1]=tim,tim^=1;
    C[1][2]=tim,tim^=1;
    printf("YES\n");
    for(int i=1;i<=N;i++){
        for(int j=1;j<M;j++) printf("%c ",L[i][j]?'B':'R');
        printf("\n");
    }
    for(int i=1;i<N;i++){
        for(int j=1;j<=M;j++) printf("%c ",C[i][j]?'B':'R');
        printf("\n");
    }
}
int main(){
    // freopen("C.in","r",stdin);
    // freopen("C.out","w",stdout);
    int T=read();
    while(T--) solve();
    return 0;
}