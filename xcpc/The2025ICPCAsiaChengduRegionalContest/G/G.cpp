#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll Tex, n, k, m;
void AC() {
    cin >> n >> k >> m;
    cout << m + (min(n - m, n / k) + 1) / 2 << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> Tex;
    while (Tex --) AC();
    return 0;
}