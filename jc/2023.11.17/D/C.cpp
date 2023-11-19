#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5,maxe=maxn*2;
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

struct node{
    int x,y;
};
vector<node> Q;
int M,N;
vector<int> a;
int vis[maxn],num_m[maxn],num_n[maxn];

int fa[maxn];
int getfa(int x){
    return fa[x]==x?x:fa[x]=getfa(fa[x]);
}
int main(){
    freopen("C.in","r",stdin);
    // freopen("C.out","w",stdout);
    while(1){
        while(1){
            int x,y;fin>>x>>y;
            if(x==-1&&y==-1) return 0;
            else if(x==0&&y==0) break;
            M++;
            node now;
            now.x=x,now.y=y;
            Q.push_back(now);
            if(!vis[x]) a.push_back(x),vis[x]=1;
            if(!vis[y]) a.push_back(y),vis[y]=1;
        }
        int N=a.size();
        for(int i=0;i<N;i++) fa[a[i]]=a[i];
        for(int i=0;i<M;i++){
            int fx=getfa(Q[i].x),fy=getfa(Q[i].y);
            if(fx==fy)continue;
            fa[fx]=fy;
        }
        
        for(int i=0;i<N;i++){
            int fa=getfa(a[i]);
            num_n[fa]++;
        }
        for(int i=0;i<M;i++){
            int fa=getfa(Q[i].x);
            num_m[fa]++;
        }

        int F=getfa(a[0]);
        if(num_n[F]==N&&num_m[F]==N-1) printf("Yes\n");
        else printf("No\n");

        for(int i=0;i<N;i++) vis[a[i]]=0,fa[a[i]]=0,num_n[a[i]]=0,num_m[a[i]]=0;
        N=M=0;
        a.clear();Q.clear();
    }
    return 0;
}