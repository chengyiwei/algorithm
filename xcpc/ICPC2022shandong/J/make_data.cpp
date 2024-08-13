#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
typedef long long ll;
ll brand() {
    return ((ll)rand() << 16) | rand();
}
int main() {
    freopen ("J.in", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    srand(time(0));
    int n = 1e5, m = 5e5;
    int q = 5e5;
    long long V = brand();
    cout << n << ' ' << m << ' ' << q << ' ' << V << '\n';
    for (int i = 1; i <= m; i++) {
        int u = rand() % n + 1, v = rand() % n + 1, w = brand();
        cout << u << ' ' << v << ' ' << w << '\n';
    }
    for (int i = 1; i <= q; i++) {
        int u = rand() % n + 1, v = rand() % n + 1;
        cout << u << ' ' << v << '\n';
    }
    return 0;
}