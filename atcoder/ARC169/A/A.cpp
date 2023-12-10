#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 1e6+5;
ll n, a[MAXN], p[MAXN], sum;
vector<ll> mp[MAXN];
ll dfs(ll x)
{
	ll sum = 0;
	for(int i = 0; i < mp[x].size(); i ++)
		sum += dfs(mp[x][i]);
	return 
}
int main()
{
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	for(int i = 2; i <= n; i ++)
	{
		cin >> p[i];
		mp[p[i]].push_back(i);
	}
	ll p = dfs(1);
	if(p > 0) cout << "+" << endl;
	else if(p < 0) cout << "-" << endl;
	else cout << 0 << endl;
	return 0;
} 
