#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll ans = 0;
    int N; cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j * i <= N; j++) {
            ans += N / (i * j);
        }
    }
    cout << ans << endl;
    return 0;
}