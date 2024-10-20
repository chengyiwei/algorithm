#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    cout << n << '\n';
    for (int i = n; i >= 1; i--) {
        long long now = i;
        int cnt = 1;
        while (now < n) {
            now *= i;
            cnt++;
        }
        if (now == n) {
            cout << "=" << i << "^" << cnt << '\n';
        }
    }
}