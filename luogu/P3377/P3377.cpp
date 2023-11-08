#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int N,M;
int lc[maxn],rc[maxn],dist[maxn],rt[maxn];
bool vis[maxn];
struct node{
	int id,v;
	bool operator <(node B)const {return v<B.v||(v==B.v&&id<B.id);}
}v[maxn];
int getfa(int x){return rt[x]==x?x:rt[x]=getfa(rt[x]);}
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
int merge(int x,int y){
	if(!x||!y)return x+y; // 如果 x，y有一颗空树，那么就返回非空的那一颗
	if(v[y]<v[x])swap(x,y); // x 为小的那个，要把小的那个作为根节点
    lc[x]=lc[x];             // 左节点为原来的左节点
	rc[x]=merge(rc[x],y); // 右节点为右节点和 另外一课左偏树 的合并
	if(dist[lc[x]]<dist[rc[x]])swap(lc[x],rc[x]);  // 保证左偏，左边的 dist 较小 
	dist[x]=dist[rc[x]]+1; // 更新 dist[x]
	return x;
}
int main(){
    freopen("P3377.in","r",stdin);
	dist[0]=-1;
	N=read();M=read();
	for(int i=1;i<=N;i++)v[i].v=read(),v[i].id=i,rt[i]=i;
	for(int i=1;i<=M;i++){
		int op=read(),x=read();
		if(op==1){
			int y=read();
			if(vis[x]||vis[y])continue;
			x=getfa(x),y=getfa(y);
			if(x!=y)rt[x]=rt[y]=merge(x,y);
		}
		else{
			if(vis[x]){printf("-1\n");continue;}
			x=getfa(x);
			printf("%d\n",v[x].v);
			vis[x]=1;
			rt[lc[x]]=rt[rc[x]]=rt[x]=merge(lc[x],rc[x]);//删除根节点，把左儿子和右儿子合并
		}
	}
	return 0;
}