#include <bits/stdc++.h>
using namespace std;
int main() {
    string S; cin >> S;
    string T; cin >> T;
    for (auto& x : T)
        x = x - 'A' + 'a';
    array<char, 3> t = {T[0], T[1], T[2]};
    if (t[2] == 'x') {
        int pos1 = S.size(), pos2 = -1;
        for (int i = 0; i < S.size(); i++) 
            if (S[i] == t[0]) {
                pos1 = i;
                break;
            }
        for (int i = S.size() - 1; i >= 0; i--)
            if (S[i] == t[1]) {
                pos2 = i;
                break;
            }
        if (pos1 < pos2)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    else {
        int pos1 = S.size(), pos3 = -1;
        for (int i = 0; i < S.size(); i++) 
            if (S[i] == t[0]) {
                pos1 = i;
                break;
            }
        for (int i = S.size() - 1; i >= 0; i--)
            if (S[i] == t[2]) {
                pos3 = i;
                break;
            }
        if (pos1 >= pos3) 
            return cout << "No" << endl, 0;
        int pos2 = -1;
        for (int i = pos1 + 1; i < pos3; i++)
            if (S[i] == t[1]) {
                pos2 = i;
                break;
            }
        if (pos2 == -1)
            return cout << "No" << endl, 0;
        cout << "Yes" << endl;
    }
    return 0;
}