#include <bits/stdc++.h>
using namespace std;

int main() {
    while (1) {
        system("./make_data");
        system("./G");
        system("./std");
        if (system("diff G.out std.out")) {
            cout << "Wrong Answer!\n";
            break;
        } else {    
            cout << "Accepted!\n";
        }
    }
}