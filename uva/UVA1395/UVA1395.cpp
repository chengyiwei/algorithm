#include<bits/stdc++.h>
using namespace std;
const int maxn=105,INF=1<<30;
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

int N,M,T;

int fa[maxn];
struct edge{
    int x,y,w;
    edge(int x,int y,int w) : x(x),y(y),w(w) {};
    bool operator <(const edge B) const {return w<B.w;}
};
int getfa(int x){return fa[x]==x?x:fa[x]=getfa(fa[x]);}

void solve(){
    vector<edge> E;
    int ans=INF;
    for(int i=1;i<=M;i++){
        int x=read(),y=read(),w=read();
        E.push_back((edge){x,y,w});
    }
    sort(E.begin(),E.end());
    for(int L=0;L<M;L++){
        iota(fa,fa+N+1,0);
        int R=L,now_m=0;
        while(R<M&&now_m<N-1){
            int fx=getfa(E[R].x),fy=getfa(E[R].y);
            ++R;
            if(fx==fy) continue;
            ++now_m;fa[fx]=fy;
        }
        if(now_m==N-1)
            ans=min(ans,E[R-1].w-E[L].w);
    }
    printf("%d\n",ans==INF?-1:ans);
    return ;
}

int main(){
    freopen("UVA1395.in","r",stdin);
    while(1) {
        N=read();M=read();
        if(N==0&&M==0) break;
        solve();
    }
}