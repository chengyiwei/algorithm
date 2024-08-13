#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

bool huiwen(LL x) {
    string s = to_string(x);
    for (int i = 0; i <= s.size() / 2; i++) {
        if (s[i] != s[s.size() - i - 1]) return 0;
    }
    return 1;

}

int main() {
    LL x, ans; cin >> x;
    for (LL i = 1; i * i * i <= x; i++) {
        if (huiwen(i * i * i)) ans = i * i * i;
    }
    cout << ans << endl;
    return 0;
}
