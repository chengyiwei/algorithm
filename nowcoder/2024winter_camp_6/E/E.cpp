#include <bits/stdc++.h>
using namespace std;
int get(string s) {
    int ret = 0;
    if (s.size() > 6) {
        ret = 999999;
        return ret;
    }
    for (auto x : s) {
        ret = ret * 10 + x - '0';
    }
    return ret;
}
int main() {
    string BO; cin >> BO;
    BO = BO.substr(2);
    int n = get(BO);
    string e; cin >> e;
    int R = 0, P = 0;
    for (int i = 0; i < e.size(); i ++) {
        char x = e[i];
        if (x == 'R') 
            R ++;
        if (x == 'P')
            P ++;
        if (R * 2 > n) {
            cout << "kou!" << '\n' << i + 1 << '\n';
            return 0;
        }
        if (P * 2 > n) {
            cout << "yukari!" << '\n' << i + 1 << '\n';
            return 0;
        }
    }
    cout << "to be continued." << '\n' << e.size() << '\n';
    return 0;
}