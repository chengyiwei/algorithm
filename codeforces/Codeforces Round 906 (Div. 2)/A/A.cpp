#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int T,N;
int a[maxn];
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
map<int,int> mp;
bool solve(){
    mp.clear();
    for(int i=1;i<=N;i++) mp[a[i]]++;
    if(mp.size()==1) return 1;
    if(mp.size()>2)return 0;
    int now_1=a[1],now_2;
    for(int i=1;i<=N;i++)if(a[i]!=a[1]){
        now_2=a[i];break;
    }
    if(abs(mp[now_1]-mp[now_2])<=1) return 1;
    return 0;
}
int main(){
    // freopen("A.in","r",stdin);
    T=read();
    while(T--){
        N=read();
        for(int i=1;i<=N;i++)a[i]=read();
        printf("%s\n",solve()?"Yes":"No");
    }
    return 0;
}