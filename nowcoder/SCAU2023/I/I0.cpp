
#include<bits/stdc++.h>
#define int __int128
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
LL ans=0;
signed main(){
   freopen("I.in","r",stdin);
   freopen("I0.out","w",stdout);
    int n,k;fin>>n>>k;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++)
        fin>>a[i];
    sort(a.begin()+1,a.begin()+n+1);
    int now_mul=1,cnt=0;
    for(int i=n;i;i--){
        ++cnt;
        if(cnt==k&&i!=1){cnt=1;now_mul++;}
        ans+=(LL)now_mul*a[i];
    }
    fout<<ans<<'\n';
    return 0;
}
