#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    int N, M; cin >> N >> M;
    vector<vector<int> > g(N + 1);
    vector<pii> edges;
    for (int i = 1; i <= M; i++) {
        int A, B; cin >> A >> B;
        edges.push_back({A, B});
    }

    vector<int> fa(N + 1);
    iota(fa.begin(), fa.end(), 0);
    function<int(int)> find = [&](int x) {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    };

    for (auto &[A, B] : edges) {
        int x = find(A), y = find(B);
        if (x != y) fa[x] = y;
    }

    vector<int> cnt_x(N + 1, 0), cnt_y(N + 1, 0);
    for (int i = 1; i <= N; i++) 
        cnt_x[find(i)]++;
    for (auto &[A, B] : edges)
        cnt_y[find(A)]++;

    ll ans = 0;
    for (int i = 1; i <= N; i++) if (i == fa[i]) {
        ans += 1ll * cnt_x[i] * (cnt_x[i] - 1) / 2 - cnt_y[i];
    }
    cout << ans << endl;
    return 0;
}