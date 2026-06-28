#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+5;
map<int,int> mp;
int a[maxn],num[maxn];
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
set<int> p;
int main(){
    freopen("E.in","r",stdin);
    int N=read(),Q=read();
    for(int i=1;i<=N;i++){
        a[i]=read();
        a[i]=min(a[i],N+10);
        num[a[i]]++;
    }
    for(int i=0;i<=N+10;i++){
        if(num[i]==0) p.insert(i);
    }
    for(int i=1;i<=Q;i++){
        int pos=read(),val=read();
        val=min(val,N+10);
        if(!--num[a[pos]]){
            p.insert(a[pos]);
        }
        a[pos]=val;
        if(!num[a[pos]]++){
            auto it=p.find(a[pos]);
            if(it!=p.end()) 
                p.erase(it);
        }
        auto it=p.begin();
        printf("%d\n",*it);
    }
    return 0;
}
