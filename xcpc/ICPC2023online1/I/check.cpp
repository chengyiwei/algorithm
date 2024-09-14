#include <bits/stdc++.h>
using namespace std;
int main() {
    while (true) {
        system("./make_data");
        system("./I");
        system("./I0");
        if (system("diff I.out I0.out")) {
            puts("WA");
            return 0;
        } else {
            puts("AC");
        }
    }
}