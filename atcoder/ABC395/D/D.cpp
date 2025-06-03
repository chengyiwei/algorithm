#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<int> from(N + 1, 0); // 编号为 i 的鸽子在哪个笼子里面
    vector<int> a(N + 1, 0), inv(N + 1, 0); // a 表示第 i 个位置的现在放的是什么笼子， inv_a 表示笼子 i 放在了哪个位置
    for (int i = 1; i <= N; i++) 
        from[i] = i, a[i] = i, inv[i] = i;
    
    int Q; cin >> Q;
    while (Q--) {
        int op ; cin >> op;
        if (op == 1) {
            int x, y; cin >> x >> y;
            from[x] = a[y];
        }
        if (op == 2) {
            int x, y; cin >> x >> y;
            swap(a[x], a[y]);
            swap(inv[a[x]], inv[a[y]]);
        }
        if (op == 3) {
            int x; cin >> x;
            cout << inv[from[x]] << '\n';
        }
    }

    return 0;
}