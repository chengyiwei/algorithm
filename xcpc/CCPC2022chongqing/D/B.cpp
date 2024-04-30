#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 2e5+10;
const ll MOD = 1e9 + 7;
ll fa[MAXN], n, m;
void init_set()
{
	for(int i = 1; i < MAXN; i ++)
		fa[i] = i;
}
ll find_set(ll x)
{
	return fa[x] = fa[x] == x ? fa[x] : find_set(fa[x]);
} 
void union_set(ll x, ll y)
{
	x = find_set(x);
	y = find_set(y);
	if(x == y) return;
	fa[x] = fa[y];
}
ll fastPow(ll a, ll b)
{
	ll res = 1;
	while(b)
	{
		if(b & 1) res = (res * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	init_set();
	ll t = 0;
	for(int i = 1; i <= m; i ++)
	{
		ll x, y, z;
		cin >> x >> y >> z;
		for(int k = 0; k < z; k += 2, x += 2, y += 2)
		{
			ll px = find_set(x);
			ll py = find_set(y);
//			cout << px << " " << py << endl;
			if(px == py) t ++;
			if(t == 100) break;
			fa[px] = fa[py];
		}
	}
	ll cnt = 0;
	for(int i = 1; i <= n; i ++)
	{
		if(find_set(i) == i)
		{
//			cout << i << endl;
			cnt ++;
		}
	}
//	cout << cnt << endl;
	cout << fastPow(26, cnt) << endl;
	return 0;
}
