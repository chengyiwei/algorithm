#include <bits/stdc++.h>
using namespace std;
const string tp = "<censored>";
int main() {
	int n; cin >> n;
	vector<string> p(n);
	for (auto &s : p)
		cin >> s;
	int top,cnt = 0; scanf("%d\n", &top);
	string T;
	getline(cin, T);
	string ans;
	int pos = 0;
	while (pos <= T.size()) {
		bool flg = 1;
		for (auto &s : p) {
//			if (pos + s.size() - 1 >= T.size()) continue;
			if (T.substr(pos, s.size()) == s) {
				ans += tp;
				cnt ++;
				pos += s.size();
				flg = 0;
				break;
			}
		}
		if (flg == 1) {
			ans.push_back(T[pos]);
			pos ++;
		}
	}
	if (cnt >= top)
		printf ("%d\nHe Xie Ni Quan Jia!\n", cnt);
	else
		cout << ans << endl;
	return 0;
}
