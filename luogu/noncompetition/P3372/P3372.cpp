#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long LL;

struct Seg_Tree{
    int n;
    vector<int> t,tag;

    Seg_Tree(int n){this->n=n;t.assign(n<<2,0);tag.assign(n<<2,0);}

    void push_up(int x){t[x]=t[x<<1]+t[x<<1|1];}

    void build(int x,int l,int r,vector<int>& a){
        if(l==r) {t[x]=a[l];return ;}
        int mid=(l+r)>>1;
        build(x<<1,l,mid,a);build(x<<1|1,mid+1,r,a);
        push_up(x);
    }

    void add_tag(int x,int l,int r,int val){
        t[x]+=val*(r-l+1);
        tag[x]+=val;
    }

    void push_down(int x,int l,int r){
        if(tag[x]){
            int mid=(l+r)>>1;
            add_tag(x<<1,l,mid,tag[x]);
            add_tag(x<<1|1,mid+1,r,tag[x]);
            tag[x]=0;
        }
    }

    void update(int x,int l,int r,int ql,int qr,int val){
        if(ql<=l&&r<=qr){  //完全覆盖，给这个结点打上 tag 不用深入了
            add_tag(x,l,r,val);
            return ;
        }
        push_down(x,l,r);
        int mid=(l+r)>>1;
        if(ql<=mid) update(x<<1,l,mid,ql,qr,val);
        if(qr>mid)  update(x<<1|1,mid+1,r,ql,qr,val);
        push_up(x);
    }

    int query(int x,int l,int r,int ql,int qr){
        if(ql<=l&&r<=qr) return t[x];
        push_down(x,l,r);
        int mid=(l+r)>>1,ret=0;
        if(ql<=mid) ret+=query(x<<1,l,mid,ql,qr);
        if(qr>mid)  ret+=query(x<<1|1,mid+1,r,ql,qr);
        return ret;
    }
};

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

signed main(){
    freopen("P3372.in","r",stdin);
    int n=read(),m=read();
    Seg_Tree T(n);
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++) a[i]=read();
    T.build(1,1,n,a);
    while(m--){
        int op=read();
        if(op==1){
            int ql=read(),qr=read(),v=read();
            T.update(1,1,n,ql,qr,v);
        }
        else{
            int ql=read(),qr=read();
            printf("%lld\n",T.query(1,1,n,ql,qr));
        }
    }
    return 0;
}