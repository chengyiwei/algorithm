#include <bits/stdc++.h>
using namespace std;
int main() {
    while (true) {
        system("./make_data");
        system("./J0");
        system("./J");
        if (system("diff J0.out J.out")) {
            cout << "WA\n";
            break;
        }
        cout << "AC\n";
    }
}