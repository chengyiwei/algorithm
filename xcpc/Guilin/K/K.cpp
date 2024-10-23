#include <bits/stdc++.h>

std::vector<int> calc (std::vector<int> &a, std::vector<int> &b) {
    int n = a.size();
    std::vector<int> ret(n);
    for (int i = 0; i < n; i++) ret[i] = a[b[i]];
    return ret;
}

int main() {
    freopen ("K.in", "r", stdin);

    int n, m; std::cin >> n >> m;
    std::vector<std::vector<int>> p(m, std::vector<int>(n, 0));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            std::cin >> p[i][j]; p[i][j] -= 1;
        }
    std::set<std::vector<int>> st, st_;
    for (auto B : p) {

        st_.clear();
        for (auto A : st) {
            auto C = calc(A, B);
            st_.insert(C);
        }
        for (auto A : st_) {
            st.insert(A);
        }
        st.insert(B);
    }
    
    std::cout << st.size() << std::endl;
    return 0;
}