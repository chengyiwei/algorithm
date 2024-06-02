#include <bits/stdc++.h>
using namespace std;



int main() {
    vector<pair<int, int>> v;
    v.push_back({1, 70}); v.push_back({4,50});
    auto p = lower_bound(v.begin(), v.end(), make_pair(1, 80));
    cout << p->first << " " << p->second << endl;
    return 0;
}