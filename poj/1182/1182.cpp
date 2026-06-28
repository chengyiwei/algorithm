#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int ans;
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
struct dsu{
    int n;
    vector<int> fa,d;
    dsu(int n){
        this->n=n;
        fa.resize(n+1);d.resize(n+1);
        for(int i=1;i<=n;i++) fa[i]=i,d[i]=0;
    }
    int getfa(int x){
        if(fa[x]==x) return x;
        int root=getfa(fa[x]);
        d[x]=(d[x]+d[fa[x]])%3;
        return fa[x]=root;
    }
    void merge(int x,int y,int v){
        int fx=getfa(x),fy=getfa(y);
        if(fx==fy) {
            if((v-1)!=((d[x]-d[y]+3)%3)) 
                ans++;
        }
        else{
            fa[fx]=fy;
            d[fx]=(d[y]-d[x]+v-1)%3;
        }
    }
};
int main(){
    // freopen("1182.in","r",stdin);
    int n,k;fin>>n>>k;
    dsu d(n);
    while(k--){
        int v,x,y;fin>>v>>x>>y;
        if(x>n||y>n||(v==2&&x==y)) ans++;
        else d.merge(x,y,v);
    }
    fout<<ans;
    return 0;
}