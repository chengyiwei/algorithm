#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen ("D.in", "w", stdout);
    srand(time(0));
    int n = rand() % 10 + 1;
    cout << n << endl;
    for (int i = 1; i <= n; i++) cout << rand() % 10 + 1 << " ";
    cout << endl;
    for (int i = 1; i <= n; i++) cout << rand() % 10 + 1 << " ";
    cout << endl;
    return 0;
}