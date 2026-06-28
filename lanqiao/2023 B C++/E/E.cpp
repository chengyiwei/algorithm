#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int s_c1[maxn];
typedef long long ll;
int main() {
	int k; cin >> k;
	string s; cin >> s; s = " " + s;
	char c1, c2; cin >> c1 >> c2;
	for (int i = 1; i < s.size(); i++) {
		s_c1[i] = s_c1[i - 1] + (s[i] == c1);
	}
	ll ans = 0;
	for (int i = k; i < s.size(); i++) {
		if (s[i] == c2) {
			ans += s_c1[i - k + 1];
		}
	}
	cout << ans << endl;
	return 0;
} 
