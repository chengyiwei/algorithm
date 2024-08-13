#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

bool solve(){
    int x=read();
    if(x==1) return 1;
    if(x==2||x==3) return 0;
    if(x%2==0) return 1;
    int sq=sqrt(x);
    if(sq*sq==x) return 1;
    if(x>=9&&x%4==1) return 1;
    return 0;
}
int main(){
    freopen("A.in","r",stdin);
    int T=read();
    while(T--){
        printf("%s\n",solve()?"Yes":"No");
    }
}