#include <bits/stdc++.h>
using ll = long long;

template <typename T>
struct LinearBasis
{
    int n;
    bool to_zero = 0;
    std::vector<T> b;
    LinearBasis(int n) : n(n), b(n + 1) {}

    void insert(T x)
    {
        std::cout << "insert " << x << '\n';
        for (int i = n; i >= 0; i--)
        {
            if (x >> i & 1)
            {
                if (!b[i])
                {
                    b[i] = x;
                    return;
                }
                x ^= b[i];
            }
        }
        to_zero = 1;
    }
    bool contain(T x)
    {
        if (x == 0)
        {
            return to_zero;
        }
        for (int i = n; i >= 0; i--)
        {
            if (x >> i & 1)
            {
                if (!b[i])
                {
                    return 0;
                }
                x ^= b[i];
            }
        }
        return 1;
    }
};

int main()
{
    freopen ("J.in", "r", stdin);
    freopen ("J0.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int T;
    std::cin >> T;

    while (T--)
    {
        int n;
        std::cin >> n;

        std::vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
            std::cin >> a[i];
        for (int i = 0; i < n; i++)
            std::cin >> b[i];

        LinearBasis<int> c(30);
        int A = 0, B = 0;
        for (int i = 0; i < n; i++)
        {
            A ^= a[i];
            B ^= b[i];
            c.insert(a[i] ^ b[i]);
        }
        for (int i = 30; i >= 0; i--)
        {
            std::cout << c.b[i] << ' ';
        }
        std::cout << '\n';
        
        for (int i = 30; i >= 0; i--)
        {
            int nA = A ^ c.b[i];
            int nB = B ^ c.b[i];
            if (std::max(nA, nB) < std::max(A, B))
            {
                A ^= c.b[i];
                B ^= c.b[i];
            }
        }

        std::cout << std::max(A, B) << '\n';
    }
    return 0;
}