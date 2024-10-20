#include <bits/stdc++.h>

int main() {
    freopen ("B.in", "r", stdin);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int n; std::cin >> n;
    int flg = 0;
    size_t now_up = 0, now_dn = 0;
    for (int i = 1; i <= n; i++) {
        int x; std::cin >> x;
        if (x > 0) now_up += x;
        if (x < 0) now_dn += -x;
        if (now_up == now_dn) {
            if (flg == 0) std::cout << '0';
            if (flg == 1) std::cout << '+';
            if (flg == -1) std::cout << '-';
        }
        if (now_up > now_dn)
            std::cout << '+';
        if (now_dn > now_up)
            std::cout << '-';
        if ((now_dn & 1) ^ (now_up & 1)) {
            if (now_dn & 1) flg = -1;
            if (now_up & 1) flg = 1;
        }
        now_dn >>= 1; now_up >>= 1;
    }
    std::cout << std::endl;
    return 0;
}