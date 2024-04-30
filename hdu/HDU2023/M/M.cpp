#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int a[maxn],b[maxn];
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return f*x;
}
bool solve(){
    int n; n=read();
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<=n;i++) b[i]=read();
    sort(a+1,a+n+1);sort(b+1,b+n+1);
    for(int i=1;i<=n;i++) if(a[i]<b[i]) return 0;
    return 1;

}
int main(){
    int T=read();
    while(T--) printf("%s\n",solve()?"YES":"NO");
}