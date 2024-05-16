#include <bits/stdc++.h>
using namespace std;


void f(int n) {
    if (n == 0) return;
    f(n / 16);
    if (n % 16 < 10) cout << n % 16;
    else cout << (char)(n % 16 - 10 + 'A');

}


int main() {
    int a, b; cin >> a >> b;
    for (int i = a; i <= b; i++) {
        f(i);
        cout << " ";
    }
}