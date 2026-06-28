#include <bits/stdc++.h>
using namespace std;

pair<int, int> gen() {
    int x = rand() % 1000000000;
    int y = rand() % 1000000000;
    if (rand() & 1) x = -x;
    if (rand() & 1) y = -y;
    return {x, y};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T = 2000;
    cout << T << '\n';
    while (T--) {
        int n = 100;
        cout << n << '\n';
        auto p1 = gen(), p2 = gen();
        cout << p1.first << ' ' << p1.second << ' ' << p2.first << ' ' << p2.second << '\n';
        for (int i = 1; i <= n; i++) {
            auto p = gen();
            cout << p.first << ' ' << p.second << '\n';
        }
    }
}