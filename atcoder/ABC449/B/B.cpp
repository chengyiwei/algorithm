#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long H, W;
    int Q;

    cin >> H >> W >> Q;

    for (int i = 0; i < Q; ++i) {
        int type;
        long long val;
        cin >> type >> val;

        if (type == 1) {
            cout << val * W << "\n";
            H -= val;
        } else {
            cout << H * val << "\n";
            W -= val; 
        }
    }

    return 0;
}