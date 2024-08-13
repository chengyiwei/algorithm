#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
const int maxn=55;
int a[maxn];
void solve(){
    int N=read(),X=read();;
    for(int i=1;i<=N;i++) a[i]=read();
    int ans=0,lst=0;
    for(int i=1;i<=N;i++) {
        int now=abs(lst-a[i]);lst=a[i];
        ans=max(ans,now);
    }
    ans=max(ans,abs((lst-X)*2));
    printf("%d\n",ans);
}
int main(){
    // freopen("A.in","r",stdin);
    int T=read();
    while(T--)solve();
}