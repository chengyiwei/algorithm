#include <bits/stdc++.h>
using namespace std;

int brand() {
    return rand();
}

int main() {
    srand(time(0));
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n = rand() % 100000 + 1;
    cout << n << '\n';
    for (int i = 0; i < n; i++) {
        int L = brand() % 1000000 + 1;
        int R = brand() % 1000000 + 1;
        if (L > R) swap(L, R);
        cout << L << ' ' << L << '\n';
    }
    return 0;
}