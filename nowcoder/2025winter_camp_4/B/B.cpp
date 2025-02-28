#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int T; cin >> T;
    while (T--) {

        int n; cin >> n;
        string s; cin >> s;
        vector<int> emp;
        vector<int> a(s.size());
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0' || s[i] == '1') {
                a[i] = s[i] - '0';
            } else {
                emp.push_back(i);
            }
        }

        ll ans = 0;

        for (int S = 0; S < (1 << emp.size()); S++) {
            vector<int> b = a;
            for (int i = 0; i < emp.size(); i++) {
                if (S & (1 << i)) b[emp[i]] = 1;
                else b[emp[i]] = 0;
            }
            for (int i = 0; i < b.size(); i++) {
                b[i] = !b[i];
                if (b.front() == b.back()) 
                    ans++;
                b[i] = !b[i];
            }
        }

        cout << ans << '\n';
    }
    return 0;
}