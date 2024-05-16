#include <bits/stdc++.h>
using namespace std;

int Fac(int n) {
    if (n == 1) return 1;
    return n * Fac(n - 1);
}

int main() {
    int n; 
    while(scanf("%d", &n) != EOF) 
        cout << Fac(n) << endl;
}