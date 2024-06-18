#include <bits/stdc++.h>
using namespace std;

bool solve() {
    string s; cin >> s;
    int n = s.size();
    string t;
    map<char, char> mp; 
    mp['('] = ')'; mp[')'] = '('; mp['['] = ']'; mp[']'] = '[';
    map<char, int> q; q['('] = 1, q[')'] = -1, q['['] = 2, q[']'] = -2;
    auto check = [&] (string t) {
        stack<int> stk;
        for (auto c : t) {
            if (q[c] > 0)
                stk.push(q[c]);
            else 
                if (stk.empty() || stk.top() != -q[c])
                    return 0;
                else 
                    stk.pop();
        }
        if (!stk.empty()) 
            return 0;
        return 1;
    };
    int cnt = 0;
    for (int S = 0; S < (1 << n); S++) {
        t.clear();
        for (int i = 0; i < s.size(); i++)
            if (S >> i & 1)
                t.push_back(mp[s[i]]);
            else 
                t.push_back(s[i]);
        if (check(t))
            cnt ++;
    }
    return cnt == 1;
}

int main() {
    freopen ("A.in", "r", stdin);
    freopen ("A1.out", "w", stdout);
    ios::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) 
        cout << (solve() ? "Yes\n" : "No\n");
    return 0;
}