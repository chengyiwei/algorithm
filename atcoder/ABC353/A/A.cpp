#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> a(n + 1);
    int pos = -1;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 2; i <= n; i++) 
        if (a[i] > a[1]) {
            pos = i;
            break;
        }
    cout << pos << endl;
    return 0;
}