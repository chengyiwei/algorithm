#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n; cin >> n;
    int max_i = 0;
    for (int i = 1; i < n; i ++) {
        cout << "? " << i << " " << i << " " << max_i << " " << max_i << endl;
        char ch; cin >> ch;
        if (ch == '>')
            max_i = i;
    }
    vector<int> p;
    for (int i = 0; i < n; i ++) {
        if (i == max_i) continue;
        if (p.size() == 0) {
            p.push_back(i);
            continue;
        }
        cout << "? " << max_i << " " << p.back() << " " << max_i << " " << i << endl;
        char ch; cin >> ch;
        if (ch == '=') 
            p.push_back(i);
        if (ch == '<') {
            p.clear();
            p.push_back(i);
        }
    }
    int min_i = p.front();
    for (int i = 1; i < p.size(); i ++) {
        cout << "? " << p[i] << " " << p[i] << " " << min_i << " " << min_i << endl;
        char ch; cin >> ch;
        if (ch == '<')
            min_i = p[i];
    }
    cout << "! " << min_i << " " << max_i << endl;
}

int main() {
    int T; cin >> T;
    while(T--) solve();
    return 0;
}