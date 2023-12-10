#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=1e6+5;
LL a[maxn],b[maxn];
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

map<LL,int> mp;
LL ans;
int main(){
    freopen("B.in","r",stdin);
    int n=read(),m=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    mp[0]=0;
    for(int i=1;i<=m;i++){
        b[i]=read();
    }
    cout<<ans<<endl;
    return 0;
}