#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int N,a[maxn],ans;
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
int main(){
    N=read();
    for(int i=1;i<=N;i++){
        a[i]=read();
    }
    for(int i=1;i<N;i++){
        if(abs(a[i]-a[i+1])!=1) ans++;
    }
    printf("%d\n",ans);
    return 0;
}