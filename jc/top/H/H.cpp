#include <bits/stdc++.h>
using namespace std;
const int p[] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
int main() {
    int L, R; cin >> L >> R;
    int ans = 0;
    for (int i = 1; i <= 12; i++) {
        for (int j = 1; j <= p[i]; j++) {
            int pre = (j%10) * 1000 + (j/10) * 100 + (i%10) * 10 + (i/10);
            int suf = i * 100 + j;
            int x = pre * 10000 + suf;
            if (x >= L && x <= R) {
                cout << x << '\n';
                ans ++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}