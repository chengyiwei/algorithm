#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
const int maxn=2e5+5;
int a[maxn],X[maxn];
int main(){
    freopen("B.in","r",stdin);
    int N=read(),L=read(),R=read();
    for(int i=1;i<=N;i++){
        a[i]=read();
        if(a[i]<L) X[i]=L;
        else if(a[i]>R) X[i]=R;
        else X[i]=a[i];
    }
    for(int i=1;i<=N;i++)
        printf("%d ",X[i]);
}