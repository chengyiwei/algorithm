#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int a, b;
    ll C; 
    cin >> a >> b >> C;
    bitset<60> bit_C(C), bit_A, bit_B;
    if (a + b < bit_C.count() || (a + b - bit_C.count()) % 2 == 1) {cout << "-1" << '\n'; return 0;}
    int cnt = (a + b - bit_C.count()) / 2;
    a -= cnt; b -= cnt;
    for (int i = 0; i < 60; i++) {
        if (bit_C[i]) {
            if (a) {bit_A[i] = 1; a--;}
            else if (b) {bit_B[i] = 1; b--;}
        }
    }
    if (a != 0 || b != 0) {cout << "-1" << '\n'; return 0;}
    for (int i = 0; i < 60; i++) 
        if (bit_C[i] == 0)
            if (cnt) {
                bit_A[i] = 1; bit_B[i] = 1; cnt--;
            }
    if (cnt) {cout << "-1" << '\n'; return 0;}
    cout << bit_A.to_ullong() << ' ' << bit_B.to_ullong() << '\n';
    return 0;
}