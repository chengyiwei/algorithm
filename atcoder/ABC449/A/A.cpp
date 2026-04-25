#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    double D; cin >> D;
    cout << fixed << setprecision(10) << D * D * PI / 4.0 << "\n";
    return 0;
}