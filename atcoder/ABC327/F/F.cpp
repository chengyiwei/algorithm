#include<bits/stdc++.h>
using namespace std;
const int maxn=4e5+5;
int N,D,W,maxT;
int ans;

struct node{
    int T,X;
}a[maxn];


inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

bool cmp(node A,node B){
    return A.X<B.X||(A.X==B.X&&A.T>B.T);
}

int t[maxn<<2],lay[maxn<<2];

void push_down(int x){
    if(lay[x]){
        lay[x<<1]+=lay[x];
        lay[x<<1|1]+=lay[x];
        t[x<<1]+=lay[x];
        t[x<<1|1]+=lay[x];
        lay[x]=0;
    }
}

void push_up(int x){
    t[x]=max(t[x<<1],t[x<<1|1]);
}

void modify(int ql,int qr,int add_val,int l,int r,int x){
    push_down(x);
    if(ql<=l&&r<=qr) {
        t[x]+=add_val;
        lay[x]+=add_val;
        return ;
    } 
    int mid=(r+l)/2;
    if(ql<=mid) modify(ql,qr,add_val,l,mid,x<<1);
    if(mid<qr) modify(ql,qr,add_val,mid+1,r,x<<1|1);
    push_up(x);
}


int main(){
    freopen("F.in","r",stdin);
    freopen("F.out","w",stdout);
    N=read();D=read();W=read();
    for(int i=1;i<=N;i++) a[i].T=read(),a[i].X=read(),maxT=max(maxT,a[i].T);
    sort(a+1,a+1+N,cmp);
    int hed=1,til;
    for(til=1;til<=N;til++){
        modify(max(a[til].T-D+1,1),a[til].T,1,1,maxT,1);
        
        while(hed<til&&a[til].X-a[hed].X+1>W) {
            modify(max(a[hed].T-D+1,1),a[hed].T,-1,1,maxT,1); hed++;
        }

        int now=t[1];
        ans=max(ans,now);
    }
    cout<<ans<<endl;
    return 0;
}