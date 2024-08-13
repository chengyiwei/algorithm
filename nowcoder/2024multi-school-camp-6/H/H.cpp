#include <bits/stdc++.h>
using namespace std;

bool check1 (string s) {
    int n = s.size(); s = " " + s;
    vector<int> sum(n + 1, 0);
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + (s[i] == '3');
    for (int l = 1; l + 10 - 1 <= n; l++) {
        int r = l + 10 - 1;
        if (sum[r] - sum[l - 1] == 10) return false;
    }
    return true;
}

bool check2(string s) {
    int n = s.size(); s = " " + s;
    vector<int> sum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (s[i] == '5' || s[i] == 'U') sum[i] = sum[i - 1] + 1;
        else sum[i] = sum[i - 1];
    }
    for (int l = 1; l + 90 - 1 <= n; l++) {
        int r = l + 90 - 1;
        if (sum[r] - sum[l - 1] == 0) return false;
    }
    return true;
}

bool check3 (string s) {
    char lst = ' ';
    for (auto ch: s) {
        if (ch == 'U' || ch == '5') {
            if (lst == '5' && ch == '5') return false;
            lst = ch;
        }
    }
    return true;
}

void solve() {
    string s; cin >> s;
    bool res = check1(s) && check2(s) && check3(s);
    cout << (res ? "valid" : "invalid") << '\n';
}

int main() {
    freopen ("H.in", "r", stdin);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}