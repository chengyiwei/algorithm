#include <bits/stdc++.h> 
using namespace std;

auto manacher(string a) {
    string s = "$#";
    for (int i = 0; i < a.size(); i++) 
        s += a[i], s += '#';
    vector<int> d(s.size());
    d[1] = 1;
    for (int i = 2, l, r = 1; i < s.size(); i++) {
        if (i <= r) d[i] = min(r - i + 1, d[r - i + l]);
        while (s[i - d[i]] == s[i + d[i]]) d[i] ++;
        if (i + d[i] - 1 > r) 
            l = i - d[i] + 1, r = i + d[i] - 1;
    }
    return d;
}

int main() {
    freopen ("P3805.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s; cin >> s;
    auto d = manacher(s);
    cout << *max_element(d.begin(), d.end()) - 1 << endl;
    return 0;
}