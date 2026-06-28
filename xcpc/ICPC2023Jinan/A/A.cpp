#include <bits/stdc++.h>
using namespace std;

bool solve() {
    map<char, int> mp; mp['('] = 0, mp[')'] = 0, mp['['] = 1, mp[']'] = 1;
    string s; cin >> s;
    stack<int> stk;
    for (auto c : s) {
        if (!stk.empty() && mp[c] == stk.top())
            stk.pop();
        else 
            stk.push(mp[c]);
    }
    if (!stk.empty())
        return 0;
    int num_0 = 0, num_1 = 0;
    for (int i = 0; i < s.size(); ) {
        int j = i;
        while (j < s.size() && mp[s[i]] == mp[s[j]]) j += 1;
        int l = j - i;
        if (l >= 3)
            return 0;
        if (mp[s[i]] == 0)
            num_0 += l / 2;
        else 
            num_1 += l / 2;
        i = j;
    }
    if (num_0 + num_1 >= 3)
        return 0;
    return 1;
}

int main() {
    freopen ("A.in", "r", stdin);
    freopen ("A.out", "w", stdout);
    ios::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) 
        cout << (solve() ? "Yes\n" : "No\n");
    return 0;
}