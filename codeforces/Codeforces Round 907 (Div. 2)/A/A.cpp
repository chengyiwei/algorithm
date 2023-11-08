#include<bits/stdc++.h>
using namespace std;
int N,a[25];
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
bool solve(){
    N=read();
    for(int i=1;i<=N;i++) a[i]=read();
    for(int i=0;(1<<i)+1<=N;i++){
        int L=(1<<i)+1,R=min((1<<i+1),N);
        for(int j=L;j<R;j++){
            if(a[j]>a[j+1]) return 0;
        }
    }
    return 1;
}
int main(){
    // freopen("A.in","r",stdin);
    int T=read();
    while(T--){
        printf("%s\n",solve()?"YES":"NO");
    }
    return 0;
}