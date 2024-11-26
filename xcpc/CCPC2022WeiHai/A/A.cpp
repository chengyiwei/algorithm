#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    map<string, int> cp;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 5; j++) {
            string s; cin >> s;
            cp[s] = j;
        }
    }

    vector<int> cnt(6, 0);
    int tot;
    int m; cin >> m;
    for (int i = 1; i <= m; i++) {
        string name; int pos; cin >> name >> pos;
        if (cp[name] == pos)
            tot += 1;
        cnt[pos] += 1;
    }
    int min_ = 1e9;
    for (int i = 1; i <= 5; i++) min_ = min(min_, cnt[i]);
    cout << min(min_, tot) << '\n';
    return 0;
}