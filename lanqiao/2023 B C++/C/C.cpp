#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn][2];
int dp[10];
int main() {
//	freopen ("C.in" ,"r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		string s; cin >> s;
		a[i][0] = s.front() - '0'; a[i][1] = s.back() - '0';
	}
	for (int i = 1; i <= n; i++)
		dp[a[i][1]] = max(dp[a[i][1]], dp[a[i][0]] + 1);
	printf("%d\n", n - *max_element(dp, dp + 10));
	return 0; 
}
