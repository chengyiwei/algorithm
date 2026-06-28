#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
const int INF = 0x3f3f3f3f;

int n,D;
int a[maxn],F[maxn],ans,maxx;

int t[maxn<<2];
//线段树
void update(int x,int l,int r,int pos,int val){
    if(l == r){t[x] = max(t[x],val); return;}
    int mid = (l+r)>>1;
    if(pos <= mid) update(x<<1,l,mid,pos,val);
    else update(x<<1|1,mid+1,r,pos,val);
    t[x] = max(t[x<<1],t[x<<1|1]);
}

int query(int x,int l,int r,int ql,int qr){
    int ret = 0;
    if(ql <= l && r <= qr) return t[x];
    int mid = (l+r)>>1;
    if(ql <= mid)
        ret = max(ret,query(x<<1,l,mid,ql,qr));
    if(qr > mid)
        ret = max(ret,query(x<<1|1,mid+1,r,ql,qr));
    return ret;
}

int main(){
    freopen("E.in","r",stdin);
    scanf("%d%d",&n,&D);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),maxx = max(maxx,a[i]);
    for(int i=1;i<=n;i++){
        int ql = max(1,a[i]-D), qr = min(maxx,a[i]+D);
        F[i] = query(1,1,maxx,ql,qr)+1;
        update(1,1,maxx,a[i],F[i]);
        ans = max(ans,F[i]);
    }
    printf("%d\n",ans);
    return 0;
}