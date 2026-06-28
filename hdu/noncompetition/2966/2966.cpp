#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e5 + 10, K = 2;

int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

struct Point{
    LL dim[K];
};
Point q[maxn],t[maxn];

int now;

bool cmp(const Point &a,const Point &b){
    return a.dim[now] < b.dim[now];
}

LL dis(const Point &a,const Point &b){
    LL ret = 0;
    for(int i = 0;i < K;++i)
        ret += (LL)(a.dim[i]-b.dim[i])*(a.dim[i]-b.dim[i]);
    return ret;
}

void build(int L,int R,int dep){
    if(L > R) return ;
    int d = dep % K, mid = (L+R)/2; now = d;
    nth_element(t+L,t+mid,t+R+1,cmp);
    build(L,mid-1,dep+1); build(mid+1,R,dep+1);
}

LL ans = INF;

void query(int L,int R,int dep,Point p){
    if(L > R) return ;
    int mid = (L+R)/2;
    int d = dep % K;
    LL min_dis = dis(t[mid],p);
    if(min_dis != 0) ans = min(ans,min_dis);
    if(p.dim[d] <= t[mid].dim[d]){
        query(L,mid-1,dep+1,p);
        if(ans > (LL)(p.dim[d]-t[mid].dim[d])*(p.dim[d]-t[mid].dim[d]))
            query(mid+1,R,dep+1,p);
    }
    else{
        query(mid+1,R,dep+1,p);
        if(ans > (LL)(p.dim[d]-t[mid].dim[d])*(p.dim[d]-t[mid].dim[d]))
            query(L,mid-1,dep+1,p);
    }
}

int main(){
    freopen("2966.in","r",stdin);
    int T = read();
    while(T--){
        int n = read();
        for(int i=1;i<=n;i++){
            for(int j=0;j<K;j++)
                q[i].dim[j] = read();
            t[i] = q[i];
        }
        build(1,n,0);
        for(int i=1;i<=n;i++){
            ans = INF;
            query(1,n,0,q[i]);
            printf("%lld\n",ans);
        }
    }
    return 0;
}