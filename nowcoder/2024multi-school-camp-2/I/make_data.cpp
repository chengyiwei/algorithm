#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

int brand() {
    return (rand() << 15) | rand();
}

int main() {
    freopen ("I.in", "w", stdout);
    srand(GetTickCount());
    int n = brand() % 5 + 1;
    vector<int> a(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++)  {
        if (i <= n) 
            a[i] = i;
        else 
            a[i] = a[i - n];
    }
    random_shuffle(a.begin() + 1, a.begin() + 2 * n + 1);
    cout << n << endl;
    for (int i = 1; i <= 2 * n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}