#include <bits/stdc++.h>
using namespace std;
int main() {
    string s1, s2;
    cin >> s1 >> s2;
    if (s1.size() == 6 || s2.size() == 6)
        return cout << "-1" << endl, 0;
    cout << abs(int(s1.size() - s2.size())) + 1 << endl;
    return 0;
}