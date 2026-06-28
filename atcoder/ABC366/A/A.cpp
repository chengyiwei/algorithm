#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, A , B ; cin >> N >> A >> B;
    int A_ = N - (A + B) + A;
    if (A_ < B) {
        cout << "Yes" << endl;
        return 0;
    }
    int B_ = N - (A + B) + B;
    if (B_ < A) {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}