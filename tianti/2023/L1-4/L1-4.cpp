#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll n, m; cin >> n >> m;
	ll s = 0;
	for (int i = 1; i <= m; i++) {
		ll x; cin >> x;
		s += x;
	}
	cout << max(s - (m - 1) * n,0) << endl;
	return 0;
} 
