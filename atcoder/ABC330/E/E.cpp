#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
map<int,int> mp;
int a[maxn];
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
int main(){
    freopen("E.in","r",stdin);
    int N=read(),Q=read();
    for(int i=1;i<=N;i++){
        a[i]=read();
        map<int,int>::iterator it=mp.find(a[i]);
        if(it!=mp.end())
            it->second++;
        else 
            mp[a[i]]=1;
    }
    for(int i=1;i<=Q;i++){
        int pos=read(),val=read();
        
        if(!--mp[a[pos]])
            mp.erase(a[pos]);
        
        a[pos]=val;
        map<int,int>::iterator it=mp.find(val);
        if(it!=mp.end())
            it->second++;
        else 
            mp[a[pos]]=1;
        
    }
}
