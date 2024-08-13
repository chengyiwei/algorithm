#include<bits/stdc++.h>
using namespace std;
const int INF=1<<30;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

int n;

struct  node{
    int son,w,id,dep,siz,top,fa;
    vector<int> E;
};
vector<node> c;
int tot;

vector<int> rk;

struct SegTree{
    int n;
    vector<int> sum,max_x;
    
    void init(int n){
        this->n=n;
        sum.resize(n*4);max_x.resize(n*4);
    }

    void build(int x,int l,int r){
        if(l==r) {
            sum[x]=max_x[x]=c[rk[l]].w;
            return ;
        }
        int mid=(l+r)>>1;
        build(x<<1,l,mid);
        build(x<<1|1,mid+1,r);
        sum[x]=sum[x<<1]+sum[x<<1|1];
        max_x[x]=max(max_x[x<<1],max_x[x<<1|1]);
    }

    int query_max(int x,int l,int r,int ql,int qr){
        if(l>qr||r<ql) return -INF;
        if(ql<=l&&r<=qr) return max_x[x];
        int mid=(l+r)>>1;
        return max(query_max(x<<1,l,mid,ql,qr),query_max(x<<1|1,mid+1,r,ql,qr));
    }

    int query_sum(int x,int l,int r,int ql,int qr){
        if(l>qr||r<ql) return 0;
        if(ql<=l&&r<=qr) return sum[x];
        int mid=(l+r)>>1;
        return query_sum(x<<1,l,mid,ql,qr)+query_sum(x<<1|1,mid+1,r,ql,qr);
    }

    void update(int x,int l,int r,int pos,int val){
        if(l==r){max_x[x]=sum[x]=val;return ;};
        int mid=(l+r)>>1;
        if(pos<=mid)
            update(x<<1,l,mid,pos,val);
        else
            update(x<<1|1,mid+1,r,pos,val);
        sum[x]=sum[x<<1]+sum[x<<1|1];
        max_x[x]=max(max_x[x<<1],max_x[x<<1|1]);
    }
}st;

void add_e(int x,int y){
    c[x].E.push_back(y);
}

void dfs_1(int u,int f,int dp){
    c[u].dep=dp;c[u].fa=f;c[u].siz=1;
    int max_son=-1;
    for(auto& v:c[u].E){
        if(v==c[u].fa) continue;
        dfs_1(v,u,dp+1);
        c[u].siz+=c[v].siz;
        if(c[v].siz>max_son){max_son=c[v].siz,c[u].son=v;}
    }
}

void dfs_2(int u,int tp){
    c[u].id=++tot;rk[tot]=u;c[u].top=tp;
    if(c[u].son) dfs_2(c[u].son,tp);
    for(auto& v:c[u].E){
        if(v==c[u].fa||v==c[u].son) continue;
        dfs_2(v,v);
    }
}

int tree_query_max(int x,int y){
    int ret=-INF,fx=c[x].top,fy=c[y].top;
    while(fx!=fy){
        if(c[fx].dep>=c[fy].dep)
            ret=max(ret,st.query_max(1,1,n,c[fx].id,c[x].id)),x=c[fx].fa;
        else
            ret=max(ret,st.query_max(1,1,n,c[fy].id,c[y].id)),y=c[fy].fa;
        fx=c[x].top;fy=c[y].top;
    }
    if(c[x].id<c[y].id) //最后那条链上的一段
        ret=max(ret,st.query_max(1,1,n,c[x].id,c[y].id));
    else 
        ret=max(ret,st.query_max(1,1,n,c[y].id,c[x].id));
    return ret;
}

int tree_query_sum(int x,int y){
    int ret=0,fx=c[x].top,fy=c[y].top;
    while(fx!=fy){
        if(c[fx].dep>=c[fy].dep)
            ret+=st.query_sum(1,1,n,c[fx].id,c[x].id),x=c[fx].fa;
        else 
            ret+=st.query_sum(1,1,n,c[fy].id,c[y].id),y=c[fy].fa;
        fx=c[x].top;fy=c[y].top;
    }
    if(c[x].id<c[y].id)
        ret+=st.query_sum(1,1,n,c[x].id,c[y].id);
    else 
        ret+=st.query_sum(1,1,n,c[y].id,c[x].id);
    return ret;
}

void init(int n){
    c.resize(n+1);
    rk.resize(n+1);
    st.init(n);
}

int main(){
    freopen("P2590.in","r",stdin);
    freopen("P2590.out","w",stdout);
    n=read();int u=0,v=0;
    init(n);
    for(int i=1;i<n;i++){
        int x=read(),y=read();
        add_e(x,y);add_e(y,x);
    }
    for(int i=1;i<=n;i++)
        c[i].w=read();
    dfs_1(1,-1,1);
    dfs_2(1,1);
    st.build(1,1,n);
    int Q=read();
    while(Q--){
        string s;
        cin>>s;u=read(),v=read();
        if(s=="CHANGE") 
            st.update(1,1,n,c[u].id,v);
        if(s=="QMAX") 
            printf("%d\n",tree_query_max(u,v));
        if(s=="QSUM") 
            printf("%d\n",tree_query_sum(u,v));
    }
    return 0;
}