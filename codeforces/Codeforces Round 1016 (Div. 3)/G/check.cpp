
#include <bits/stdc++.h>
using namespace std;

int main() {
    
    while (true) {
        system("./make_data");
        system("./G");
        system("./G_");
        if (system("diff G.out G_.out")) {
            cout << "Wrong Answer" << endl;
            break;
        } else {
            cout << "Accepted" << endl;
        }

    }

}