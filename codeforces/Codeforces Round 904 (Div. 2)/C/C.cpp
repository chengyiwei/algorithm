#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

int T,N,M,tot,c[maxn<<1];
map<int,int> mp;
map<int,int>::iterator it;
struct line{
    int L,R;
}a[maxn];

void add_x(int x,int w){
    for(int i=x;i<=tot+1;i+=i&-i)
        c[i]+=w;
    return ;
}

int get_x(int x){
    int ret=0;
    for(int i=x;i>0;i-=i&-i)
        ret+=c[i];
    return ret;
}

int check(int pos){
    memset(c,0,sizeof c);
    for(int i=1;i<=N;i++){
        if(mp[a[i].L]<=pos&&mp[a[i].R]>=pos) continue;
        add_x(mp[a[i].L],1);add_x(mp[a[i].R]+1,-1);
    }
    int ans=0;
    for(int i=1;i<=tot;i++){
        ans=max(ans,get_x(i));
    }
    return ans;
}

int main(){
    // freopen("C.in","r",stdin);
    // freopen("C.out","w",stdout);
    T=read();
    while(T--){
        mp.clear();
        N=read();M=read();
        for(int i=1;i<=N;i++){
            a[i].L=read();a[i].R=read();
            mp[a[i].L]=1;mp[a[i].R]=1;
        }
        mp[1]=1;mp[M]=1;
        tot=0;
        for(it=mp.begin();it!=mp.end();++it){
            mp[(*it).first]=++tot;
        }
        printf("%d\n",max(check(mp[1]),check(mp[M])));
    }
    return 0;
}