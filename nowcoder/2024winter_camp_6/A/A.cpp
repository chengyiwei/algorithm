#include <bits/stdc++.h>
using namespace std;
vector<int> p = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int main() {
    vector<int> a;
    for (int i = 0; i < p.size(); i++)
        for (int j = i + 1; j < p.size(); j++)
            for (int k = j + 1; k < p.size(); k ++)
                a.push_back(p[i] * p[j] * p[k]);
    int l,r; cin >> l >> r;
    sort(a.begin(), a.end());
    for (auto x : a) {
        if (x >= l && x <= r) {
            cout << x << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}