#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return f*x;
}

void solve(){
    int n;
    string s;
    n=read();cin>>s;
    if(n>5) printf("sleep\n");
    else printf("%s\n",s.c_str());
    
}
int main(){
    // freopen("A.in","r",stdin);
    int T=read();
    while(T--) solve();
}