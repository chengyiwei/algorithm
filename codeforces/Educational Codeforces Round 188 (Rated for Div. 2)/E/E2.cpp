#include <bits/stdc++.h>
using namespace std;

int f(long long x) {
    int s = 0;
    while (x) s += x % 10, x /= 10;
    return s;
}

long long S(int x) {
    if (x < 10) return x;
    long long y = S(f(x)), t = y;
    while (t) x *= 10, t /= 10;
    return 1LL * x + y;
}

void solve() {
    string s;
    cin >> s;
    int n = s.size(), sum = 0;
    vector<int> cnt(10);
    for (char c : s) sum += c - '0', cnt[c - '0']++;

    if (n == 1) {
        cout << s << '\n';
        return;
    }

    for (int fx = max(1, sum - 100); fx <= sum; fx++) {
        long long suf = S(fx);
        if (fx + f(suf) != sum) continue;

        vector<int> need(10), rem = cnt;
        long long t = suf;
        while (t) need[t % 10]++, t /= 10;

        bool ok = 1;
        for (int i = 0; i < 10; i++) {
            if (need[i] > cnt[i]) ok = 0;
            rem[i] -= need[i];
        }
        if (!ok) continue;

        int len = n - (int)to_string(suf).size();
        if (len <= 0) continue;

        if (len == 1) {
            if (fx >= 10) continue;
            if (rem[fx] != 1) continue;
            ok = 1;
            for (int i = 0; i < 10; i++) {
                if (i != fx && rem[i]) ok = 0;
            }
            if (!ok) continue;
            cout << fx << suf << '\n';
            return;
        }

        string pre;
        for (int i = 1; i <= 9; i++) {
            if (rem[i]) {
                pre += char('0' + i);
                rem[i]--;
                break;
            }
        }
        if (pre.empty()) continue;

        for (int i = 0; i < 10; i++) {
            while (rem[i]--) pre += char('0' + i);
        }

        cout << pre << suf << '\n';
        return;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}