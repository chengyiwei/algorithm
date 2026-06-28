#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
int a[maxn];
signed main(){
    // freopen("B.in","r",stdin);
    int T=read();
    while(T--){
        int N=read();
        for(int i=1;i<=N;i++) a[i]=read();
        int num=1,lst=a[N];
        for(int i=N-1;i;i--){
            if(a[i]<=lst){num+=1;lst=a[i];continue;}
            int K=a[i]/lst+(a[i]%lst!=0);
            lst=a[i]/K;
            num+=K;
        }
        printf("%lld\n",num-N);
    }
    return 0;
}