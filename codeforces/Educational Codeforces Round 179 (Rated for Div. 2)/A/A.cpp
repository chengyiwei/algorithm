#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        long long x; cin >> x;
        int cnt = 0, num = 0;
        while (num < x) {
            num = num * 2 + 1;
            cnt += 1;
        }
        cout << cnt * 2 + 1 << "\n";
    }
}