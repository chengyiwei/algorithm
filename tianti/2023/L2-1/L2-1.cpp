#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
typedef pair<int, int> pii;
int vis[maxn];
int ans[maxn];
int main() {
	freopen ("A.in" ,"r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m; cin >> n >> m;
	vector<vector<int> > p(n + 1, vector<int> ());
	
	vector<int> now;
	for (int i = 1; i <= n; i++) {
		int k; cin >> k;
		p[i].resize(k + 1);
		for (int j = 1; j <= k; j++)
			cin >> p[i][j];
	}
	
	int q; cin >> q;
	vector<pii> Q(q + 1);
	for (int i = 1; i <= q; i++) {
		int x, y; cin >> x >> y;
		Q[i] = {x,y};
	}

	for (int i = 1; i <= n; i++) {
		for (auto &x : p[i])
			vis[x] = 1;
		for (int j = 1; j <= q; j++) {
			if (vis[Q[j].first] == 1 && vis[Q[j].second] == 1)
				ans[j] ++;
		}
		for (auto &x : p[i])
			vis[x] = 0;
	}	
	for (int j = 1; j <= q; j++)
		cout << ans[j] <<'\n';
	return 0;
} 
