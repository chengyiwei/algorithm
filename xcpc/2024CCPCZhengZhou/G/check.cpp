#include <bits/stdc++.h>
using namespace std;

int main() {
        system("./G < G.in > G.out");
    while (true){
        system("./make_data > G.in");
        system("./G1 < G.in > G1.out");
        system("./G < G.in > G.out");

        if (system("diff G.out G1.out")){
            cout << "Wrong Answer!" << endl;
            break;
        } else {
            cout << "Accepted!" << endl;
        }
    }
}