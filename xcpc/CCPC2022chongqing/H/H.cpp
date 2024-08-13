#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=1e1+5,INF=1<<30;
int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
struct AS{
    int x,w;
}a[maxn];
bool cmp(AS A,AS B){return A.x<B.x;}
priority_queue<int,vector<int>> p;
void solve(){
    int n=read(); LL sum=0,ans=0;
    for(int i=1;i<=n;i++){
        a[i].x=read(),a[i].w=read();
    }
    sort(a+1,a+1+n,cmp);
    int pos=a[1].x;
    for(int i=1;i<=n;i++){
        while(!p.empty()&&pos<a[i].x){ //pos表示当前的数都在pos
            sum-=p.top();p.pop();
            ans+=sum;
            pos++;
        }
        pos=a[i].x;
        sum+=a[i].w;
        p.push(a[i].w);
    }
    while(!p.empty()){
        sum-=p.top();p.pop();
        ans+=sum;
    }
    printf("%lld\n",ans);
}

int main(){
    freopen("H.in","r",stdin);
    int T=read();
    while(T--) solve();
    return 0;
}