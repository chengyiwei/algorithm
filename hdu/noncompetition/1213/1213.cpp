#include<bits/stdc++.h>
using namespace std;
struct dsu{
    int n;
    vector<int> fa,h;
    dsu(int n){
        this->n=n;
        fa.resize(n+1);h.resize(n+1);
        for(int i=1;i<=n;i++) fa[i]=i,h[i]=0;
    }
    int find(int x){
        return fa[x]==x?x:find(fa[x]);
    }
    void merge(int x,int y){
        x=find(x),y=find(y);
        if(x==y) return ;
        if(h[x]==h[y]){ //高度相同，随便合并
            h[x]++;
            fa[y]=x;
        }
        else{ //把矮的合并到高的上
            if(h[x]<h[y]) fa[x]=y;
            else fa[y]=x;
        }
    }
};

void solve(){
    int n,m;
    cin>>n>>m;
    dsu d(n);
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        d.merge(x,y);
    }
    int ans=0;
    for(int i=1;i<=n;i++) if(d.find(i)==i) ans++;
    cout<<ans<<endl;
}

int main(){
    int T;cin>>T;
    while (T--) solve();
    return 0;
}