#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
int brand() {
    return (rand() << 15) | rand();
}
int main() {
    freopen ("D.in", "w", stdout);
    srand(GetTickCount());
    int n = brand() % 1000 + 1;
    cout << n << endl;
    return 0;
    
}