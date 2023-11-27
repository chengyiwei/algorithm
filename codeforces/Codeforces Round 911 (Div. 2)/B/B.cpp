#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

int check(int x,int y,int z){
    if((y^z)&1) return 0;
    return 1;  
}
void solve(){
    int a=read(),b=read(),c=read();
    int ans1=check(a,b,c),ans2=check(b,a,c),ans3=check(c,a,b);
    printf("%d %d %d\n",ans1,ans2,ans3);
    return ;
}
int main(){
    // freopen("B.in","r",stdin);
    int T=read();
    while(T--) solve();
}