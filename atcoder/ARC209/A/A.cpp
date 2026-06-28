#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 2e5 + 5;
ll Tex, k;
string s;
void AC() {
    cin >> s >> k;
    ll cnt = 0;
    vector<ll> pt((ll)(s.size() + 5), 0);
    stack<ll> st;
    for (int i = 0; i < s.size(); i ++) {
        if (s[i] == '(') {
            cnt ++;
            st.push(i);
        }
        else cnt --;
        if (cnt < 0) {
            cout << "First\n";
            return;
        }
        if (s[i] == ')') {
            pt[st.top()] = i;
            pt[i] = st.top();
            st.pop();
        }
    }
    if (cnt > 0) {
        cout << "First\n";
        return;
    }
    ll L = 0, R = s.size() - 1, now = 0;
    while (L <= R) {
        if (R - L + 1 == k) {
            if (now) {
                cout << "First\n";
                return;
            }
            break;
        }
        if (!now) {
            now ^= 1;
            L ++;
        }
        else {
            now ^= 1;
            if (pt[L] == L - 1) {
                L ++;
            }
            else if (pt[R] == L - 1) {
                R --;
            }
            else {
                cout << "First\n";
                return;
            }
        }
    }
    L = 0, R = s.size() - 1, now = 0;
    while (L <= R) {
        if (R - L + 1 == k) {
            if (now) {
                cout << "First\n";
                return;
            }
            break;
        }
        if (!now) {
            now ^= 1;
            R --;
        }
        else {
            now ^= 1;
            if (pt[L] == R + 1) {
                L ++;
            }
            else if (pt[R] == R + 1) {
                R --;
            }
            else {
                cout << "First\n";
                return;
            }
        }
    }
    cout << "Second\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> Tex;
    while (Tex --) AC();
    return 0;
}