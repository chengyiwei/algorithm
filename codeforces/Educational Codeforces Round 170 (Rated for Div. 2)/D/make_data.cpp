#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen ("D.in", "w", stdout);
    srand(time(0));

    int n = rand() % 20 + 1, m;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        if (rand() % 3 == 0) v[i] = 0;
        else v[i] = rand() % 7 * (rand() % 2 == 0 ? 1 : -1);
        if (v[i] == 0) m += 1;
    }
    cout << n << ' ' << m << '\n';
    for (int i = 1; i <= n; i++) cout << v[i] << ' ';
    cout << '\n';
    
}