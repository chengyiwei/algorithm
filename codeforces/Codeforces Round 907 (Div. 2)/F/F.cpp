#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+5;
int N,Q,siz,num_q,ans[maxn];
int in[maxn];

struct AS{
    int time,val;
};
vector<AS> add[maxn];
vector<int> E[maxn];
struct tree{
    int c[maxn];
    tree(){memset(c,0,sizeof c);}
    void add_x(int x,int val){for(int i=x;i<maxn;i+=i&-i) c[i]+=val;}
    int get(int x){
        if(x==0)return 0;
        int ret=0;
        for(int i=x;i;i-=i&-i) ret+=c[i];
        return ret;
    }
}t;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

void dfs(int x){
    int num_add=add[x].size();
    for(int i=0;i<num_add;i++) 
        t.add_x(add[x][i].time,add[x][i].val);

    ans[x]=t.get(maxn-1)-t.get(in[x]-1);
    int num_son=E[x].size();
    for(int i=0;i<num_son;i++)
        dfs(E[x][i]);
    
    for(int i=0;i<num_add;i++) 
        t.add_x(add[x][i].time,-add[x][i].val);
}

inline void print(int x){
    if(x<0) putchar('-'),x=-x;
    stack<int> p;
    do{p.push(x%10);x/=10;}while(x);
    while(!p.empty()) putchar(p.top()+'0'),p.pop();
}

inline void solve(){
    Q=read();siz=1;in[1]=1;

    for(int i=1;i<=Q;i++){
        int op=read();
        if(op&1){
            int fa=read();
            siz++;in[siz]=i;
            E[fa].push_back(siz); //建边
        }
        else {
            AS now;
            int id=read();
            now.time=i;now.val=read();
            add[id].push_back(now);
        }
    }
    
    dfs(1);

    for(int i=1;i<=siz;i++)
        print(ans[i]),putchar(' ');
    putchar('\n');

    for(int i=1;i<=siz;i++) add[i].clear(),E[i].clear(),ans[i]=0;
}

signed main(){
    // freopen("F.in","r",stdin);
    // freopen("F.out","w",stdout);
    int T=read();
    while(T--)solve();
    // printf("%d\n",clock());
    return 0;
}