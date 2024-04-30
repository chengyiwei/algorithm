#include<bits/stdc++.h>
using namespace std;
int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

vector<int> du;
void solve(){
    int n=read(),ans=0;
    du.assign(n+1,0);
    for(int i=1;i<n;i++){
        int x=read(),y=read();
        du[x]++;du[y]++;
    } 
    for(int i=1;i<=n;i++)
        if(du[i]==1) ans++;
    printf("%d\n",(ans+1)/2);
}
int main(){
    freopen("B.in","r",stdin);
    int T=read();
    while(T--) solve();
    
}