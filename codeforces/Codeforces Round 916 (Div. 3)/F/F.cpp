#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

vector<vector<int> >G; 

int ans;
int DFS(int u){
    if(G[u].size()==0) return 0;
    priority_queue<int> pq;
    for(auto v:G[u]){
        int now=DFS(v);
        pq.push(now+1);
    }
    while(pq.size()>1){
        int x=pq.top();pq.pop();
        int y=pq.top();pq.pop();
        int c=abs(x-y);
        ans+=min(x,y);
        if(c!=0)
            pq.push(c);
    }
    int ret=0;
    for(int i=0;i<pq.size();i++){
        ret+=pq.top();pq.pop();
    }
    return ret;
}

void solve(){
    int n=read();
    G.assign(n+1,vector<int>());
    for(int i=1;i<n;i++){
        int fa=read();
        G[fa].push_back(i+1);
    }
    ans=0;
    DFS(1);
    printf("%d\n",ans);
}
int main(){
    freopen("F.in","r",stdin);
    int T=read();
    while(T--) solve();
}