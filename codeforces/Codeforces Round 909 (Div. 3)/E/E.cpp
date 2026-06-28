#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5,INF=2e9;
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
int a[maxn];
void solve(){
    int N=read();
    for(int i=1;i<=N;i++) a[i]=read();
    int Min=a[1],Min_i=1;
    for(int i=2;i<=N;i++){
        if(Min>a[i]) {Min=a[i];Min_i=i;}
    }
    for(int i=Min_i;i<N;i++){
        if(a[i]>a[i+1]) {printf("-1\n");return ;}
    }
    printf("%d\n",Min_i-1);
    return ;
}
int main(){
    // freopen("E.in","r",stdin);
    int T=read();
    while(T--)solve();
    return 0;
}