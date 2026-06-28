#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    int T; cin >> T;
    while(T--) {
        LL n, ret = 1; cin >> n;
        while(ret * 2 <= n) {
            ret <<= 1;
        }
        cout << ret << '\n';
    }
    return 0;
}