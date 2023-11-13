#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int N,M;
struct Tree{
    int a[maxn],sum[maxn<<1],lay[maxn<<1];

    void pushup(int now){
        sum[now]=sum[now<<1]+sum[now<<1|1];
    }

    void pushdown(int len,int now){
        if(lay[now]){
            lay[now]=lay[now]*(len);
            if(len==1){
                lay[now<<1]+=lay[now];
                lay[now<<1|1]+=lay[now];
            }
            lay[now]=0;
        }
    }

    void build(int l,int r,int now){
        if(l==r){sum[now]=a[l];return ;}
        int mid=(r-l>>1)+l;
        build(l,mid,now<<1);build(mid+1,r,now<<1|1);
        pushup(now);
    }

    void update(int l,int r,int ql,int qr,int now){
        if(l==r){}
    }

    int query_sum(int l,int r,int ql,int qr,int now){
        pushdown(r-l+1,now);
        if(l<=ql&&qr<=r) return sum[now];
        int mid=(r-l>>1)+l,sum=0;
        if(l<=mid) sum+=query_sum(l,r,ql,mid,now<<1);
        if(r>mid) sum+=query_sum(l,r,mid+1,qr,now<<1|1);
        return sum;
    }
}T;

inline LL read(){
    LL ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
int main(){
    freopen("P3372.in","r",stdin);
    N=read();M=read();
    for(int i=1;i<=N;i++)
        T.a[i]=read();
    T.build(1,N,1);
    for(int i=1;i<=M;i++){
        int x=read();
        if(x==1){
            int L=read(),R=read(),k=read();
            T.
        }
    }
}