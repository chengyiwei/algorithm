#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL TT=998244353;
vector<LL> fac,tot,siz;
vector<vector<int> > g;
vector<vector<LL> > dp;
int n;

int dfs1(int u,int fa){
    LL res=1;
    tot[u]=0;
    siz[u]=1;
    for(int v:g[u]){
        if(v==fa) continue;
        res=(res*dfs1(v,u))%TT;
        tot[u]++;
        siz[u]+=siz[v];
    }
    res=(res*fac[tot[u]])%TT;
    return res;
}

void dfs(int u,int fa){
    vector<vector<LL> > f(n+1,vector<LL>(n+1,0));
    f[0][0]=1;
    for(int v:g[u]){
        if(v==fa) continue;
        for(int i=tot[u];i>=1;i--){
            for(int sz=siz[u];sz>=siz[v];sz--){
                f[i][sz]=(f[i][sz]+f[i-1][sz-siz[v]])%TT;
            }
        }
    }

    for(int v:g[u]){
        if(v==fa)continue;
        for(int i=1;i<=tot[u];i++)
            for(int sz=siz[v];sz<=siz[u];sz++)
                f[i][sz]=(f[i][sz]-f[i-1][sz-siz[v]]+TT)%TT;

        vector<int> g(n+1,0);
        for(int i=0;i<tot[u];i++)
            for(int k=0;k<siz[u];k++)
                g[k+1]=(g[k+1]+fac[i]*fac[tot[u]-i-1]%TT*f[i][k])%TT;
        
        for(int i=1;i<=n;i++)
            for(int k=1;k<=n;k++)
                if(i+k<=n)
                    dp[v][i+k]=(dp[v][i+k]+dp[u][i]*g[k])%TT;

        for(int i=tot[u];i>=1;i--)
            for(int sz=siz[u];sz>=siz[v];sz--)
                f[i][sz]=(f[i][sz]+f[i-1][sz-siz[v]])%TT;
    }

    for(int v:g[u]){
        if(v==fa)continue;
        dfs(v,u);
    }

}

LL ksm(LL a,LL b=TT-2){
    LL ret=1;
    while(b){
        if(b&1) ret=ret*a%TT;
        a=a*a%TT;
        b>>=1;
    }
    return ret%TT;
}

void solve(){
    cin>>n;
    fac.assign(n+1,0);fac[0]=1;tot.assign(n+1,0);siz.assign(n+1,0);
    g.assign(n+1,vector<int>());dp.assign(n+1,vector<LL>(n+1,0));

    for(int i=1;i<=n;i++) fac[i]=(fac[i-1]*i)%TT;
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    LL p=dfs1(1,0);
    dp[1][1]=1;
    dfs(1,0);
    for(int i=1;i<=n;i++){
        LL sum=0;
        for(int k=1;k<=n;k++)
            sum=(sum+dp[i][k])%TT;
        LL inv=ksm(sum);
        for(int k=1;k<=n;k++){
            printf("%lld ",dp[i][k]*p%TT*inv%TT);
        }
        printf("\n");
    }
    return ;
}
int main(){
    freopen("C.in","r",stdin);
    int T=1;
    while(T--) solve();
    return 0;
}