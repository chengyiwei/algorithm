#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    string s; getline(cin, s);
    string now;
    long long ans = -1;
    for (auto c : s) {
        if ('0' <= c && c <= '9') {
            now.push_back(c);
        }
        else {
            if (now.size() > 0) {
                long long x = stoll(now);
                ans = max(ans, x);
            }
            now.clear();
        }
    }
    if (now.size() > 0) {
        long long x = stoll(now);
        ans = max(ans, x);
    }
    if (ans == -1) {
        cout << "none" << '\n';
    }
    else {
        cout << ans << '\n';
    }
}