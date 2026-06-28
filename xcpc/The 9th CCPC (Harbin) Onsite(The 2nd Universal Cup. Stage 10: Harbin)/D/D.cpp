#include <bits/stdc++.h>


struct DSU {
    std::vector<int> f;
    std::vector<int> size;
 
    DSU(int n) : f(n), size(n) {
        std::iota(f.begin(), f.end(), 0);
        std::fill(size.begin(), size.end(), 1);
    }
 
    int find(int x) { // 路径压缩
        while (x != f[x])
            x = f[x] = f[f[x]];
        return x;
    }
 
    void Union(int x, int y) {
        if (find(x) == find(y))
            return;
        if (size[x] < size[y]) // 按秩合并
            std::swap(x, y);
 
        size[find(x)] += size[find(y)];
        f[find(y)] = find(x);
    }
};

constexpr int N = 1e6 + 5;
constexpr int INF = 0x3f3f3f3f;

int P[N], w[N], proP[N], v[N], tot;
int L[N], R[N], cnt[N];

void init() {
    v[1] = 1;
    std::fill(proP, proP + N, 1);

    for (int i = 2; i < N; i++) {
        if (v[i] == 0) {
            P[++tot] = i;
            v[i] = i; w[i] = 1;
            proP[i] = i;
        }
        for (int j = 1; j <= tot && i * P[j] < N; j++) {
            v[i * P[j]] = P[j];
            if (i % P[j] == 0) {
                w[i * P[j]] = w[i];
                proP[i * P[j]] = proP[i];
                break; 
            }
            w[i * P[j]] = w[i] + 1;
            proP[i * P[j]] = proP[i] * P[j];
        }
    }

    auto find_div = [&] (int x) {
        std::vector<int> res(1, 1);
        while (x > 1) {
            int d = v[x];
            x /= d;
            for (int i = res.size() - 1; i >= 0; i--)
                res.push_back(res[i] * d);
        }
        return res;
    };

    for (int i = 1; i < N; i++) {
        auto divs = find_div(proP[i]);
        for (int d : divs) 
            L[i] = std::max(L[i], cnt[d]);
        cnt[proP[i]] = i;
    }

    std::fill(cnt, cnt + N, INF);
    std::fill(R, R + N, INF);

    for (int i = N - 1; i; i--) {
        auto divs = find_div(proP[i]);
        for (int d : divs) 
            R[i] = std::min(R[i], cnt[d]);
        cnt[proP[i]] = i;
    }
}

void cpSort(std::vector<std::array<int, 3>> &a) {
    int M = 0;
    for (const auto &[w, x, y] : a) M = std::max(M, w);
    std::vector<std::vector<int>> cnt(M + 1);
    for (int i = 0; i < a.size(); i++)
        cnt[a[i][0]].push_back(i);
    
    std::vector<std::array<int, 3>> res;
    for (int x = 0; x <= M; x++)
        for (auto i : cnt[x])
            res.push_back(a[i]);
    a = res;
}

int mst(std::vector<std::array<int, 3>> &e, int l, int r) {
    DSU dsu(r - l + 1);
    cpSort(e);
    int ret = 0;
    for (const auto &[w, x, y] : e) {
        if (dsu.find(x - l) != dsu.find(y - l)) {
            dsu.Union(x - l, y - l);
            ret += w;
        }
    }
    return ret;
}

int edge(int x, int y) {
    return w[x] + w[y] - w[std::gcd(x, y)];
}

void solve() {
    int l, r; std::cin >> l >> r;

    int ans = std::accumulate(w + l, w + r + 1, 0);
    if (l == 1) {
        std::cout << ans << '\n';
        return;
    }

    std::vector<std::array<int, 3>> e;

    int prime = 0;
    for (int x = l; x <= r; x++) {
        if (w[x] == 1)
            prime = x;
    }

    if (prime == 0) {// 区间内没有 w[x]=1 的数
        for (int i = l; i < r; i++)
            for (int j = i + 1; j <= r; j++)
                e.push_back({edge(i, j), i, j});
            
        ans = mst(e, l, r);
        std::cout << ans << '\n';
        return ;
    }

    for (int x = l; x <= r; x++) {
        if (L[x] >= l) 
            e.push_back({w[x], x, L[x]});
        if (R[x] <= r) 
            e.push_back({w[x], x, R[x]});
        if (prime != x) 
            e.push_back({edge(x, prime), x, prime});
    }
    ans = mst(e, l, r);
    std::cout << ans << '\n';
}

int main() {
    freopen ("D.in", "r", stdin);
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    init(); 

    int _; std::cin >> _;
    while (_--) solve();
    return 0;
}