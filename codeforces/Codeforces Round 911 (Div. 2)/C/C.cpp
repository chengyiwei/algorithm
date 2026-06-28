#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=3e5+5;
char s[maxn];
struct node{
    char op;
    int L,R,F;
}t[maxn];

void dfs(int x){
    if(t[x].L==0&&t[x].R==0) {
        t[x].F=0;
        return ;
    }
    if(t[x].L) dfs(t[x].L);if(t[x].R) dfs(t[x].R);
    if(t[x].L==0) {
        t[x].F=t[t[x].R].F+(t[x].op!='R');
        return ;
    }
    if(t[x].R==0){
        t[x].F=t[t[x].L].F+(t[x].op!='L');
        return ;
    }
    
    if(t[x].op=='U') {
        t[x].F=min(t[t[x].L].F,t[t[x].R].F)+1;
        return ;
    }
    if(t[x].op=='L'){
        t[x].F=min(t[t[x].L].F,t[t[x].R].F+1);
        return ;
    }
    
    if(t[x].op=='R'){
        t[x].F=min(t[t[x].L].F+1,t[t[x].R].F);
        return ;
    }
    return ;
}
void solve(){
    int N=read();
    for(int i=1;i<=N;i++){
        char ch=getchar();
        // while(ch!='L'&&ch!='R'&&ch!='U') ch=getchar();
        t[i].op=ch;
    }
    for(int i=1;i<=N;i++){
        t[i].L=read(),t[i].R=read();
    }
    dfs(1);
    printf("%d\n",t[1].F);
    return ;
}
int main(){
    // freopen("C.in","r",stdin);
    int T=read();
    while(T--) solve();
}