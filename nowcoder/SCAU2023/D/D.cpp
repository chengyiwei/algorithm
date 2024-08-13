#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=5e6+5;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
inline void write(int x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
}

int a[maxn],id[maxn],b[maxn/2];
LL ans=0;
int main(){
    freopen("D.in","r",stdin);
    int n,m;scanf("%d",&n);m=(n+1)/2;
    for(int i=1;i<=n;i++) a[i]=read(),id[i]=i;
    sort(id+1,id+n+1,[](int x,int y){return a[x]<a[y];});
    for(int i=1;i<=m;i++){
        ans+=a[id[i]];
        b[i]=id[i];
    }
    sort(b+1,b+m+1);
    printf("%lld\n",ans);
    for(int i=1;i<=m;i++) write(b[i]),putchar(' ');
    putchar('\n');
    return 0;
}