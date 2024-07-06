#include <bits/stdc++.h>
using namespace std;
int main() {
    int N; cin >> N;
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        string s; cin >> s;
        if (s == "Takahashi")
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}