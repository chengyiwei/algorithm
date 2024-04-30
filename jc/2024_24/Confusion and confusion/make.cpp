#include <bits/stdc++.h>
using namespace std;

int brand() {return (rand() << 16) | (rand() << 1) | (rand() & 1);}
int brand(int l, int r) {return l + brand() % (r - l + 1);}

bool check (int x, int y, int r) {
    if (x + r > 100 || x - r < -100) return 0;
    if (y + r > 100 || y - r < -100) return 0;
    return 1;
}

int main() {
    srand(time(0));
    int num = 0, n = 1e5;
    while (num < n) {
        int x = brand(-99, 99), y = brand(-99, 99), r = brand(1, 100);
        while (!check(x, y, r)) {
            x = brand(-99, 99), y = brand(-99, 99), r = brand(1, 100);
        }
        printf ("%d %d %d\n", x, y, r); num++;
    }
    return 0;
}