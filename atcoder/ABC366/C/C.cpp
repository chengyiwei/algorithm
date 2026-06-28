#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int main() {
    int Q; cin >> Q;
    vector<int> p(maxn, 0);
    int cnt = 0;
    while (Q--) {
        int op; cin >> op;
        if (op == 1) {
            int x; cin >> x;
            if (p[x]++ == 0) cnt += 1;
        }
        else if (op == 2) {
            int x; cin >> x;
            if (--p[x] == 0) cnt -= 1;
        }
        else {
            cout << cnt << endl;
        }
    }
}