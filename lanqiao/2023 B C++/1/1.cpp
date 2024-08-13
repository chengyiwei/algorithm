#include <bits/stdc++.h>
using namespace std;

set<string> p;

bool check (string p) {
	if (p.substr(0, 4) != (string)"2023")
		return false;
	
}

int main() {
	char c;
	string s;
	while (cin >> c) {
		s.push_back(c);
	}
	int ans = 0;
	for (int i = 0; i + 8 - 1 < s.size(); i++) {
		if (check(s.substr(i, 8)))
			ans ++;
	}
	printf ("%d\n",ans);
	return 0;
} 
