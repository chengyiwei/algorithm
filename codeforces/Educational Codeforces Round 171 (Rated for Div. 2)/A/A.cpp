#include <bits/stdc++.h>

int main() {
    freopen ("A.in", "r", stdin);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int T; std::cin >> T;
    while (T--) {
        int X, Y, K; std::cin >> X >> Y >> K;
        int M = std::min(X, Y);
        int Ax = 0, Ay = 0;
        int Bx = M, By = M;
        int Cx = 0, Cy = M;
        int Dx = M, Dy = 0;
        
        std::cout << Ax << ' ' << Ay << ' ' << Bx << ' ' << By << ' ' << '\n';
        std::cout << Cx << ' ' << Cy << ' ' << Dx << ' ' << Dy << ' ' << '\n';

    }
}