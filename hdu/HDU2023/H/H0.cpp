#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pil;
const ll MAXC = 505;
const ll MAXN = 5e4 + 5;
const ll INF = 2e9 + 5;
ll Tex = 1, n, a[MAXN], k;
bool check(ll x)
{
	ll s = 0;
	ll rp = upper_bound(a + 1, a + n + 1, x - a[1]) - a;
	rp --;
	for(int i = 1; i <= n; i ++)
	{
		ll l = i;
		while(a[l] + a[rp] > x) rp --;
		if(l >= rp) continue;
		s += (rp - l);
	}
	return s >= k;
}
void AC()
{
	cin >> n;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	cin >> k;
	ll l = 0, r = 2e9;
	while(l + 1 < r)
	{
		ll mid = l + r >> 1;
		if(check(mid)) r = mid;
		else l = mid;
	}
	cout << r << endl;
}
int main()
{
    freopen("H.in","r",stdin);
    freopen("H0.out","w",stdout);
	ios::sync_with_stdio(false);
	cin >> Tex;
	while(Tex --) AC();
	return 0;
}