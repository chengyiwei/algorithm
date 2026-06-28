#include <bits/stdc++.h>

using ld = double;
constexpr ld eps = 1e-9;

int sgn(const ld &a) {
    if (a < -eps)
        return -1;
    return (a > eps);
}

std::string gauss(std::vector<std::vector<ld>> &a) { // 传入增广矩阵
    int n = a.size();
    int c = 0, r = 0;
    for (c = 0, r = 0; c < n; c++) {
        int tmp = r;
        for (int i = r; i < n; i++)
            if (sgn(a[i][c]))
                tmp = i;
        if (sgn(a[tmp][c]) == 0)
            continue;

        std::swap(a[tmp], a[r]);

        for (int i = n; i >= c; i--)
            a[r][i] /= a[r][c];
        
        for (int i = r + 1; i < n; i++)
            if (sgn(a[i][c]))
                for (int j = n; j >= c; j--)
                    a[i][j] -= a[r][j] * a[i][c];
        r += 1;
    }
    if (r < n) {
        for (int i = r; i < n; i++)
            if (sgn(a[i][n]))
                return "NoSolution";
        return "InfSolution";
    }

    for (int i = n - 1; i >= 0; i--)
        for (int j = i + 1; j < n; j++)
            a[i][n] -= a[j][n] * a[i][j];
    
    return "OK";
}

int main() {
    freopen ("H.in", "r", stdin);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);

    int n; std::cin >> n;

    std::vector w(n, std::vector<int>(n , 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            std::cin >> w[i][j];
    
    ld ans = 0;
    for (int S = 1; S < (1 << n); S++) {
        int m = __builtin_popcount((S));
        if (m <= 1)
            continue;
        
        std::vector a(m, std::vector<ld>(m + 1, 0));
        std::vector<int> b;

        for (int T = S; T ; T -= T & -T) {
            b.push_back(std::__lg(T & -T));
        }

        for (int i = 0; i <= m; i++)
            a[0][i] = 1;
        
        for (int j = 1; j < m; j++) {
            for (int k = 0; k < m; k++) 
                a[j][k] = w[b[j]][b[k]] - w[b[j - 1]][b[k]];
        }

        // debug
        // std::cout << "S = " << S << '\n';
        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j <= m; j++)
        //         std::cout << a[i][j] << ' ';
        //     std::cout << '\n';
        // }
        // std::cout << '\n';
    
        auto res = gauss(a);
        if (res == "OK") {
            ld now = 0;
            for (int i = 0; i < m; i++)
                if (sgn(a[i][m]) == -1) 
                    now = -1e9;
            
            for (int i = 0; i < m; i ++)
                for (int j = i + 1; j < m; j++)
                    now += a[i][m] * a[j][m] * w[b[i]][b[j]];
                
            ans = std::max(ans, now);
        }
    }

    std::cout << std::fixed << std::setprecision(10) << ans << '\n';
    return 0;
}