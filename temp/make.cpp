#include <bits/stdc++.h>
using namespace std;

static mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rnd(long long l, long long r) {
    uniform_int_distribution<long long> dist(l, r);
    return dist(rng);
}

int main() {
    freopen ("make.in", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1; // 生成 5 组测试
    // cout << T << "\n";

    while(T--) {
        int N = rnd(10, 2000);  // N 在 10~2000 之间
        long long C = rnd(1, (1ll << 20)); // C 范围小一点，避免溢出

        cout << N << " " << C << "\n";

        vector<long long> a;
        a.reserve(N);

        int pairCnt = N * 6 / 10; // 60%确保合法数对

        // 构造合法数对
        for(int i = 0; i < pairCnt; i++) {
            long long x = rnd(0, (1ll << 20) - 1 - C);
            a.push_back(x);     // B
            a.push_back(x + C); // A = B + C
        }

        // 补齐数组
        while((int)a.size() < N) {
            a.push_back(rnd(0, (1ll << 20)));
        }

        shuffle(a.begin(), a.end(), rng);

        for(int i = 0; i < N; i++)
            cout << a[i] << (i + 1 == N ? '\n' : ' ');
    }

    return 0;
}