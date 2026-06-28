#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k; cin >> n >> k;
    int l = 0, r = n * n; k = n * n - k + 1;

    auto check = [&](int x) {
        int res = 0;
        int pos_x = n, pos_y = 1;
        while (pos_x >= 1 && pos_y <= n) {
            cout << "? " << pos_x << " " << pos_y << " " << x << endl;
            int rely; cin >> rely;
            if (rely == 1) {
                res += pos_x;
                pos_y++;
            }
            else {
                pos_x--;
            }
        }
        return res;
    };

    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (check(mid) >= k) r = mid;
        else l = mid;   
    }
    cout << "! " << r << endl;
    return 0;
}