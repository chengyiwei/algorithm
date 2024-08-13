#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void solve(){
    int N=read();
    LL ans=0;
    vector<vector<int> > a(N+1,vector<int>(N+1,0));
    vector<int> Line(N+1,0),Col(N+1,0);

    for(int i=1;i<=N;i++)
    for(int j=1;j<=N;j++)
        a[i][j]=read();
    for(int i=1;i<=N;i++)
    for(int j=1;j<=N;j++)
        if(a[i][j]<=0){
            ans+=a[i][j];
            Line[i]=1;Col[j]=1;
        }
    
    LL ans1=0,ans2=0;
    for(int i=1;i<=N;i++)if(Line[i]==0){
        int Min_x=INF;
        for(int j=1;j<=N;j++) Min_x=min(Min_x,a[i][j]);
        ans1+=Min_x; Line[i]=1;
    }

    for(int i=1;i<=N;i++)if(Col[i]==0){
        int Min_y=INF;
        for(int j=1;j<=N;j++) Min_y=min(Min_y,a[j][i]);
        ans2+=Min_y; Col[i]=1;
    }

    ans=ans+min(ans1,ans2);
    printf("%lld\n",ans);

}
int main(){
    freopen("D.in","r",stdin);
    int T=read();
    while(T--) solve();
}