#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q; cin >> n >> q;
    string s; cin >> s;
    map<string, int> mp;

    mp["ca"] = mp["cb"] = mp["ba"] = mp["bc"] = mp["ac"] = mp["ab"] = 0;


    while (q--) {
        char x, y; cin >> x >> y;
        string now; now += x; now += y;
        mp[now] += 1;
    }

    auto check = [&] (auto && check, string str, string pre) -> int {   
        if (str == "ca") {
            if (mp["ca"] > 0) return 1;
            if (pre != "ba" && check(check, "cb", str) && check(check, "ba", str)) return 1;
            return 0;
        }

        if (str == "ba") {
            if (mp["ba"] > 0) return 1;
            if (pre != "ca" && check(check, "bc", str) && check(check, "ca", str)) return 1;
            return 0;
        }
        if (mp[str] > 0)return 1;
        else return 0;
    };

    auto calc = [&] (auto && calc, string str) -> void {
        if (str == "ca") {
            if (mp["ca"] > 0) {
                mp["ca"] -= 1;
                return;
            }
            calc(calc, "cb"); calc(calc, "ba");
            return;
        }

        if (str == "ba") {
            if (mp["ba"] > 0) {
                mp["ba"] -= 1;
                return;
            }
            calc(calc, "bc"); calc(calc, "ca");
            return;
        }
        
        mp[str] -= 1;
        return ;
    };

    for (auto &c : s) {
        auto b = c;
        if (b == 'a') continue;
        else if (b == 'b') {
            if (check(check, "ba", "  ")) {
                calc(calc, "ba");
                b = 'a';
            }
        }
        else if (b == 'c') {
            if (check(check, "ca", "  ")) {
                calc(calc, "ca");
                b = 'a';
            }
            else if (check(check, "cb", "  ")) {
                calc(calc, "cb");
                b = 'b';
            }
        }
        c = b;
        // cout << c << "\n";
    }
    cout << s << "\n";
}

int main() {
    freopen ("E.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}
