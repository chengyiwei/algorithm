#include<bits/stdc++.h>
#include <unordered_map>
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

unordered_map<LL,int> mp;
LL ans;
int main(){
    freopen("B.in","r",stdin);
    int n=read(),m=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
        if(mp.find(a[i]*i)==mp.end())
            mp[a[i]*i]=1;
        else
            mp[a[i]*i]++;
    }
    mp[0]=0;
    for(int i=1;i<=m;i++){
        b[i]=read();
        if(mp.find(b[i]*i)!=mp.end())
            ans+=mp[i*b[i]];
    }
    cout<<ans<<endl;
    return 0;
}