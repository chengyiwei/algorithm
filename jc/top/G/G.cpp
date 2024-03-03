#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("G.in","r",stdin);
    int n; cin >> n;
    vector<int> a,b;
    int num_0 = 0, num_1 = 0;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        if (x == 1) a.push_back(i);
        else b.push_back(i);
    }
    int ans = 0;
    while (!a.empty() || !b.empty()) {
        if (a.empty()) 
            b.pop_back();
        else if (b.empty()) 
            a.pop_back();
        else {
            if (a.back() < b.back()) {
                while (!b.empty() && b.back() > a.back()) 
                    b.pop_back();
                a.pop_back();
            }
            else {
                while (!a.empty() && a.back() > b.back()) 
                    a.pop_back();
                b.pop_back();
            }
        }
        ans ++;
    }
    cout << ans << endl;
    return 0;
}