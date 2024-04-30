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
	int x = cnt[pos].x, y = cnt[pos].y;
	if (pos == id + 1) {
		for (int i = 1; i <= N; i++)
			if (sum_x[i] != L || sum_y[i] != L) return ;
		ans ++; return ;
	}
	int top = max(L - sum_x[x], L - sum_y[y]);
	for (int i = 0; i <= top; i++) {
		sum_x[x] += i; sum_y[y] += i;
		dfs(pos + 1);
		sum_x[x] -= i; sum_y[y] -= i;
	}
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
