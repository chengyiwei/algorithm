#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL TT=998244353;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

struct Line{
    int L,R;
    Line(int L=0,int R=0):L(L),R(R){}
    bool operator <(const Line B) const{return L<B.L;}
};

vector<vector<int> > E;
struct Tarjan{
    int n;
    vector<int>dfn,low;int dfn_cnt;
    vector<int> scc;int sc; //节点 i 所在 SCC 的编号
    vector<int> siz; //强连通 i 的大小
    stack<int> st;
    vector<int> in_st;//判断是否在栈内

    void init(int n){
        this->n=n;
        dfn.resize(n+1);low.resize(n+1);dfn_cnt=0;
        scc.assign(n+1,0);sc=0;siz.assign(n+1,0);
        while(!st.empty())st.pop();
        in_st.assign(n+1,0);
    }

    void tarjan(int u){
        low[u]=dfn[u]=++dfn_cnt;st.push(u);in_st[u]=1;
        for(int i=0;i<E[u].size();i++){
            int& v=E[u][i];
            if(!dfn[v]){//没有访问过
                tarjan(v);
                low[u]=min(low[u],low[v]);
            }else if(in_st[v]){
                low[u]=min(low[u],dfn[v]);
            }
        }
        if(dfn[u]==low[u]){ //找到双连通分量了
            ++sc; 
            while(st.top()!=u){ //从栈顶到 u 都是这个强连通分量里面的
                scc[st.top()]=sc;siz[sc]++;
                in_st[st.top()]=0;st.pop();
            }
            scc[st.top()]=sc;siz[sc]++;
            in_st[st.top()]=0;st.pop();
        }
        return ;
    }
};

void solve(){
    int n=read();
    LL ans1=0,ans2=1;
    Tarjan F;F.init(n);
    vector<int> a(2*n+1);
    vector<Line> L(n+1,Line(0,0));
    E.assign(n+1,vector<int>());
    for(int i=1;i<=2*n;i++) a[i]=read();
    for(int i=1;i<=2*n;i++){
        if(L[a[i]].L==0) L[a[i]].L=i;
        else L[a[i]].R=i;
    }
    sort(L.begin()+1,L.begin()+1+n);
    for(int i=1;i<=n;i++)
    for(int j=max(1,i-1000);j<=min(n,i+1000);j++){
        if(i==j)continue;
        if((L[i].L<L[j].L&&L[i].R>L[j].L)||(L[i].L<L[j].R&&L[i].R>L[j].R)){ //j in i
            // printf(":%d %d\n",i,j);
            E[i].push_back(j);
        }
    }
    for(int i=1;i<=n;i++) if(!F.dfn[i])
        F.tarjan(i);
    
    vector<int> du(n+1,0);
    for(int u=1;u<=n;u++){
        for(int& v:E[u]){
            if(F.scc[u]!=F.scc[v])
                du[F.scc[v]]++;
        }
    }
    for(int i=1;i<=F.sc;i++){
        if(du[i]==0){
            ans1++;
            ans2=ans2*(F.siz[i]*2)%TT;
        }
    }
    printf("%lld %lld\n",ans1,ans2);
}
int main(){
    freopen("G1.in","r",stdin);
    int t=read();
    while(t--) solve();
}