#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    if (s[0] != '<') {printf("No\n"); return 0;}
    if (s.back() != '>') {printf("No\n"); return 0;}
    for (int i = 1; i < s.size() - 1; i++) {
        if (s[i] != '=') {printf("No\n"); return 0;}
    }
    printf("Yes\n");
}