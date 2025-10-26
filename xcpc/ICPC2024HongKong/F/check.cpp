#include <bits/stdc++.h>
using namespace std;
int main() {
    while (true) {
        system("./make_data");
        system("./F");
        system("./F0");
        if (system("diff F.out F0.out")) {
            puts("WA");
            exit(0);
            
        }
        puts("AC");
    }
}