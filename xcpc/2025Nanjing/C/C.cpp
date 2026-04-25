#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll Tex, n;
void AC() {
    cin >> n;
    if (n & 1) cout << "No\n";
    else cout << "Yes\n" << n / 2 << " " << n / 2 << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> Tex;
    while (Tex --) AC();
    return 0;
}
