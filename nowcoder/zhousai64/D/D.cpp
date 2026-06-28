#include <bits/stdc++.h>
using namespace std;

map<array<array<int, 2>, 2>, int> sg;

int mex(vector<int> v) {  // v可以是vector、set等容器
    unordered_set<int> S;
    for (auto e : v) S.insert(e);
    for (int i = 0;; ++i)
        if (S.find(i) == S.end()) return i;
}

int main() {
    freopen ("D.out", "w", stdout);
    array<array<int, 2>, 2> a;
    for (int i = 0; i <= 10; i++)
        for (int j = 0; j <= 10; j++)
            for (int k = 0; k <= 10; k++)
                for (int p = 0; p <= 10; p++) {
                    a[0][0] = i; a[0][1] = j;
                    a[1][0] = k; a[1][1] = p;
                    vector<int> qwq;
                    if (a[0][0] && a[0][1]) {
                        auto b = a;
                        b[0][0] -= 1; b[0][1] -= 1;
                        qwq.push_back(sg[b]);
                    }
                    if (a[0][0] && a[1][0]) {
                        auto b = a;
                        b[0][0] -= 1; b[0][1] -= 1;
                        qwq.push_back(sg[b]);
                    }
                    if (a[0][1] && a[1][1]) {
                        auto b = a;
                        b[0][1] -= 1; b[1][1] -= 1;
                        qwq.push_back(sg[b]);
                    }
                    if (a[1][0] && a[1][1]) {
                        auto b = a;
                        b[1][0] -= 1; b[1][1] -= 1;
                        qwq.push_back(sg[b]);
                    }
                    sg[a] = mex(qwq);
                    cout << a[0][0] << " " << a[0][1] << '\n';
                    cout << a[1][0] << " " << a[1][1] << '\n';
                    cout << "=" << sg[a];
                    cout << '\n' << '\n';
                }
}