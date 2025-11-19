#include <bits/stdc++.h>
using namespace std;

int main() {
    while (true) {
        system("./make_data");
        system("./C");
        system("./C0");
        if (system("diff C.out C0.out")) {
            cout << "Wrong Answer!\n";
            break;
        } else {
            cout << "Accepted!\n";
        }
    }
}