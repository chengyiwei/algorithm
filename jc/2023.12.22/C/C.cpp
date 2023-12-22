#include<bits/stdc++.h>
using namespace std;
#define int long long 
typedef long long LL;
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

int n,m;
vector<int> a,b;

bool check(LL k){
    LL cnt=0;
    queue<int> q;
    vector<LL> c(n+1,0);
    for(int i=1;i<=n;i++) if(b[i]) c[i]=k;
    for(int i=1;i<=n;i++){
        if(!q.empty()&&i-q.front()>k) cnt-=q.front(),q.pop();
        c[i]+=(k-i)*(LL)q.size()+cnt;
        if(b[i]){q.push(i);cnt+=i;}
    }
    while(!q.empty())q.pop();
    cnt=0;
    for(int i=n;i>=1;i--){
        if(!q.empty()&&q.front()-i>k) 
            cnt-=q.front(),q.pop();
        c[i]+=(i+k)*(LL)q.size()-cnt;
        if(b[i]){q.push(i);cnt+=i;}
    }
    for(int i=1;i<=n;i++)
        if(c[i]<a[i]) return false;
    return true;
}

signed main(){
    fin>>n>>m;
    a.assign(n+1,0);b.assign(n+1,0);
    int ans=0;
    for(int i=1;i<=n;i++) fin>>a[i];
    for(int i=1;i<=m;i++){int x;fin>>x;b[x]=1;}
    LL L=0,R=1e10;
    while(L<=R){
        LL mid=(L+R)>>1;
        if(check(mid)) 
            ans=mid,R=mid-1;
        else
            L=mid+1;
    }
    fout<<ans<<'\n';
    return 0;
}