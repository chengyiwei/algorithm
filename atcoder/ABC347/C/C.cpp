#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n; cin >> n;
    ll A, B; cin >> A >> B;
    vector<ll> D(n);
    for (int i = 0; i < n; i++) {
        cin >> D[i];
        D[i] = (D[i] - 1) % (A + B);
    }
    sort(D.begin(), D.end());
    for (int i = 1; i < n; i++)
        if (D[i] - D[i - 1] >= B) {
            cout << "Yes" << '\n';
            return 0;
        }
    if (D.back() - D.front() < A) {
        cout <<  "Yes" << '\n';
        return 0;
    }
    cout << "No" << endl;
    return 0;
}