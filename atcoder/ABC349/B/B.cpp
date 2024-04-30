#include <bits/stdc++.h>
using namespace std;
int main() {
    string s; cin >> s;
    vector<int> cnt(26, 0);
    for (auto c : s)
        cnt[c - 'a']++;
    map <int, int > mp;
    for (auto x : cnt) {
        if (!x) continue;
        if (!mp.count(x))
            mp[x] = 1;
        else
            mp[x]++;
    }
    for (auto x : mp) {
        if (x.second != 2)
            return cout << "No" << endl, 0;
    }
    return cout << "Yes" << endl, 0;
    return 0;
}