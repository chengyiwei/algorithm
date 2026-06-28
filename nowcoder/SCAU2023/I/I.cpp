#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define int long long
using namespace std;

struct IO{
    static const int S=1<<21;
    char buf[S],*p1,*p2;int st[105],Top;
    ~IO(){clear();}
    inline void clear(){fwrite(buf,1,Top,stdout);Top=0;}
    inline void pc(const char c){Top==S&&(clear(),0);buf[Top++]=c;}
    inline char gc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;}
    inline IO&operator >> (char&x){while(x=gc(),x==' '||x=='\n'||x=='r');return *this;}
    template<typename T>inline IO&operator >> (T&x){
        x=0;bool f=0;char ch=gc();
        while(ch<'0'||ch>'9'){if(ch=='-') f^=1;ch=gc();}
        while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=gc();
        f?x=-x:0;return *this;
    }
    inline IO&operator << (const char c){pc(c);return *this;}
    template<typename T>inline IO&operator << (T x){
        if(x<0) pc('-'),x=-x;
        do{st[++st[0]]=x%10,x/=10;}while(x);
        while(st[0]) pc('0'+st[st[0]--]);return *this;
    }
}fin,fout;
typedef long long LL;
signed main(){
    freopen("I.in","r",stdin);
    // freopen("I.out","w",stdout);

    int n,k;fin>>n>>k; LL ans=0;k=min(k,n);
    
    int p=n;
    while(p>k) p-=(k-1);
    priority_queue<LL,vector<LL>,greater<LL> > q;
    
    for(int i=1;i<=n;i++){
        LL x;fin>>x;
        q.push(x);
    }
    if(1){
        LL now=0;
        for(int i=1;i<=p;i++){
            now+=q.top();q.pop();
        }
        ans+=now;
        q.push(now);
    }
    while(q.size()>1){
        if(q.size()>=k){
            LL now=0;
            for(int i=1;i<=k;i++)
                now+=q.top(),q.pop();
            ans+=now;
            q.push(now);
        }
    }
    fout<<ans<<'\n';
    return 0;
}