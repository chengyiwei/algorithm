#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
inline char read_ch(){
	char ch=getchar();
	while(ch!='M'&&ch!='C')ch=getchar();
	return ch;
}
struct dsu{
    int n;
    vector<int> fa,d,siz;
    dsu(int n){
        this->n=n;
        fa.resize(n+1);d.resize(n+1);siz.resize(n+1);
        for(int i=1;i<=n;i++) fa[i]=i,d[i]=0,siz[i]=1;
    }
    int getfa(int x){
        if(fa[x]==x) return x;
        int root=getfa(fa[x]);
        d[x]+=d[fa[x]];
        return fa[x]=root;
    }
    void merge(int x,int y){
        int fx=getfa(x),fy=getfa(y);
        if(fx==fy) return ;
        fa[fx]=fy; // 把 x 的祖先连接到 y 的祖先上面去
        d[fx]=siz[fy];
        siz[fy]+=siz[fx];
    }
    int query(int x,int y){
        int fx=getfa(x),fy=getfa(y);
        if(fx!=fy) return -1;
        return abs(d[x]-d[y])-1;
    }
};

int main(){
    int Q;Q=read();
    dsu d(30000);
    while(Q--){
        char ch=read_ch();
        int x=read(),y=read();
        if(ch=='M') d.merge(x,y);
        else printf("%d\n",d.query(x,y));
    }
    return 0;
}