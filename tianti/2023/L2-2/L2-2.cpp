#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll pp = 37;

map<ll,vector<string> > mp;

ll get_hash(vector<string>& p) {
	ll hsh = 0;
	for (auto &s : p) {
		hsh = hsh * pp + (s.front() - 'a' + 1);
	}
	return hsh;
}

int main() {
	freopen ("A.in" ,"r", stdin);
	int n; scanf("%d\n", &n);
	vector<string> now;
	for (int i = 1; i <= n; i++) {
		string s; getline(cin, s);
		now.clear();
		int pos = 0;
		while (pos < s.size()) {
			int j = pos;
			while (j < s.size() && s[j] != ' ') j++;
			now.push_back(s.substr(pos, j - pos));
			while (j < s.size() && s[j] == ' ') j++;
			pos = j;
		}
		ll hsh = get_hash(now);
		mp[hsh].push_back(s);
	}
	for (auto &x : mp) {
		sort(x.second.begin(), x.second.end());
	}
	int Q; scanf("%d\n", &Q);
	while (Q--) {
		string s; getline(cin, s); now.clear();
		int pos = 0;
		while (pos < s.size()) {
			int j = pos;
			while (j < s.size() && s[j] != ' ') j++;
			now.push_back(s.substr(pos, j - pos));
			while (j < s.size() && s[j] == ' ') j++;
			pos = j;
		}
		ll hsh = get_hash(now);
		if (!mp.count(hsh))
			printf("%s\n", s.c_str());
		else {
			for (int j = 0; j < mp[hsh].size(); j++) {
				printf("%s", mp[hsh][j].c_str());
				if (j != mp[hsh].size() - 1)
					printf("|");
			}
			printf("\n");
		}
	}
	return 0;
}
