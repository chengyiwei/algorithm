#include <bits/stdc++.h>
using namespace std;
int mp[55][55];
int vis[55][55];
typedef pair<int, int> pii;
const int flg1[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
const int flg2[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
void solve() {
	int n, m;
	scanf ("%d %d\n", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char ch; scanf("%c",&ch);
			mp[i][j] = ch - 48;
		}
		scanf("\n");
	}
	queue<pii> q;
	memset(vis, 0, sizeof vis);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) if (mp[i][j] != 1) {
			if (i == 1 || i == n || j == 1 || j == m)
				q.push({i, j}), vis[i][j] = 1;
		}
	while (!q.empty()) {
		pii now = q.front(); q.pop();
		int x = now.first, y = now.second;
		for (int k = 0; k < 8; k ++) {
			int nx = x + flg1[k][0], ny = y + flg1[k][1];
			if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
			if (vis[nx][ny] || mp[nx][ny]) continue;
			vis[nx][ny] = 1;
			q.push({nx, ny});
		}
	}
	
	auto bfs = [&] (pii st) {
		queue<pii> q; q.push(st); vis[st.first][st.second] = 1;
		while (!q.empty()) {
			pii now = q.front(); q.pop();
			int x = now.first, y = now.second;
			for (int k = 0; k < 4; k ++) {
				int nx = x + flg2[k][0], ny = y + flg2[k][1];
				if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
				if (vis[nx][ny]) continue;
				vis[nx][ny] = 1;
				q.push({nx, ny});
			}
		}
	};
	
	int ans = 0;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++) if (!vis[i][j]){
			ans ++ ;
			bfs(make_pair(i, j));
		}
	printf ("%d\n", ans);
}
int main() {
	int t; scanf("%d", &t);
	while (t--) solve();
	return 0;
}
