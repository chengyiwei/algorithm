#include <bits/stdc++.h>
const double eps = 1e-9;

int dcmp (double x, double y) {
    if (fabs(x - y) < eps) return 0;
    return x < y ? -1 : 1;
}

int main() {
    // freopen ("A.in", "r", stdin);
    double a, b; std::cin >> a >> b; a += b;
    std::pair<int, int> p[3];
    for (int i = 0; i < 3; i++) {
        auto &[x, y] = p[i]; std::cin >> x >> y;
    }
    for (int i = 1; i < 3; i++) {
        if (p[i] == std::make_pair(0, 0)) 
            swap(p[0], p[i]);
    }

    double len[3];
    for (int i = 0; i < 3; i++) {
        int j = (i + 1) % 3;
        len[i] = sqrt((p[i].first - p[j].first) * (p[i].first - p[j].first) + (p[i].second - p[j].second) * (p[i].second - p[j].second));
    }

    double P = (len[0] + len[1] + len[2]) / 2;
    double R = len[0] * len[1] * len[2] / (4 * sqrt(P * (P - len[0]) * (P - len[1]) * (P - len[2])));
    
    if (dcmp(a, R) >= 0) std::cout << "Win" << std::endl;
    else if (dcmp(2 * a, *std::min_element(len, len + 3)) >= 0) std::cout << "2" << std::endl;
    else std::cout << "1" << std::endl;

    return 0;
}