#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e4 + 5;
int mu[maxn], prime[maxn], vis[maxn], sum_mu[maxn];
int a, b, c, d, k;

void get_mu() {
    int cnt = 0;
    mu[1] = 1;
    for (int i = 2; i < maxn; i++) {
        if (!vis[i]) {
            prime[++cnt] = i;
            mu[i] = -1;
        }
        for (int j = 1; j <= cnt; j++) {
            if (i * prime[j] >= maxn) break;
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                mu[i * prime[j]] = 0;
                break;
            }
            mu[i * prime[j]] = -mu[i];
        }
    }
    for (int i = 1; i < maxn; i++) sum_mu[i] = sum_mu[i - 1] + mu[i];
}

int calc(int n, int m) {
    int ret = 0;
    for (int i = 1, j; i <= min(n, m); i = j + 1) {
        j = min(n / (n / i), m / (m / i));
        ret += (sum_mu[j] - sum_mu[i - 1]) * (n / i / k) * (m / i / k);
    }
    return ret;
}

int main() {
    get_mu();
    int T; cin >> T;
    while (T--) {
        cin >> a >> b >> c >> d >> k;
        int ans = calc(b, d) - calc(a - 1, d) - calc(b, c - 1) + calc(a - 1, c - 1);
        cout << ans << endl;
    }
    return 0;
}