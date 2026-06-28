#include <bits/stdc++.h>
using namespace std;
int qpow (int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int a[1005][1005];

void dfs (int up, int le, int len) {
    if (len == 1) {
        for (int i = up; i < up + len; i++)
            for (int j = le; j < le + len; j++)
                a[i][j] = 1;
        return;
    }
    int x = len / 3;
    for (int i = up + x; i < up + 2 * x; i++)
        for (int j = le + x; j < le + 2 * x; j++)
            a[i][j] = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (i != 1 || j != 1)
                dfs (up + i * x, le + j * x, x);

    return;
}

int main() {
    ios::sync_with_stdio(0);
    int K; cin >> K;
    int n = qpow(3, K);
    dfs (1, 1, n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << (a[i][j] ? '#' : '.');
        cout << endl;
    }
}