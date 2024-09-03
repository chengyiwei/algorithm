#include <bits/stdc++.h>
using namespace std;
int main() {
    int A, B;
    cin >> A >> B;
    if (A == B) {
        cout << 1 << '\n';
        return 0;
    }
    int ans = 2;
    if ((B - A) % 2 == 0) ans += 1;
    cout << ans << '\n';
    return 0;
}