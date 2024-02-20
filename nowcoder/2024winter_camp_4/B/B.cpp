#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> a(n + 1);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if ((a[i] & 1) == 0) cnt++;
    }
    if (cnt & 1)
        cout << "gui" << endl;
    else
        cout << "sweet" << endl;
    return 0;
}