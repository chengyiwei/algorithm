#include<algorithm>
#include<stdio.h>
#include<math.h>
#include<set>
#include<bits/stdc++.h>
#define LL long long
using namespace std;
char c[6][1005][1005];
int T,n,m,h,K,v[6][1005][1005],hed,til,now,ed_x,ed_y;
struct wyj{
	int k,x,y;
}que[50000005];
LL read(){
	LL ret=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-f;ch=getchar();}
	while(ch<='9'&&ch>='0') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
int add(int k,int x,int y){
	if(x<=0||x>n||c[k][x][y]=='*') return 1;
	for(int p=-1;p<=1;p++){
		int kk=(k+1)%K,xx=x,yy=y+p;
		if(yy<=0||yy>m||c[k][xx][yy]=='*'||v[kk][xx][yy]) continue;
		que[++til]=(wyj){kk,xx,yy};v[kk][xx][yy]=now+1;
	}
	return 0;
}
void work(){
	memset(v,0,sizeof v);
	n=read();m=read();K=read();
	for(int k=0;k<K;k++)
	for(int i=1;i<=n;i++)scanf("%s",c[k][i]+1);
	h=read();ed_x=read();ed_y=read();
	if(ed_x==n&&ed_y==m){printf("1\n");return;}
	v[0][n][m]=1;
	hed=0;til=1;
	que[1]=(wyj){0,n,m};
	while(hed<til){
		wyj x=que[++hed];now=v[x.k][x.x][x.y];
		if(c[x.k][x.x][x.y]=='*') continue;
		if(x.x==ed_x&&x.y==ed_y){printf("%d\n",now-1);return;}
		if(x.x==n||c[x.k][x.x+1][x.y]=='*'){
			for(int i=0;i<=h;i++)
			if(add(x.k,x.x-i,x.y)) break;
		}
		else add(x.k,x.x+1,x.y);
	}
	printf("-1\n");
}
int main(){
    freopen("G.in","r",stdin);
    freopen("G0.out","w",stdout);
	T=read();
	while(T--) work();
	return 0;
}