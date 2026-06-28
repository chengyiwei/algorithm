#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
const int maxn=2e5+5;
int N,a[maxn];
void solve(){
    N=read();
    int ans=0;
    for(int i=1;i<=N;i++)a[i]=read();
    sort(a+1,a+1+N);
    int hed=1,til=N;
    int now=0,big;
    while(hed<=til){
        big=a[til];
        if(hed==til){
            printf("%lld\n",ans+min(a[til],(a[til]+1)/2+1));
            return;
        }
        while(hed<til&&now<=big) 
            now+=a[hed++];
        if(now<=a[til]){
            if(now==big){
                ans+=now+1;printf("%lld\n",ans);return ;
            }
            else{
                int derta=(a[til]-now)/2;
                if(now==0&&a[til]==1)
                    printf("%lld\n",ans+1);
                else 
                    printf("%lld\n",ans+now+derta+1+(a[til]-now-derta*2));return;
            }
        }
        else{
            ans++;ans+=big;til--;
            if(now!=big)
                a[--hed]=now-big;
            now=0;
        }
    }
    printf("%lld\n",ans);
}
signed main(){
    // freopen("C.in","r",stdin);
    // freopen("C.out","w",stdout);
    int T=read();
    while(T--) solve();
    return 0;
}