#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define int long long
const int maxn = 5e6 + 10;

int prime[maxn];
bool vis[maxn];
int mu[maxn];
LL phi[maxn];

unordered_map <int, int> mu_sum;
unordered_map <int, LL> phi_sum;

void init() {
    int cnt = 0;
    vis[0] = vis[1] = 1;
    mu[1] = phi[1] = 1;
    for (int i = 2; i < maxn; i++) {
        if (!vis[i]) {
            prime[cnt++] = i;
            mu[i] = -1;
            phi[i] = i - 1;
        }
        for (int j = 0l; j < cnt && i * prime[j] < maxn; j++) {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                mu[i * prime[j]] = 0;
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
            mu[i * prime[j]] = -mu[i];
            phi[i * prime[j]] = phi[i] * phi[prime[j]];
        }
    }
    for (int i = 1; i < maxn; i++) {
        mu[i] += mu[i - 1];
        phi[i] += phi[i - 1];
    }
}

int g_sum(int x) {
    return x;
}

LL get_mu_sum (int x) {
    if (x < maxn) return mu[x];
    if (mu_sum.count(x)) return mu_sum[x];
    LL ret = 1;
    for (LL l = 2, r; l <= x; l = r + 1) {
        r = x / (x / l);
        ret -= 1ll * (r - l + 1) * get_mu_sum(x / l);
    }
    return mu_sum[x] = ret;
}

LL get_phi_sum (int x) {
    if (x < maxn) return phi[x];
    if (phi_sum.count(x)) return phi_sum[x];
    LL ret = 1ll * x * (x + 1) / 2;
    for (LL l = 2, r; l <= x; l = r + 1) {
        r = x / (x / l);
        ret -= 1ll * (r - l + 1) * get_phi_sum(x / l);
    }
    return phi_sum[x] = ret;
}

signed main() {
    ios::sync_with_stdio(0);
    init();
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cout << get_phi_sum(n) << ' ' << get_mu_sum(n) << '\n';
    }
    return 0;
}