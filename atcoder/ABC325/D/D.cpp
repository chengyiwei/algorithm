#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 2e5 + 10;

LL l[N], r[N];
int p[N];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		LL x, y;
		scanf("%lld %lld", &x, &y);
		l[i] = x, r[i] = x + y;
		p[i] = i;
	}
	sort(p, p + n, [&](int i, int j) {
		return l[i] < l[j];
	});
	priority_queue<LL, vector<LL>, greater<LL>> pq;
	LL t = 0;
	int ret = 0;
	for (int i = 0; i < n; i++) {
		while (t < l[p[i]] && !pq.empty()) {
			LL x = pq.top();
			pq.pop();
			if (t <= x) t++, ret++;
		}
		t = l[p[i]];
		pq.push(r[p[i]]);
		if (i == n - 1) {
			while (!pq.empty()) {
				LL x = pq.top();
				pq.pop();
				if (t <= x) t++, ret++;
			}
		}
	}
	printf("%d", ret);
	
	return 0;
}