#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 63;
LL p[maxn];

void insert(LL x) {
    for (int i = maxn - 1; i >= 0; i--) 
        if (x >> i & 1) {
            if (!p[i]) {p[i] = x; return ;}
            x ^= p[i]; 
        }
}

LL qmax() {
    LL ret = 0;
    for (int i = maxn - 1; i >= 0; i--)
        ret = max(ret, ret ^ p[i]);
    return ret;
}

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        LL x; cin >> x;
        insert(x);
    }
    printf("%lld\n",qmax());
    return 0;
}