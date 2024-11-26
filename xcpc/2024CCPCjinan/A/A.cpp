#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, k; cin >> n >> m >> k;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    map<string, int> mp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int l = j * k;
            string t = s[i].substr(l, k);
            mp[t]++;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int l = j * k;
            string t = s[i].substr(l, k);
            if (mp[t] == 1) {
                cout << i + 1 << " " << j + 1 << endl;
                return 0;
            }
        }
    }
    return 0;
}