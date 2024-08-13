#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    string s1, s2; cin >> s1 >> s2;
    int ans = 0;
    for (int i = 0; i + s1.size() - 1 < s2.size(); i++) {
        if (s2.substr(i, s1.size()) == s1)
            ans ++;
    }
    cout << ans << endl;
    return 0;
}