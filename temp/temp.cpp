#include <bits/stdc++.h>

using namespace std;
int main() {
    int n, m;
    std::vector<int> p = {50, 20, 10, 5, 2, 1};
    while (std::cin >> n >> m) {
        int d = m - n;
        for (auto x : p) {
            int num = d / x;
            if (num) {
                std::cout << x << " yuan: " << num << '\n';
            }
            d -= num * x;
        }
        std::cout << '\n';
    }
}