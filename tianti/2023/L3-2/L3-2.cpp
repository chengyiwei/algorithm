#include <bits/stdc++.h>
using namespace std;


void solve() {
	int N, M, K; scanf("%d %d %d\n", &N, &M, &K);
	string S; cin >> S;
	vector<int> p; 
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == '1')
			p.push_back(i);
	}
	int L, R;
}

int main() {
	int T; scanf("%d", &T);
	while (T--) solve();
	return 0;
}
