#include <bits/stdc++.h>
using namespace std;
int main() {
    while (1) {
        system("./make_data");
        system("./G0");
        system("./G");
        if (system("diff G0.out G.out")) {
            puts("WA");
            return 0;
        } else {
            puts("AC");
        }
    }
}