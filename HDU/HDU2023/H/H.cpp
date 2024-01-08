#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL INF=1e18;
int n,k;
vector<LL> a;

inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return f*x;
}

int check(LL S){
    int j=n;
    LL s_sm=0;
    for(int i=1;i<=n;i++){
        while(j>i&&a[j]+a[i]>=S) 
            j--;
        if(j<=i) break;
        s_sm+=j-i;
    }
    return s_sm<k;
}

void solve(){
    n=read();
    a.resize(n+1);
    for(int i=1;i<=n;i++)a[i]=read();
    k=read();
    sort(a.begin()+1,a.begin()+1+n);
    LL L=0,R=a[n]*2,mid,ans=INF;
    while(L<=R){
        LL mid=(L+R)/2;
        int now=check(mid);
        if(now) {L=mid+1;}
        else R=mid-1; 
    }
    // printf("%lld\n",R);
    LL S=R;
    int j=n;
    for(int i=1;i<n;i++){
        while(j>i&&a[j]+a[i]>=S){
            ans=min(a[j]+a[i],ans);
            j--;
        }
    }
    printf("%lld\n",ans);
}
int main(){
    freopen("H.in","r",stdin);
    freopen("H.out","w",stdout);
    int T=read();
    while(T--) solve();
}