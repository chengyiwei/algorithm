#include <bits/stdc++.h>
using namespace std;

vector<int> get_phi (int n) {
    vector<int> phi (n + 1);
    vector<bool> vis (n + 1, 0);
    vector<int> prime;
    for (int i = 2; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            prime.push_back(i);
            phi[i] = i - 1;
        }
        for (int j = 0; j < prime.size(); j++) {
            if (i * prime[j] > n) break;
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
            phi[i * prime[j]] = phi[i] * phi[prime[j]];
        }
    }
    return phi;
}

int main() {
    int n; cin >> n;
    if (n == 1) {
        cout << 0 << '\n';
        return 0;
    }
    auto phi = get_phi(n);
    vector<int> sum (n + 1); sum[1] = 1;
    for (int i = 2; i <= n; i++) sum[i] = sum[i - 1] + phi[i]; 
    cout << 2 * sum[n - 1] + 1 << '\n';
    return 0;
}