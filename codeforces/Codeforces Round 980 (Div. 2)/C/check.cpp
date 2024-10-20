#include <bits/stdc++.h>
using namespace std;
int main() {
    while (true) {
        system("./make_data");
        system("./C > C.out");
        system("./C_ > C_.out");
        if (system("diff C.out C_.out")) {
            cout << "WA" << endl;
            break;
        }
        cout << "AC" << endl;
    }
}