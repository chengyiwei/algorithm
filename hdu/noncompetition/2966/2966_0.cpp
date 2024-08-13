#include<bits/stdc++.h>
using namespace std;
const int K = 2;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3f;
struct Point{
    LL dim[K];
};
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
LL dis(const Point &a,const Point &b){
    LL ret = 0;
    for(int i = 0;i < K;++i)
        ret += (LL)(a.dim[i]-b.dim[i])*(a.dim[i]-b.dim[i]);
    return ret;
}

int main(){
    freopen("2966.in","r",stdin);
    int T = read();
    while(T--){
        int n = read();
        vector<Point> q(n+1);
        for(int i=1;i<=n;++i)
            for(int j=0;j<K;++j)
                q[i].dim[j] = read();
        for(int i=1;i<=n;i++){
            LL ans = INF;
            for(int j=1;j<=n;j++){
                if(i == j) continue;
                ans = min(ans,dis(q[i],q[j])); 
            }  
            printf("%lld\n",ans);
        }
    }
}