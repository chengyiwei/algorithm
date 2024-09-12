#include <bits/stdc++.h>
using namespace std;
int main() {
    while (true) {
        system("./make_data");
        system("./P3806");
        system("./P3806_");
        if (system("diff P3806.out P3806_.out")) {
            puts("WA");
            return 0;
        } else {
            puts("AC");
        }
    }
}