#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 5e5 + 5;
ll Tex, q;
string s;
void AC() {
    cin >> s;
    vector<ll> a;
    ll n = s.size(), ft = -1;
    for (int i = 0; i < n; i ++) {
        if(s[i] == 'R') {
            a.push_back(i - ft - 1);
            // cout << i - ft - 1 << " ";
            ft = i;
        }
    }
    // cout << " " << a.size() << "\n";
    cin >> q;
    while(q --) {
        string ask;
        cin >> ask;
        if (ask[0] == 'R' && s[0] != 'R') {
            cout << "NO\n";
            continue;
        }
        if (ask.back() == 'L' && s.back() != 'L') {
            cout << "NO\n";
            continue;
        }
        int cnt = 0, idx = 0, flag = 0;
        for (int i = 0; i < ask.size(); i ++) {
            // cout << " * " << i << " " << cnt << "\n";
            if (ask[i] == 'L') {
                cnt ++;
            }
            else {
                if (idx == a.size()) {
                    flag = 1;
                    break;
                }
                int sum = a[idx];
                idx ++;
                // cout << "R : " << i << " " << sum << " " << cnt << "\n";
                while (sum < cnt && idx < a.size()) {
                    // cout << idx << " " << a[idx] << " " << a.size() << "\n";
                    sum += a[idx];
                    idx ++;
                }
                if (sum < cnt) {
                    flag = 1;
                    break;
                }
                // cout << "R : " << i << " " << sum << " " << cnt << "\n";
                cnt = 0;
            }
        }
        if (flag) {
            cout << "NO\n";
            continue;
        }
        if (cnt) {
            a.push_back(n - ft - 1);
            int sum = a[idx];
            idx ++;
            while(sum < cnt && idx < a.size()) {
                sum += a[idx];
                idx ++;
            }
            a.pop_back();
            if (sum < cnt) {
                cout << "NO\n";
                continue;
            }
            else {
                cout << "YES\n";
                continue;
            }
        }
        else {
            cout << "YES\n";
            continue;
        }
    }

}
int main() {
    // freopen("K.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> Tex;
    while(Tex --) AC();
    return 0;
}