#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dfs (ll x) {
	if (x < 10) return 0;
	string s = to_string(x);
	ll ret = 1;
	for (auto & c : s) {
		ret = ret * (c - '0'); 
	}
	return dfs(ret) + 1;
}

int main() {
	ll L, R; cin >> L >> R;
	int max_x = -1;
	for (ll i = L; i <= R; i++) {
		max_x = max(max_x, dfs(i));
	}
	vector<ll> ans;
	for (ll i = L; i <= R; i++) {
		if (dfs(i) == max_x) 
			ans.push_back(i);
	}
	printf ("%d\n", max_x);
	for (int i = 0 ; i < ans.size(); i++) {
		printf ("%d%c",ans[i], (i == ans.size() - 1 ? '\n':' '));
	}
}
