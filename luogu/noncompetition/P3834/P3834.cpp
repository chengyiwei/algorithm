#include<bits/stdc++.h>
using namespace std;
int N,M,tot;
const int maxn=200005,INF=1<<30;
struct AS{
	int x,y,z,op;
}q[maxn<<1],lq[maxn<<1],rq[maxn<<1];
int ans[maxn],c[maxn];

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline void add_x(int x,int val){
	for(int i=x;i<=N;i+=i&-i)c[i]+=val;
	return ;
}

inline int get(int x){
	int ret=0;
	for(int i=x;i;i-=i&-i)ret+=c[i];
	return ret;
}

void solve(int lval,int rval,int st,int ed){  //lval rval 对于是值域  st en 对于是询问的序号 他是在值域上进行二分
	if(st>ed)return ;
	if(lval==rval){
		for(int i=st;i<=ed;i++){
			if(q[i].op>0)ans[q[i].op]=lval;
		}
		return ;
	}
	int mid=lval+rval>>1;
	int lt=0,rt=0;
	for(int i=st;i<=ed;i++){
		if(q[i].op==0){  //把初始化看成时一次修改
			if(q[i].y<=mid)add_x(q[i].x,1),lq[++lt]=q[i]; //符合左边值域的修改
			else rq[++rt]=q[i]; //符合右边值域的修改
		}
		else {
			int cnt=get(q[i].y)-get(q[i].x-1);
			if(q[i].z<=cnt)lq[++lt]=q[i];
			else q[i].z-=cnt,rq[++rt]=q[i]; // q[i].z-=cnt 把在 [l,mid] 的那部分减掉
		}
	}
	for(int i=ed;i>=st;i--)
		if(q[i].op==0&&q[i].y<=mid)add_x(q[i].x,-1); //清空树状数组
	for(int i=1;i<=lt;i++)q[st+i-1]=lq[i];
	for(int i=1;i<=rt;i++)q[st+lt+i-1]=rq[i];
	solve(lval,mid,st,st+lt-1);
	solve(mid+1,rval,st+lt,ed);
	return ;
}
int main(){
	N=read();M=read();
	for(int i=1;i<=N;i++){
		++tot;
		q[tot].op=0;q[tot].x=i;q[tot].y=read();
	}
	for(int i=1;i<=M;i++){
		++tot;
		q[tot].op=i;q[tot].x=read(),q[tot].y=read(),q[tot].z=read();
	}
	solve(-INF,INF,1,tot);
	for(int i=1;i<=M;i++)printf("%d\n",ans[i]);
	return 0;
}