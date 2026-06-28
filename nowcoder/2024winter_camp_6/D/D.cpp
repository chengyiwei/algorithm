#include <bits/stdc++.h>
using namespace std;
int main() {
    double p; cin >> p;
    double q = 1 - p;
    double ans = q * q * p * p * p + p * p * q * q * q;
    printf("%.6f\n", ans);
    return 0;
}