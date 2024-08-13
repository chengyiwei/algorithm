#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
typedef pair<int,int> pii;
int mp[maxn][maxn];
const int flg[4][2] = {{-1, 0}, {0,1}, {1,0}, {0,-1}};
int vis[maxn][maxn], dis[maxn][maxn];
pii S;

map<int, vector<int> > T;

int main() {
	freopen ("A.in" ,"r", stdin);
	int n, m;
	scanf ("%d %d\n", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			scanf("%d", &mp[i][j]);
			if (mp[i][j] == 2) 
				S = {i, j};
		}
	queue<pii> q; q.push(S); vis[S.first][S.second] = 1; 
	memset(dis, -1, sizeof dis); dis[S.first][S.second] = 0;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second; q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + flg[k][0], ny = y + flg[k][1];
			if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
			if (vis[nx][ny] || mp[nx][ny] == 0) continue;
			vis[nx][ny] = 1; dis[nx][ny] = dis[x][y] + 1;
			q.push({nx,ny});
		}
	}
	
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++)
//			printf("%d ", dis[i][j]);
//		printf("\n");
//	}
	
	int K; scanf("%d", &K);
	for (int i = 1; i <= K; i++) {
		int id = i;
		int x, y; scanf("%d %d\n", &y, &x);
		if (dis[x][y] == -1) continue;
		T[dis[x][y]].push_back(id);
	}
	for (auto &u : T) {
		if (u.second.size() == 1) {
			printf("%d %d\n", u.second.front(), u.first);
			return 0;
		}
	}
	printf ("No winner.");
	return 0;
	 
} 
