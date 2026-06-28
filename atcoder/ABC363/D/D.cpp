#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    freopen ("D.in", "r", stdin);
    freopen ("D.out", "w", stdout);
    ios::sync_with_stdio(false);
    const int tp = 36;
    vector<ll> cnt(tp + 1, 1);
    for (int i = 1; i <= tp; i++) {
        int num = i + 1 >> 1;
        for (int j = 1; j <= num; j++)
            if (j == 1) cnt[i] *= 9;
            else cnt[i] *= 10;
    }
    cnt[1] = 10;

    ll N; cin >> N; ll N_ = N;
    int len = log10(N) + 1;
    if (N <= 10) {
        cout << N - 1 << endl;
        return 0;
    }
    N -= 1; N -= 10;

    for (int i = 2; i <= tp; i++) {
        len = i + 1 >> 1;
        if (N < cnt[i]) {
            if (i & 1) {
                string s = to_string(N); 
                while (s.size() < len) s = "0" + s;
                s[0] += 1;
                string t = s; s.pop_back(); t += string(s.rbegin(), s.rend());
                cout << t << endl;
            }
            else {
                string s = to_string(N); 
                while (s.size() < len) s = "0" + s;
                s[0] += 1;
                string t = s; s.reserve(); t += string(s.rbegin(), s.rend());
                cout << t << endl;
            }
            return 0;
        }
        N -= cnt[i];
    }
    return 0;
}