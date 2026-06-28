#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;
const int maxn = 5e5 + 5; 
ll a[maxn];
int nxt[maxn], pre[maxn];
int main() {
//	freopen ("F.in", "r", stdin);
	priority_queue<pli, vector<pli>, greater<pli> > pq;
	int n, k; scanf ("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf ("%lld", &a[i]);
		pq.push({a[i], i});
		nxt[i] = i + 1; pre[i] = i - 1;
	}
	nxt[0] = 1; pre[n + 1] = n;
	while (k--) {
		pli now = pq.top(); pq.pop();
		while (a[now.second] != now.first)
			now = pq.top(), pq.pop();
		a[now.second] = -1;
		if (nxt[now.second] != n + 1) {
			a[nxt[now.second]] += now.first;
			pq.push({a[nxt[now.second]], nxt[now.second]});
		}
		if (pre[now.second] != 0) {
			a[pre[now.second]] += now.first;
			pq.push({a[pre[now.second]], pre[now.second]});
		}
		
		nxt[pre[now.second]] = nxt[now.second];
		pre[nxt[now.second]] = pre[now.second];
	}
	for (int i = 1; i <= n; i++)
		if (a[i] != -1)
			printf ("%lld ", a[i]);
	return 0;
} 
