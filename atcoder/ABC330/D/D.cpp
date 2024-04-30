#include<bits/stdc++.h>
using namespace std;
const int maxn=2005;
int N,M;
int a[maxn][maxn];
int L[maxn],C[maxn];
long long ans;
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
int main(){
    freopen("D.in","r",stdin);
    N=read();
    for(int i=1;i<=N;i++)
    for(int j=1;j<=N;j++){
        char ch=getchar();
        while(ch!='o'&&ch!='x') ch=getchar();
        if(ch=='o') a[i][j]=1;
        else a[i][j]=0;
        L[i]+=a[i][j];
        C[j]+=a[i][j];
    }
    for(int i=1;i<=N;i++)
    for(int j=1;j<=N;j++)
        if(a[i][j])
            ans+=(L[i]-1)*(C[j]-1);
    printf("%lld\n",ans);
}