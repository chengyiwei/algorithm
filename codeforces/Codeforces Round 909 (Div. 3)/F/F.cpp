#include<bits/stdc++.h>
using namespace std;
const int maxn=505;
int d[maxn];
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
void solve(){
    int N=read(),Q=read();
    for(int i=1;i<=Q;i++){
        d[i]=read();
    }
    for(int i=1;i<N;i++) printf("%d %d\n",i,i+1);
    int lst=N-1;
    for(int i=1;i<=Q;i++){
        if(i==1&&d[i]==N-1) {printf("-1 -1 -1\n");continue;}
        if(d[i]==d[i-1])  {printf("-1 -1 -1\n");continue;}
        
        printf("%d %d %d\n",N,lst,d[i]);
        lst=d[i];
    }
    return ;
}
int main(){
    // freopen("F.in","r",stdin);
    // freopen("F.out","w",stdout);
    int T=read();
    while(T--)solve();
    return 0;
}