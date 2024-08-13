#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 1e6 + 5;
ll Tex = 1, n;
vector<ll> a;
void AC()
{
	a.push_back(0);
	a.push_back(0);
	cin >> n;
	for(int i = 1; i <= n; i ++)
	{
		ll x;
		cin >> x;
		a.push_back(x);
	}
	sort(a.begin(), a.end(), greater<ll>());
	cout << a[0] + a[1] << endl;
}
int main()
{
	ios::sync_with_stdio(false);
//	cin >> Tex;
	while(Tex --) AC();
	return 0;
} 