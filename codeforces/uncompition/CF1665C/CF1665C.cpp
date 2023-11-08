#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int N,du[maxn];
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

priority_queue<int> pq;
void solve(){
    int num=0,cnt=0,ans=0;
    while(!pq.empty())pq.pop();
    memset(du,0,sizeof du);
    N=read();
    for(int i=1;i<N;i++){int fa=read();du[fa]++;}
    du[0]++;
    sort(du,du+1+N);
    for(int i=0;i<=N;i++)if(du[i]){
        num++;ans++;
        pq.push(max(du[i]-num,0));
    }
    while(cnt<pq.top()){
        cnt++;ans++;
        int now=pq.top()-1;
        pq.pop();
        pq.push(now);
    }
    printf("%d\n",ans);
    return ;
}
int main(){
    // freopen("CF1665C.in","r",stdin);
    int T=read();
    while(T--) solve();
    return 0;
}