#include<cstdio>
#include<iostream>
#include<utility>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<set>
#include<map>
#include<set>
#include<array>
#include<random>
#include<bitset>
#include<ctime>
#include<limits.h>
#include<assert.h>
#include<unordered_set>
#include<unordered_map>
#define RI register int
#define CI const int&
#define mp make_pair
#define fi first
#define se second
#define Tp template <typename T>
using namespace std;
typedef long long LL;
typedef long double LDB;
typedef unsigned long long u64;
typedef pair <int,int> pi;
typedef vector <int> VI;
typedef array <int,3> tri;
const int N=300005;
int t,n,q,x,y,fa[N],p[N],a[N],sz[N],ret;
vector <int> v[N]; set <int> son[N];
inline int check(CI now)
{
	return a[now]==*son[now].begin()&&a[now]+sz[now]-1==*son[now].rbegin();
}
inline void DFS(CI now=1,CI fa=0)
{
	sz[now]=1; son[now].insert(a[now]);
	for (auto to:v[now]) if (to!=fa)
	{
		DFS(to,now); sz[now]+=sz[to];
		for (auto tmp:son[to]) son[now].insert(tmp);
	}
	ret+=check(now);
}
signed main()
{
	freopen("C.in","r",stdin); freopen("C0.out","w",stdout);
	for (scanf("%d",&t);t;--t)
	{
		scanf("%d%d",&n,&q); ret=0; fa[1]=0;
		for (RI i=1;i<=n;++i) v[i].clear(),son[i].clear();
		for (RI i=2;i<=n;++i) scanf("%d",&fa[i]),v[fa[i]].push_back(i);
		for (RI i=1;i<=n;++i) scanf("%d",&p[i]),a[p[i]]=i;
		for (DFS();q;--q)
		{
			scanf("%d%d",&x,&y);
			swap(p[x],p[y]); x=p[x]; y=p[y];
			vector <int> vec;
			for (int tmp=x;tmp;tmp=fa[tmp]) vec.push_back(tmp);
			for (int tmp=y;tmp;tmp=fa[tmp]) vec.push_back(tmp);
			sort(vec.begin(),vec.end());
			vec.erase(unique(vec.begin(),vec.end()),vec.end());
			for (auto p:vec) if (p) ret-=check(p);
			for (int tmp=x;tmp;tmp=fa[tmp]) son[tmp].erase(a[x]);
			for (int tmp=y;tmp;tmp=fa[tmp]) son[tmp].erase(a[y]);
			swap(a[x],a[y]);
			for (int tmp=x;tmp;tmp=fa[tmp]) son[tmp].insert(a[x]);
			for (int tmp=y;tmp;tmp=fa[tmp]) son[tmp].insert(a[y]);
			for (auto p:vec) if (p) ret+=check(p);
			puts(ret==n?"YES":"NO");
		}
	}
	return 0;
}