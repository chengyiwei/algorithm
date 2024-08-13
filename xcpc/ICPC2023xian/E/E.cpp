#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 2e3+5;
ll n, m;
char x_line[MAXN][MAXN];
char y_line[MAXN][MAXN];
ll xs[MAXN][MAXN], ys[MAXN][MAXN];
bool dfs(ll x1, ll y1, ll x2, ll y2){
	bool p = 1;
	for(int i = x1 + 1; i <= x2 - 1; i ++){
		if(y2 - y1 == xs[i][y2] - xs[i][y1]){
			return dfs(x1, y1, i, y2) && dfs(i, y1, x2, y2);
		}
		else if(xs[i][y2] - xs[i][y1] > 0) p = 0;
	}
	for(int j = y1 + 1; j <= y2 - 1; j ++){
		if(x2 - x1 == ys[x2][j] - ys[x1][j]){
			return dfs(x1, y1, x2, j) && dfs(x1, j, x2, y2);
		}
		else if(ys[x2][j] - ys[x1][j] > 0) p = 0;
	}
	return p;
}
int main(){
	cin >> n >> m;
	n ++, m ++;
	for(int i = 2; i <= n - 1; i ++){
		ll sum = 0;
		for(int j = 2; j <= m; j ++){
			cin >> x_line[i][j];
			sum += x_line[i][j] == '1';
			xs[i][j] = sum;
		}
	}
	for(int i = 2; i <= n; i ++){
		for(int j = 2; j <= m - 1; j ++){
			cin >> y_line[i][j];
		}
	}
	for(int j = 2; j <= m - 1; j ++){
		ll sum = 0;
		for(int i = 2; i <= n; i ++){
			sum += y_line[i][j] == '1';
			ys[i][j] = sum;
		}
	}
	if(dfs(1, 1, n, m)) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
