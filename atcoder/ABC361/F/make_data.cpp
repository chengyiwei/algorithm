#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

int brand() {
    return (rand() << 16) + (rand() << 1) + (rand() & 1);
}

int main() {
    srand(GetTickCount());
    freopen ("F.in", "w", stdout);
    cout << brand() << endl;
    return 0;
}