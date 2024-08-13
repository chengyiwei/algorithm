#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    if (n <= 2) {
        cout << "0\n";
        return 0;
    }
    if (n == 3) {
        cout << "1\n" << "1 3\n" << "1 2\n";
        return 0;
    }
    int b, Max_ = -1;
    for (int Block = 2; Block <= n / 2; Block ++) {
        int num = (n + Block - 1) / Block;
        int A = (num - 1) * (Block - 1) + (n - (num - 1) * Block - 1);
        int B = (num - 1 - 1) * Block + (n - (num - 1) * Block);
        int C = min(A, B);
        if (C > Max_) {
            Max_ = C; b = Block;
        }
    }

    int m = Max_;
    cout << m << '\n';
    int cnt = 0;
    for (int i = 1; i + 1<= n; i++) {
        if (i % b == 0) continue;
        cout << i << ' ' << i + 1 << '\n';
        if (++cnt == m) break;
    }
    cnt = 0;
    for (int i = 1; i <= b; i++) {
        for (int j = i; j + b <= n; j += b) {
            cout << j << ' ' << j + b << '\n';
            if (++cnt == m) break;
        }
        if (cnt == m) break;
    }
    
    return 0;
}