#include<bits/stdc++.h>
using namespace std;
struct dsu{
    int n;
    vector<int> fa,d;
    dsu(int n){
        this->n=n;
        fa.resize(n+1);d.resize(n+1);
        for(int i=1;i<=n;i++) fa[i]=i,d[i]=0;
    }
    int find(int x){
        if(x!=fa[x]){
            int f=fa[x];  // f 是此时的父节点
            fa[x]=find(fa[x]);   // 递归找到根节点
            d[x]+=d[f]; // 更新权值
        }
        return fa[x];
    }
    void merge(int x,int y){
        int fx=find(x),fy=find(y);
        if(fx==fy) {
            
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