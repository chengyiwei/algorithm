#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const vector<int> ip = {1,2,3,4,5,6,7,8,9};
const int n = 9;
int solve() {
	vector<vector<int> > mp(9, vector<int> (9));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> mp[i][j];
	
	vector<int> p;
	for (int i = 0; i < n; i++) {
		p.clear();
		for (int j = 0; j < n; j ++)
			p.push_back(mp[i][j]);
		sort(p.begin(), p.end());
		if (p != ip) return 0;
	}
	
	for (int j = 0; j < n; j++) {
		p.clear();
		for (int i = 0; i < n; i++)
			p.push_back(mp[i][j]);
		sort(p.begin(), p.end());
		if (p != ip) return 0;
	}
	
	for (int dx = 0; dx < 3; dx ++)
		for (int dy = 0; dy < 3; dy ++) {
			p.clear();
			for (int i = dx * 3; i < dx * 3 + 3; i ++)
				for (int j = dy * 3; j < dy * 3 + 3; j++)
					p.push_back(mp[i][j]);
			sort(p.begin(), p.end());
			if (p != ip) return 0;
		}
	return 1;
}

int main() {
	int t; cin >> t;
	while (t--) 
		printf ("%d\n", solve());
	return 0;
} 
