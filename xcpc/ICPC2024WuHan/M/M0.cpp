#include <bits/stdc++.h>

using i64 = long long;

int main() {
    freopen ("M.in", "r", stdin);
    freopen ("M0.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::vector<i64> cand(a);
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            cand.push_back(a[i] * 2 - 1);
            cand.push_back(a[i] * 2 + 1);
        }
    }
    
    std::sort(cand.begin(), cand.end());
    
    cand.erase(std::unique(cand.begin(), cand.end()), cand.end());
    
    std::multiset<i64> s(a.begin(), a.end());
    
    std::vector<i64> v;
    auto check = [&](i64 x) {
        v.clear();
        
        int ok = 1;
        while (!s.contains(x)) {
            if (x % 2 == 0) {
                ok = 0;
                break;
            }
            i64 a = x / 2, b = x - a;
            if (a % 2 == 0) {
                std::swap(a, b);
            }
            if (!s.contains(b)) {
                ok = 0;
                break;
            }
            s.extract(b);
            v.push_back(b);
            x = a;
        }
        
        if (ok) {
            s.extract(x);
        } else {
            for (auto x : v) {
                s.insert(x);
            }
        }
        
        return ok;
    };
    
    std::vector<i64> ans;
    for (int i = cand.size() - 1; i >= 0; i--) {
        while (check(cand[i])) {
            ans.push_back(cand[i]);
        }
    }
    std::cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
        std::cout << ans[i] << " \n"[i == ans.size() - 1];
    }
    
    return 0;
}
