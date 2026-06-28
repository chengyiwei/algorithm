#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=1e6+5;
vector<int> dep;
vector<vector<int> > E;
vector<int> son;
vector<int> p;
void dfs1(int x){
    for(auto u: E[x]){
        dfs1(u);
        if(son[x]==0||dep[u]>dep[son[x]]) son[x]=u;
    }
    dep[x]=dep[son[x]]+1;
}
void dfs2(int x,int now_l){
    if(!son[x]) p.push_back(now_l);
    else {
        dfs2(son[x],now_l+1);
        for(auto u:E[x]) {
            if(u!=son[x])
                dfs2(u,1);
        }
    } 
}
inline void solve(){
    int N=read();
    p.clear();
    dep.assign(N+1,0);
    son.assign(N+1,0);
    E.resize(N+1);
    for(auto& x:E){
        x.clear();
    }

    for(int i=2;i<=N;i++){
        int fa=read();
        E[fa].push_back(i);
    }
    dfs1(1);
    dfs2(1,1);
    sort(p.begin(),p.end(),greater<int>());
    int num=p.size(),ans=num;
    for(int i=0;i<num-1;i++){
        int now_ans=i+p[i+1]+1;
        ans=min(now_ans,ans);
    }
    cout<<ans<<endl;
    return ;
}
int main(){
    freopen("L.in","r",stdin);
    int T=read();
    while(T--) solve();
}