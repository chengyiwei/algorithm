#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 2e5 + 5;
string a[3] = {"Kato_Shoko", "koishiYun"};
ll Tex = 1, n;
void AC() {
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        ll x;
        cin >> x;
        if (x == 3 || x == 6) cout << a[1] << "\n";
        else cout << a[0] << "\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cin >> Tex;
    while (Tex --) AC();
    return 0;
}