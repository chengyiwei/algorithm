#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n; cin >> n;
    int A = -1, B = -1;
    for (int i = 1; i <= n; i += 2) {
        int now_a = i, now_b = (i + 1 - 1) % n + 1;
        cout << '?' << ' ' << now_a << ' ' << now_b  << endl;
        int ok; cin >> ok;
        if (ok) {
            A = now_a, B = now_b;
            break;
        }
    }
    if (A == -1) {cout << '!' << ' ' << 1 << endl; return;} 
    int o1 = 1, o2 = 2;
    while (o1 == A || o1 == B) o1 = rand() % n + 1;
    while (o2 == A || o2 == B || o2 == o1) o2 = rand() % n + 1;
    cout << '?' << ' ' << A << ' ' << o1 << endl;
    int ok1; cin >> ok1;
    if (ok1) { // A is center
        cout << '?' << ' ' << A << ' ' << o2 << endl;
        int ok2; cin >> ok2;
        if (ok2) {cout << '!' << ' ' << 2 << endl; return;}
        else {cout << '!' << ' ' << 1 << endl; return;}
    }
    else { // B is center
        cout << '?' << ' ' << B << ' ' << o1 << endl;
        int ok3; cin >> ok3;
        if (ok3) {
            cout << '?' << ' ' << B << ' ' << o2 << endl;
            int ok4; cin >> ok4;
            if (ok4) {cout << '!' << ' ' << 2 << endl; return;}
            else {cout << '!' << ' ' << 1 << endl; return;}
        }
        else {cout << '!' << ' ' << 1 << endl; return;}
    }
}
int main() {
    srand(time(0));
    int t; cin >> t;
    while (t--) solve();
    return 0;
}