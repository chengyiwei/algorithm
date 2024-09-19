#include <bits/stdc++.h>
using namespace std;

const int N = 2008;
int arr[N], sa[N];
int b[N][N], sb[N][N];

void eachT() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }

    auto check = [&](int x) {
        sa[0] = 0;
        for (int i = 1; i <= n; ++i) {
            int a = arr[i] <= x ? 1 : -1;
            sa[i] = sa[i - 1] + a;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = i; j <= n; ++j) {
                b[i][j] = sa[j] - sa[i - 1] >= 0 ? 1 : -1;
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                sb[i][j] = sb[i - 1][j] + sb[i][j - 1] - sb[i - 1][j - 1] + b[i][j];
            }
        }
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = i; j <= n; ++j) {
                int c = sb[j][j] - sb[i - 1][j] - sb[j][i - 1] + sb[i - 1][i - 1] >= 0 ? 1 : -1;
                sum += c;
            }
        }
        return sum >= 0;
    };

    int l = 0, r = 1e9 + 1;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) r = mid - 1;
        else l = mid + 1;
    }
    cout << l << '\n';
}

int main() {
    freopen ("G.in", "r", stdin);
    freopen ("G0.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    eachT();
    return 0;
}