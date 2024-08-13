#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

void solve(){
    int n; cin >> n;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    int ans = 3;
    for (int i = 1; i <= n; i++) {
        if (p[p[i]] == i) {
            ans = 2;
            break;
        }
    }
    printf("%d\n", ans);
}

int main(){
    freopen ("A.in" ,"r", stdin);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}