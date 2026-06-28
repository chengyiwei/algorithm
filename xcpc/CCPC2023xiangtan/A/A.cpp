#include <bits/stdc++.h>
using namespace std;
const int TT = 26;

int qpow (int a, int b) {
    int ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % TT;
        a = a * a % TT;
        b >>= 1;
    }
    return ret;
}

int main() {
    freopen ("A.in","r",stdin);
    int n, m; cin >> n >> m;
    string s; cin >> s;
    int len, cnt = 0;
    while (1) {
        len = s.size();
        if (len - 1 - (len / 2) + 1 >= m)
            break;
        string nxt;
        nxt += s.substr(0,len / 2);
        nxt += s;
        for (int i = len / 2; i < len ; i++)
            nxt.push_back((s[i] - 'a' + 1) % TT + 'a');
        s = nxt; cnt ++;
    }
    string p = s.substr(s.size() - m, m);
    int tot = (qpow(10,100) - cnt + TT) % TT;
    for (auto & x : p) {
        x = (x - 'a' + tot) % TT + 'a';
    }
    cout << p << endl;
    return 0;
}