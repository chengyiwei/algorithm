#include <bits/stdc++.h>
using namespace std;
int main() {
	int n; cin >> n;
	vector<int> H(n);
	for (int i = 0; i < n; i++)
		cin >> H[i];
	int max_x = *max_element(H.begin(), H.end());
	vector<int> p(max_x + 1, 0);
	for (int i = 0; i < n; i++)
		p[H[i]]++;
	vector<int> res;
	for (int i = max_x; i; i--) {
		res.clear();
		for (int j = i; j <= max_x; j += i) {
			for (int k = 1; k <= p[j]; k++)
				res.push_back(j);
		}
		if (res.size() < 3) continue;
		sort(res.begin(), res.end());
		return cout << res[0] << ' ' << res[1] << ' ' << res[2] << '\n', 0;
	}
	return 0;
}