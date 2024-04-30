#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, T; cin >> n >> T;
    map<LL,int> mp; mp[0] = n;
    vector<LL> a(n + 1, 0);
    
    auto del = [&](LL x) {
        if (mp[x] == 1) mp.erase(x);
        else mp[x] --;
    };
    
    auto add = [&](LL x) {
        if (mp.count(x) != 0) mp[x] ++;
        else mp[x] = 1;
    };

    while (T--) {
        int A; LL B; cin >> A >> B; 

        \\ a[A] -> a[A] + B

        del(a[A]);
        a[A] += B;
        add(a[A]);

        cout << mp.size() << '\n';
    }
    return 0;
}