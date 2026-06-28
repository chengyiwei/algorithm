#include<bits/stdc++.h>
using namespace std;
int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
void solve(){
    int a=read(),b=read();
    printf("%d\n",max(a,b));
}
int main(){
    freopen("A.in","r",stdin);
    int T=read();;
    while(T--) solve();
}