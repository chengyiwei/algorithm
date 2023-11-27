#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=1e5+5;
int N;
vector<int> factor[maxn];

void solve(){
    LL ans=0;
    N=read();
    vector<int> cnt(maxn+1);
    vector<LL> f(maxn+1);
    vector<int> a;
    for(int i=1;i<=N;i++) 
        a.push_back(read());
    sort(a.begin(),a.end());
    for(int i=0;i<N;i++){
        LL now=0;
        int x=a[i];
        for(int k=factor[x].size()-1;k>=0;k--){
            int t=factor[x][k];
            f[t]+=cnt[t];
            now+=t*f[t];
            for(auto tt:factor[t])
                f[tt]-=f[t];
        }
        for(auto t:factor[x]){
            cnt[t]+=1;
            f[t]=0;
        }
        ans+=now*(N-i-1);
    }
    cout<<ans<<'\n';
    return ;
}

int main(){
    freopen("D.in","r",stdin);
    for(int i=1;i<maxn;i++)
        for(int j=i;j<maxn;j+=i)
            factor[j].push_back(i);
    int T=read();
    while(T--) solve();
}