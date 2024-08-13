#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll A = 343720, B = 233333;

int main() {
    for (ll n = 1; n <= 10000; n++)
        for (ll m = 1; m <= 10000; m++) {
            if (n * A * 17 == m * B * 15 && n % 2 == 0 && m % 2 == 0) {
                ld x = n * A, y = m * B;
                cout << n << ' ' << m << endl;
                printf("%.2Lf\n", sqrt(x * x + y * y));
                return 0;
            }
        }
    return 0;
}