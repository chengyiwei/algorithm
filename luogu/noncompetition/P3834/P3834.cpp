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

inline void add_x(int x,int val){for(int i=x;i<=N;i+=i&-i)c[i]+=val;return ;}
inline int get(int x){int ret=0;for(int i=x;i;i-=i&-i)ret+=c[i];return ret;}

void solve(int lval,int rval,int st,int ed){  //lval rval 对于是值域  st en 对于是询问的序号 他是在值域上进行二分
	if(st>ed)return ;  // 如果没有对应的询问序号就返回
	if(lval==rval){for(int i=st;i<=ed;i++){if(q[i].op>0)ans[q[i].op]=lval;}return ;}  // 找到了对应的序号
	int mid=lval+rval>>1,lt=0,rt=0;
	for(int i=st;i<=ed;i++){
		if(q[i].op==0){  //把初始化看成时一次修改
			if(q[i].y<=mid)add_x(q[i].x,1),lq[++lt]=q[i]; //符合左边值域的修改，并在树状数组上面打上标记
			else rq[++rt]=q[i]; //符合右边值域的修改
		}
		else {
			int cnt=get(q[i].y)-get(q[i].x-1); //查询 [x,y] 有多少个被标记的位置
			if(q[i].z<=cnt)lq[++lt]=q[i]; // 如果 k <= cnt 说明最后的答案在左区间
			else q[i].z-=cnt,rq[++rt]=q[i]; // 否则答案就在右区间, q[i].z-=cnt 把在 [l,mid] 的那部分减掉
		}
	}
	for(int i=ed;i>=st;i--)if(q[i].op==0&&q[i].y<=mid)add_x(q[i].x,-1); //清空树状数组
	for(int i=1;i<=lt;i++)q[st+i-1]=lq[i];  //修改 q 数组,把属于左边的询问放在前面
	for(int i=1;i<=rt;i++)q[st+lt+i-1]=rq[i];  //把属于右边的询问放在后面
	solve(lval,mid,st,st+lt-1); solve(mid+1,rval,st+lt,ed);
	return ;
}
int main(){
    freopen("P3834.in","r",stdin);
	N=read();M=read();
	for(int i=1;i<=N;i++){++tot;q[tot].op=0;q[tot].x=i;q[tot].y=read();}
	for(int i=1;i<=M;i++){++tot;q[tot].op=i;q[tot].x=read(),q[tot].y=read(),q[tot].z=read();}
	solve(-INF,INF,1,tot);
	for(int i=1;i<=M;i++)printf("%d\n",ans[i]);
	return 0;
}