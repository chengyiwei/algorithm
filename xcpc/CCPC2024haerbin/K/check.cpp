#include <bits/stdc++.h>

int main() {
    while (true) {
        system("./make_data");
        system("./K > K.out");
        system("./K0 > K0.out");
        if (system("diff K.out K0.out")) {
            puts("WA");
            return 0;
        }
        puts("AC");
    }
}