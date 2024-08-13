#include <bits/stdc++.h>
using namespace std;

inline int read() {
	int ret = 0,f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') {if (ch == '-') f = -f; ch = getchar();}
	while (ch <= '9' && ch >= '0') ret = ret * 10 + ch - 48, ch = getchar();
	return ret * f;
}

const int maxn = 15;
int T[maxn], D[maxn], L[maxn];
int id[maxn];
void solve() {
	int n = read();
	for (int i = 1; i <= n; i++)
		id[i] = i, T[i] = read(), D[i] = read(), L[i] = read();
	
	auto check = [&]() {
		int tim = 0;
		for (int i = 1; i <= n; i++) {
			auto x = id[i];
			if (tim > T[x] + D[x]) return false;
			if (tim < T[x]) tim = T[x];
			tim = tim + L[x];
		}
		return true;
	};
	
	do {
		if (check ()) {
			printf("YES\n");
			return;
		}
	}while (next_permutation(id + 1, id + 1 + n));
	printf("NO\n");
}

int main() {
//	freopen ("B.in", "r", stdin);
//	freopen ("B.out", "w", stdout);
	int t = read();
	while (t--) solve();
	return 0;
} 
