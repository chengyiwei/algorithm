#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
int N,Q;
int hsh[35],a[100005];
vector<int> q;
int Get(int x){
    int Len=q.size();
    for(int i=0;i<Len;i++){
        if(x%(1<<q[i])==0) x+=(1<<q[i]-1);
    }
    return x;
}
void solve(){
    memset(hsh,0,sizeof hsh);
    N=read(),Q=read();
    q.clear();
    for(int i=1;i<=N;i++)a[i]=read();
    for(int i=1;i<=Q;i++){
        int x=read();
        if(hsh[x])continue;
        hsh[x]=1;
        q.push_back(x);
    }
    for(int i=1;i<=N;i++){
        printf("%d ",Get(a[i]));
    }
    printf("\n");
    return ;
}
signed main(){
    // freopen("B.in","r",stdin);
    int T=read();
    while(T--){
        solve();
    }
    return 0;
}