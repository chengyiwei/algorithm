#include <bits/stdc++.h>
using namespace std;

bool solve() {
    string s;
    int n; cin >> n;
    cin >> s;
    for (int i = 0; i + 1 < s.size() ; i++) {
        if (s[i] >= 'a' && s[i] <= 'z' && s[i + 1] >= '0' && s[i + 1] <= '9') {
            return false;
        }
    }
    vector<char> num , ch;
    for (auto c : s) 
        if (c >= '0' && c <= '9') 
            num.push_back(c);
        else 
            ch.push_back(c);
    auto num_ = num;
    sort(num_.begin(), num_.end());
    if (num_ != num) 
        return false;
    auto ch_ = ch;
    sort(ch_.begin(), ch_.end());
    if (ch_ != ch) 
        return false;
    return true; 
}

int main() {
    freopen ("A.in", "r", stdin);
    int t; cin >> t;
    while (t--) 
        if (solve())
            cout << "YES" << '\n';
        else 
            cout << "NO" << '\n';
}