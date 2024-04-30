#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int ans[maxn];
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
int main(){
    freopen("P9780.in","r",stdin);
    M=read();K=read();
    for(int i=1;i<=M;i++) a[i]=read();
    int num;
    for(int i=N;i>1;i--){
        if(a[i]>a[i-1]) num++;
        ans[(i-1)+num]
    }
}