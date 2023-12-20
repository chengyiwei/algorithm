#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL INF=1e18;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void solve(){
    int n=read();LL ans=0;
    vector<vector<int> > A(3,vector<int>(n+1,0));
    for(int i=0;i<3;i++)
        for(int j=1;j<=n;j++)
            A[i][j]=read();
    vector<vector<LL> > F(n+1,vector<LL>(8,-INF));
    F[0][0]=0;
    for(int i=0;i<n;i++){
        for(int k=0;k<8;k++){
            F[i+1][k]=max(F[i+1][k],F[i][k]);
            for(int p=0;p<3;p++){
                if(k&1<<p) continue;
                F[i+1][k|1<<p]=max(F[i+1][k|1<<p],F[i][k]+A[p][i+1]);
            }
        }
    }
    printf("%lld\n",F[n][7]);
}
int main(){
    freopen("D.in","r",stdin);
    int t=read();
    while(t--) solve();
}