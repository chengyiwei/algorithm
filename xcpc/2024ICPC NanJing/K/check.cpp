#include <bits/stdc++.h>

int main() {
    while (true) {
        system("./make_data");
        system("./K > K.out");
        system("./K1 > K0.out");
        if(system("diff K.out K0.out")) {
            printf("WA\n");
            break;
        }
        printf("AC\n");
    }
}