#include <bits/stdc++.h>
using namespace std;
int main() {
    int L = 1, R = 1e9;
    while (L < R) {
        int mid = (L + R) >> 1;
        cout << mid << endl;
        int ret; cin >> ret;
        if (ret == 0)
            L = mid + 1;
        else
            R = mid;
    }
    cout << R << endl;
}