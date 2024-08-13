#include<bits/stdc++.h>
using namespace std;
int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
int n;
bool run(int x,int k,int op,int y){
    if(op==0){
        for(;x>=1;x-=k)
            if(x==y) return 1;
    }
    else {
        for(;x<=n;x+=k)
            if(x==y) return 1;
    }
    return 0;
}
bool solve(){
    n=read();
    int k=read(),x=read(),y=read();
    if(run(x,k,1,y)) return 1;
    if(run(x,k,0,y)) return 1;
    if(run(1,k,1,y)) return 1;
    if(run(n,k,0,y)) return 1;
    return 0;
}
int main(){
    freopen("F.in","r",stdin);
    int T=read();
    while(T--) printf("%s\n",solve()?"YES":"NO");
    return 0;
}