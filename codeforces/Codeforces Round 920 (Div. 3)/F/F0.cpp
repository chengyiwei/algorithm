#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0' || c>'9'){if(c=='-') f=-1;c=getchar();}
    while(c>='0' && c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}

struct Node{
    LL tsum,sum;
    int to;
    Node(int tsum=0,int sum=0,int to=0):tsum(tsum),sum(sum),to(to){}
};

void solve(){
    int n=read(),Q=read();
    int Block=sqrt(n),t=n/Block+(n%Block!=0);
    vector<int> a(n+1);

    for(int i=1;i<=n;i++) a[i]=read();
    while(Q--){
        int s=read(),d=read(),k=read();
        if(1){ 
            LL ans=0;
            for(int i=s,cnt=1;cnt<=k;i+=d,cnt++)
                ans+=a[i]*cnt;
            printf("%lld ",ans);
        }
    }
    printf("\n");
}

int main(){
    freopen("F.in","r",stdin);
    freopen("F0.out","w",stdout);
    int T=read();
    while(T--) solve();
}