#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 1e6 + 5;
const ll INF = 1e18 + 5;
ll Tex = 1, a, b, c, ans;
ll fastPow(ll a, ll b)
{
	ll res = 1;
	while(b)
	{
		if(b & 1) res *= a;
		a *= a;
		b >>= 1;
	}
	return res;
}
void AC()
{
	ans = INF;
	cin >> a >> b >> c;
	for(ll i = 0; i < 40; i ++)
	{
		ll dq = a * i + ceil((c * 1.0) / (fastPow(2, i))) * b;
		ans = min(ans, dq);
	}
	cout <<ans << endl;
}
int main()
{
	ios::sync_with_stdio(false);
	cin >> Tex;
	while(Tex --) AC();
	return 0;
} 