#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=2e5+5,INF=2e9;
int a[maxn];
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
void solve(){
    int N=read(),ans=0;
    int Max=-INF,Min=INF;
    for(int i=1;i<=N;i++) a[i]=read(),Max=max(Max,a[i]),Min=min(Min,a[i]);
    int now=Max-Min;
    while(now){
        now>>=1;
        ans++;
    }
    printf("%d\n",ans);
    if(ans<=N){
        for(int i=1;i<=ans;i++){
            int flg=0;
            if((Max&1)==0&&(Min&1)) flg=1;
            else if((Max&1)&&(Min&1)==0) flg=2;
            else flg=1;
            printf("%d ",flg);
            Max=(Max+flg)/2;
            Min=(Min+flg)/2;
        }
        if(ans)printf("\n");
    }
}
int main(){
    // freopen("C.in","r",stdin);
    int T=read();
    while(T--)solve();
}