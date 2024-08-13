#include <bits/stdc++.h>
using namespace std;
int N, L;

int sum_x[5],sum_y[5];
int ans = 0;
struct node {
	int x, y;
}cnt[200];
int id;

void dfs (int pos) {
}

int main() {
	freopen ("A.in", "r", stdin);
	cin >> L >> N;
	for (int i = 1; i <= N; i++) {
		cnt[++id] = {i, i};
		for (int j = i + 1; j <= N; j++) {
			cnt[++id] = {i, j};
			cnt[++id] = {j, i};
		}
	}
	printf("%d\n",id);
	dfs(1);
	cout << ans ;
	return 0;
} 
