#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 105;
double p[maxn];
int cnt[maxn];
int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> p[i];
	double ans = 0;
	while (1) {
		int id, num; cin >> id >> num;
		if (id == 0 && num == 0) break;
		ans += p[id] * num;
		cnt[id] += num;
	}
	for (int i = 1; i <= n; i++)
		printf("%d\n", cnt[i]);
	printf("%.2lf", ans);
	return 0;
} 
