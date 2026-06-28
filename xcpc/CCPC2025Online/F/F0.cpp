#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<int> sg(105, 0);
    
    auto mex = [&](const vector<int> &v) {
        set<int> s(v.begin(), v.end());
        for (int i = 0; ; i++) {
            if (!s.count(i)) return i;
        }
    };

    sg[0] = 0; sg[1] = 0;
    for (int i = 2; i <= 100; i++) {
        vector<int> v;
        for (int j = 0; j <= i - 2; j++) {
            v.push_back(sg[j] ^ sg[i - 2 - j]);
        }
        sg[i] = mex(v);
    }

    for (int i = 1; i <= 100; i++) {
        cout << sg[i] << ' ';
        if ((i - 1) % 34 == 33) cout << '\n';
        
    }
    return 0;
}