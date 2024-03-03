#include <bits/stdc++.h>
using namespace std;

bool zhishu (int x) {
    if (x == 0 || x == 1) return 0;
    for (int i = 2; i <= sqrt(x) ; i++)
        if (x % i == 0)
            return 0;
    return 1;
}

bool huiwen (int x) {
    string s;
    do { s.push_back (x % 10 + '0' ); x /= 10; } while (x);
    for (int i = 0; i < s.size(); i++)
        if (s[i] != s[s.size() - 1 - i])
            return 0;
    return 1;
}

int main() {
    int T; cin >> T;
    int flg = 0;
    queue<int> q;
    stack<int> st;
    int cnt = 0;
    while (T--) {
        cnt ++;
        string opt; int x; cin >> opt >> x;
        if (opt == "start") {
            if (x & 1) {
                flg = 1;
                while (!q.empty()) q.pop();
            }
            else {
                flg = 2;
                while(!st.empty()) st.pop();
            }
        }
        if (opt == "push") {
            if (flg == 0)  cout << "Error" << '\n';
            if (flg == 1)  q.push(x);
            if (flg == 2)  st.push(x);
        }
        if (opt == "magic") {
            if (flg == 0) { cout << "Error" << '\n'; continue;}
            if (!huiwen(x) && !zhishu(x)) { cout << "FKKK" << '\n'; continue; }
            if (huiwen(x)) {
                if (flg == 1) 
                    if (q.empty()) { cout << "Error" << '\n';}
                    else cout << q.front() << '\n';
                if (flg == 2)
                    if (st.empty()) { cout << "Error" << '\n';}
                    else cout << st.top() <<'\n'; 
            }
            if (zhishu(x)) { 
                if (flg == 1)
                    while (!q.empty()) q.pop();
                if (flg == 2)
                    while (!st.empty()) st.pop();
            }
        }
    }
    return 0;
}