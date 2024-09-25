#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    freopen ("F.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int N, A, R ,M; cin >> N >> A >> R >> M;
    vector<int> h(N + 1);
    for (int i = 1; i <= N; i++) cin >> h[i];
    M = min(M, A + R);
    
    auto check = [&] (int mid) -> ll{
        ll sum1 = 0, sum2 = 0;
        for (int i = 1; i <= N; i++) {
            if (h[i] < mid) sum1 += mid - h[i];
            else sum2 += h[i] - mid;
        }
        ll sum = min(sum1, sum2);
        sum1 -= sum; sum2 -= sum;
        return sum1 * A + sum2 * R + sum * M;
    };

    int l = 0, r = 1e9;
    while (l < r) {
        int lmid = l + (r - l) / 3, rmid = r - (r - l) / 3;
        if (check(lmid) < check(rmid)) r = rmid - 1;
        else l = lmid + 1;
    }
    cout << check(l) << '\n';
    return 0;
}