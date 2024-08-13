#include<bits/stdc++.h>
using namespace std;
int rd(int x=0,char c=getchar()){int f=1;while(!isdigit(c))f=(c^'-'?1:-1),c=getchar();while(isdigit(c))x=x*10+(c^48),c=getchar();return x*f;}
const int N=505;
using ll=long long;
int n,f[N];
vector<int> E[N];
int t[N];
ll s[N],g[N];
int tot,id[N],pos[N];//id[i]表示第i个药的编号，pos[i]表示i是第几个药
ll dp[1<<10];
bitset<N> vis[1<<10];//记录哪些是已经用过的
signed main(){
	n=rd();
	for(int i=2;i<=n;i++){
		f[i]=rd();
		E[f[i]].push_back(i);
		t[i]=rd(),s[i]=rd(),g[i]=rd();
		if(t[i]==2)id[++tot]=i,pos[i]=tot;
	}
	// for(int i=1;i<=n;i++)cerr<<f[i]<<" "<<i<<endl;
	// for(int i=1;i<=tot;i++)cerr<<id[i]<<endl;
	using PII=pair<ll,int>;
	priority_queue<PII,vector<PII>,greater<PII> > q;//优先队列，第一个值代表s,第二个代表编号。
	ll now=1;
   //给dp[0]初始化
	for(int v:E[1])if(t[v]==1)q.push({s[v],v});//是敌人就入队。
	while(q.size()){
		int u=q.top().second;q.pop();
		if(now<s[u])break;//如果不行直接break
		now+=g[u];vis[0][u-1]=1;
		for(int v:E[u])if(t[v]==1){
			q.push({s[v],v});
		}
	}dp[0]=now;
	queue<int> Q;
	bitset<N> sp;
	if(now>=1e9){puts("Yes");return 0;}//因为s最大1e9，只要超过就说明一定可以。
	for(int i=1;i<(1<<tot);i++){
		dp[i]=-1e9;
		for(int j=0;j<tot;j++){
			if((i>>j)%2==0)continue;
			if(dp[i^(1<<j)]<0)continue;
			ll tmp=dp[i^(1<<j)]*g[id[j+1]];
			sp.reset();
			Q.push(1);
			int f=0;
		//判断转移状态能不能吃到第j+1个药
			while(Q.size()){
				int u=Q.front();Q.pop();
				for(int v:E[u]){
					if(v==id[j+1])f=1;
					if(vis[i^(1<<j)][v-1])Q.push(v);
				}
			}if(!f)continue;
			while(q.size())q.pop();
			for(int v:E[1])if(t[v]==1){
				if(vis[i^(1<<j)][v-1])//之前走到过了s就是0了。
				q.push({0,v});
				else
				q.push({s[v],v});
			}else if((i>>(pos[v]-1))&1){//注意只能走吃过的药。
				q.push({0,v});
			}
			while(q.size()){
				ll sb=q.top().first;
				int u=q.top().second;q.pop();
				if(tmp<sb)break;
				sp[u-1]=1;//标记走过了。
				if(!vis[i^(1<<j)][u-1]&&t[u]==1)tmp+=g[u];//只能加之前没吃过的敌人。
				for(int v:E[u])if(t[v]==1){
					if(!vis[i^(1<<j)][v-1])
					q.push({s[v],v});
					else
					q.push({0,v});
				}else if((i>>(pos[v]-1))&1){
					q.push({0,v});
				}
			}
			if(tmp>dp[i])
			dp[i]=tmp,vis[i]=sp;
			if(dp[i]>=1e9){
				puts("Yes");
				return 0;
			}
		}
	}
	ll ans=dp[(1<<tot)-1];
	// cerr<<ans<<endl;
	for(int i=1;i<=n;i++)if(t[i]==1)if(ans<s[i]){//判断是不是大于等于所有敌人。
		puts("No");
		return 0;
	}puts("Yes");
	return 0;
}