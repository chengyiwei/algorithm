#include <bits/stdc++.h>
using namespace std;

bool check (string s) {
    if (s.size() != 5) return 0;
    if (s[2] != s[4]) return 0;
    map<char, int> mp;
    mp[s[0]]++; mp[s[1]]++; mp[s[2]]++; mp[s[3]]++;
    if (mp.size() != 4) return 0;
    return 1;
}

int main() {
    int n; cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        string s; cin >> s;
        ans += check(s);
    }
    cout << ans << endl;
    return 0;
}