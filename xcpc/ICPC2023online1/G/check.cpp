#include <bits/stdc++.h>
using namespace std;
int main() {
    while (true) {
        system("./make_data");
        system("./G0");
        system("./G");
        if (system("diff G0.out G.out")) {
            printf ("WA\n");
            break;
        }
        else {
            printf ("AC\n");
        }
    }
}