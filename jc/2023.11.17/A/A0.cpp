#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 2e5+5;
const ll INF = 1e5+5;
ll n,m;
struct edge{
	int u,v,w;
	edge(int a,int b,int c){u=a,v=b,w=c;}
};
vector<edge> mp[MAXN];
bool check(ll x)
{
	queue<ll> op;
	op.push(1);
	array<int,MAXN> flag{};
	flag[1]=1;
	while(!op.empty())
	{
		ll qwq=op.front();
		op.pop();
		for(int i=0;i<mp[qwq].size();i++)
		{
			int xx=mp[qwq][i].v;
			int yy=mp[qwq][i].w;
			if(flag[xx]) continue;
			if(yy>x) continue;
			op.push(xx);
			flag[xx]=1;
			if(xx==n) return true;
		}
	}
	return false;
}
int main()
{
    freopen("A.in","r",stdin);
    freopen("A0.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		mp[x].push_back(edge(x,y,z));
		mp[y].push_back(edge(y,x,z));
	}
	ll l=0,r=INF;
	while(l+1<r)
	{
		ll mid=(l+r)/2;
		if(check(mid)) r=mid;
		else l=mid;
	}
	if(r==INF) cout<<"-1"<<endl;
	else cout<<r<<endl;
	return 0;
}