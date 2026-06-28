#include <bits/stdc++.h>
using namespace std;

int ask(int n) {
    if (n == 1) return 10;
    return ask(n - 1) + 2;
}

int main() {
    int n; cin >> n;
    printf("Number %d is %d age!\n", n, ask(n));
    return 0;
}