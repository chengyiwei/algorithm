#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

struct Node {
    LL x, y ,z;
};

map<LL,Node> mp;

int main() {
    vector<LL> a(2); a[0] = 0; a[1] = 1;
    for (int i = 2; i; i++) {
        LL x = a[i - 1] + a[i - 2];
        if (x > 1e9) break;
        a.push_back(x); 
    }
    for (int i = 0; i < a.size(); i++) 
        for (int j = i; j < a.size(); j++) 
            for (int k = j; k < a.size(); k++) 
                mp[a[i] + a[j] + a[k]] = {a[i], a[j], a[k]};
    int q; scanf("%d", &q);
    while (q--) {
        LL x; scanf("%lld", &x);
        if (mp.count(x)) 
            printf("%lld %lld %lld\n", mp[x].x, mp[x].y, mp[x].z);
        else 
            printf("-1\n");
    }
    return 0;
}