#include <bits/stdc++.h>
using namespace std;

int main() {
    while (true) {
        system("./make_data");
        system("./D2 > D.out");
        system("./D_ > D_.out");
        if (system("diff D.out D_.out")) {
            cout << "WA" << endl;
            break;
        } else {
            cout << "AC" << endl;
        }
    }
}