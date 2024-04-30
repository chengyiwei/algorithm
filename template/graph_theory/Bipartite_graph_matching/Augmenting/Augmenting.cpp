#include<bits/stdc++.h>
using namespace std;
const int maxn=5005,maxe=1000005;
int N,M,E,vis[maxn],match[maxn],cnt,son[maxe],lnk[maxn],nxt[maxe],ans;
bool DFS(int x){
	for(int j=lnk[x];j;j=nxt[j]){
		if(!vis[son[j]]){
			vis[son[j]]=1;
			if(!match[son[j]]||DFS(match[son[j]])){ //如果没有被匹配或者 和son匹配的那个点 可以找到新的点匹配，那么son就和x匹配
				match[son[j]]=x;return 1;
			}
		}
	}
	return 0;
}
inline void add_e(int x,int y){son[++cnt]=y;nxt[cnt]=lnk[x];lnk[x]=cnt;}
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
int main(){
	N=read();M=read();E=read();
	for(int i=1;i<=E;i++){
		int x=read(),y=read();
		add_e(x,y+N);add_e(y+N,x);
	}
	for(int i=1;i<=N;i++){
		memset(vis,0,sizeof vis);
		if(DFS(i))ans++;
	}
	printf("%d\n",ans);
	return 0;
}