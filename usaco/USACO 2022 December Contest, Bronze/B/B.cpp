#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("B.in","r",stdin);
    // freopen("B.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--) {
		int n;
		int k;
		cin >> n >> k;
		string s;
		cin >> s;
		int patchG = -k - 1; 
		int patchH = -k - 1; 
		int cnt = 0;
		string ans(n, '.');
		for (int i = 0; i < n; i++) {
			if (s[i] == 'G' && i - patchG > k) {
				// 最近的 G不能覆盖 i
				++cnt;
				if (i + k >= n) { //如果 超过N 了
					patchG = n-1;
					if (ans[patchG] == 'H') { patchG--; }
				} else {
					patchG = i + k; // i+k的位置放上 G
				}
				ans[patchG] = 'G';
			}
			if (s[i] == 'H' && i - patchH > k) {
				++cnt;
				if (i + k >= n) {
					patchH = n-1;
					if (ans[patchH] == 'G') { patchH--; }
				} else {
					patchH = i + k; 
				}
				ans[patchH] = 'H';
			}
		}
		cout << cnt << endl << ans << endl;
	}
    return 0;
}