#include <bits/stdc++.h>
using namespace std;

int holes_cnt[26] = {1, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0};

int get(string s) {
    int cnt = 0;
    for (char c : s) {
        cnt += holes_cnt[c - 'A'];
    }
    return cnt;
}

int main() {
    string s; cin >> s;
    int max_ = 0;
    for (int j = 0; j < 26; j++) {
        string t = "";
        for (char c : s) {
            t.push_back((c - 'A' + j) % 26 + 'A');
        }
        max_ = max(max_, get(t));
    }

    cout << max_ << endl;
    return 0;
}