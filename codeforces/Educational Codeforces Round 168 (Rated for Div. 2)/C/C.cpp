#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int cnt = 0;
    stack<int> st;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') cnt += 1;
        else if (s[i] == '_') {
            if (cnt > 0) {
                s[i] = ')'; cnt -= 1; st.push(i);
            }
            else {
                cnt += 1; s[i] = '(';
            }
        }
        else if (s[i] == ')') {
            cnt -= 1;
            if (cnt < 0) {
                int pos = st.top(); st.pop();
                s[pos] = '(';
                cnt += 2;
            }
        }
    }
    while (cnt < 0) {
        int pos = st.top(); st.pop();
        s[pos] = '(';
        cnt += 2;
    }
    while (!st.empty()) st.pop();
    long long ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') st.push(i);
        else {
            int pos = st.top(); st.pop();
            ans += i - pos;
        }
    }
    cout << ans << '\n';
}

int main() {
    freopen ("C.in", "r", stdin);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}