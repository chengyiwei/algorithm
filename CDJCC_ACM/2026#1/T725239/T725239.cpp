#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s; cin >> s;
    long long n; cin >> n; n -= 1;

    stack<long long> st;
    st.push(s.size());
    while (true) {
        long long x = st.top();
        if (x >= n) break;
        st.push(x * 2);
    }

    while (!st.empty()) {
        long long x = st.top(); st.pop();
        if (n >= x) {
            n -= x;
            n = (n - 1 + x) % x;
        }
    }

    cout << s[n] << '\n';
    return 0;
}
