#include <bits/stdc++.h>

int main() {
    while (true) {
        system("./make_data");
        system("./J > J.out");
        system("./JJ > JJ.out");
        if (system("diff J.out JJ.out")) {
            puts("WA");
            return 0;
        }
        puts("AC");
    }
}