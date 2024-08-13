#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

struct node{
    int x,siz;
    bool operator < (const node &rhs) const{return siz<rhs.siz;}
};

vector<int> siz;
vector<vector<int> >G; 

int ans;
int DFS(int u){
    int ret=1;
    for(auto v:G[u]){
        ret+=DFS(v);
    }
    return siz[u]=ret;
}

void solve(){
    int n=read();ans=0;
    G.assign(n+1,vector<int>());
    siz.assign(n+1,0);
    for(int i=1;i<n;i++){
        int fa=read();
        G[fa].push_back(i+1);
    }
    DFS(1);
    priority_queue<node> pq;
    pq.push((node){1,siz[1]});
    while(!pq.empty()){
        if(pq.size()==1){
            int u=pq.top().x;pq.pop();
            for(int& v:G[u]){
                pq.push((node){v,siz[v]});
            }
        }
        else{
            node A=pq.top();pq.pop();
            node B=pq.top();pq.pop();
            ans++;
            for(int& v:G[A.x]){
                pq.push((node){v,siz[v]});
            }
            for(int& v:G[B.x]){
                pq.push((node){v,siz[v]});
            }
        }
    }
    printf("%d\n",ans);
}
int main(){
    freopen("F.in","r",stdin);
    int T=read();
    while(T--) solve();
}