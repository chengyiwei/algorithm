#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

vector<int> ans;
void dfs(int x, vector<vector<int> > &g) {
	ans.push_back(x);
	for (auto &v : g[x]) 
		dfs(v, g);
}

int main() {
	int n; cin >> n;
	vector<int> du(n + 1, 0);
	vector<vector<int> > g(n + 1, vector<int> ());
	int rt = -1;
	for (int i = 1; i <= n; i++) {
		int f; cin >> f;
		if (f == 0) 
			rt = i; 
		else
			du[f] += 1, g[f].push_back(i);
	}
	int max_du = du[rt], flg = 1;
	for (int i = 1; i <= n; i++) {
		if (du[i] == 0) continue;
		max_du = max(max_du, du[i]); 
		if (du[i] != du[rt]) {
			flg = 0;
		}
	}
	printf ("%d %s\n",max_du, flg? "yes":"no");
	
	dfs(rt, g);
	
	for (int i = 0; i < ans.size(); i++) {
		printf ("%d%c", ans[i], i == ans.size() - 1? '\n' : ' ');
	}
	return 0;
} 
