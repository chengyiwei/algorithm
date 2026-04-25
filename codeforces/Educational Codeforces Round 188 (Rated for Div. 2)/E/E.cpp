#include <bits/stdc++.h>
using namespace std;

int f(int x) {
    int ret = 0;
    while (x) {
        ret += x % 10; 
        x /= 10;
    }
    return ret;
}

int S(int x) {
    if (x < 10) return x;
    int Sfx = S(f(x));
    int _ = Sfx;
    while (_) x = x * 10, _ /= 10;
    x += Sfx;
    return x;
}

void solve() {
    string s; cin >> s;
    vector<int> cnt_(10, 0);
    int total = 0;
    for (int i = 0; i < s.size(); i++) total += s[i] - '0', cnt_[s[i] - '0'] += 1;

    auto check = [&] (int fx) {
        int Sfx = S(fx);

        
        if (fx + f(Sfx) != total) return false;


    };

    for (int fx = total - 100; fx <= total; fx++) {
    }
} 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << S(123)<< endl;
    // int t; cin >> t;
    // while (t--) solve();
    return 0;
}