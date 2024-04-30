#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1e6 + 10;
const int mod = 1e9 + 7;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> o(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        o[x + 1] = i;
    }
    int lef = n + 1, rig = 0;
    int result = 1;
    for (int i = 1; i <= n; ++i)
    {
        lef = min(lef, o[i]), rig = max(rig, o[i]);
        if (o[i] != lef && o[i] != rig) {
            (result *= (rig - lef + 1) - (i - 1)) %= mod;
        }
    }
    cout << result << '\n';
    return 0;
}