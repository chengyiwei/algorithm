#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
typedef long long LL;
int N,Q;
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

struct Bit{
    int a[65];
    Bit(){memset(a,0,sizeof a);}
    Bit operator +(const Bit B){
        Bit ret;
        for(int i=0;i<=60;i++)ret.a[i]=a[i]+B.a[i];
        return ret;
    }
    Bit operator -(const Bit B){
        Bit ret;
        for(int i=0;i<=60;i++)ret.a[i]=a[i]-B.a[i];
        return ret;
    }
}d[maxn],s[maxn];

LL PrintBit(Bit x){
    LL ret=0;
    for(int i=60;i>=0;i--)
        ret=(ret<<1)+(x.a[i]!=0);
    return ret;
}
Bit GetBit(LL x){
    Bit ret;
    int cnt=0;
    while(x){
        ret.a[cnt++]=x&1;
        x>>=1;
    }
    return ret;
}
int main(){
    freopen("C.in","r",stdin);
    fin>>N;
    for(int i=1;i<=N;i++){
        LL now;fin>>now; 
        if(now<0) 
            now=0;
        d[i]=GetBit(now);
        s[i]=s[i-1]+d[i];
    }
    fin>>Q;
    for(int i=1;i<=Q;i++){
        int L,R;fin>>L>>R;
        Bit ans=s[R]-s[L-1];
        fout<<PrintBit(ans)<<'\n';
    }
    
    return 0;
}