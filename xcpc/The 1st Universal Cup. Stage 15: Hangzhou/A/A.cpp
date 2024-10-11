#include <bits/stdc++.h>
using namespace std;

int ask(int x) {
    cout << "? " << x << endl;
    int res; cin >> res;
    return res;
}

void find(int x) {
    cout << "! " << x << endl;
    exit(0);
}

int main() {
    int n; cin >> n;
    int L = 1, R = n;
    int pre = 0;
    while (L <= R) {
        int now = ask(L);
        if (now == pre) find(L);
        L += 1;

        int mid = (L + R) >> 1;
        int now_ = ask(mid);
        if (now_ == now) find(mid);
        if (now_ < now) R = mid - 1;
        else L = mid + 1;
        pre = now_;
    }
    return 0;
}