#include <bits/stdc++.h>
using namespace std;
int main() {
    int a[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            cin >> a[i][j];
    }
    int ans1 = a[0][0] + a[1][1] + a[2][2];
    int ans2 = a[0][2] + a[1][1] + a[2][0];
    cout << ans1 << " " << ans2 << endl;
    return 0;
}